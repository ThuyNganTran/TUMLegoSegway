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
#psm.BAS1.activateCustomSensorI2C() # do we need this?

#
# TILT
#
def readTilt(numReads, firstLine):
    psm.screen.termPrintAt(firstLine, str(numReads) + " readings of tilt take:")
    psm.screen.termPrintAt(firstLine+1, "... wait for it")
    start = time.time() 
    for i in range(1,numReads):
        xy = imu.get_tiltx()
    end = time.time()
    psm.screen.termPrintAt(firstLine+1, str(int((end-start) * 1000)) + " ms" )




psm.screen.termPrintAt(0,"TEST SPEED")
readTilt(numReads=1000, firstLine=1)
readTilt(numReads=10000, firstLine=3)
readTilt(numReads=20000, firstLine=5)



    


#
# END LOOP
#


doExit = False
while(not doExit):
    if(psm.isKeyPressed() == True):
        doExit = True
    
