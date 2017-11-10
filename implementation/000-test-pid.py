#!/usr/bin/env python


#initial setup code
import os,sys,inspect,time,thread, random
from mindsensors_i2c import mindsensors_i2c
from PiStorms import PiStorms
from mindsensors import ABSIMU

currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0,parentdir)

#starts an instance of PiStorms

imu=ABSIMU()
psm = PiStorms()
#exit variable will be used later to exit the program and return to PiStormsMaster
doExit = False

psm.screen.termPrintln("AbsIMU test")
psm.screen.termPrintln("connect mindsensors.com's ")
psm.screen.termPrintln("AbsImu to BAS1 sensor Port")
psm.led(1, 0,0,0)
psm.led(2, 0,0,0)

psm.BAS1.activateCustomSensorI2C() #Connect the I2C sensor on the port BBS1
time.sleep(.1)

# tilt data conversion
def convertTilt(tilt):
    if (tilt > 0):
        return tilt - 127
    return tilt + 128


# PID stuff, CONSTANTS HAVE TO BE ADJUSTED
kp = 0.2
ki = 0
kd = 0
errorSum = 0
lastError = convertTilt(imu.get_tiltx())
lastTime = time.time()


# print options
printLastTime = lastTime
printSkipIterations = 10
printCounter = 0

psm.BAM1.setSpeed(0)
psm.BAM2.setSpeed(0)


while(not doExit):
    #
    try:
        #heading = imu.get_heading()
        #accl = imu.get_accelall()
        #mag = imu.get_magall()
        #gyro = imu.get_gyroall()
        
        # WE COULD USE TILT OR ACCELERATION
        # - TILT IS NOT VERY PRECISE
        # - ACCELERATION IS AFFECTED BY MOVEMENT
        # error = convertTilt(imu.get_tiltx()) 
        error = imu.get_accelx()
        
        now = time.time() 
        dt = now - lastTime
        dError = (error - lastError) * dt
        errorSum += error
        lastTime = now
        lastError = error
        
        # PID CONTROL
        control = (kp * error)  +  (ki * errorSum)  +  (kd * dError)
        # prevent over / underflows
        if control > 127:
            control = 127
        if control < -128:
            control = -128
        psm.BAM1.setSpeed(control)
        psm.BAM2.setSpeed(control)
        
        
        # output
        printCounter += 1
        if printCounter >= printSkipIterations:
            printCounter = 0
            #psm.screen.termPrintAt(6,"control:    " + str(control) )
            #psm.screen.termPrintAt(7,"err:    " + str(error) )
            
            timePassed = now - printLastTime
            printLastTime = now
            timePerIteration = timePassed / (printSkipIterations+1)
            hz = int(1 / timePerIteration)
            #psm.screen.termPrintAt(8, str( hz ) + " Hz update rate" )
    except:
        psm.led(2,0, 0,0)
        psm.screen.termPrintAt(6,"connect AbsImu on BAS1 ")


    # END LOOP
    if(psm.isKeyPressed() == True): # if the GO button is pressed
        psm.BAM1.float()
        psm.BAM2.float()
        psm.screen.clearScreen()
        psm.screen.termPrintln("")
        psm.screen.termPrintln("Exiting to menu")
        time.sleep(0.5)
        psm.led(1, 0,0,0)
        psm.led(2, 0,0,0)
        doExit = True
