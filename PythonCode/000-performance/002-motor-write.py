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

psm = PiStorms()




#
# MOTOR
#
def writeMotor(numWrites, firstLine):
    psm.screen.termPrintAt(firstLine, str(numWrites) + " writing motor values:")
    psm.screen.termPrintAt(firstLine+1, "... wait for it")
    start = time.time() 
    for i in range(1,numWrites):
        psm.BAM1.setSpeed(i * 1.0 / numWrites * 100)
    end = time.time()
    psm.BAM1.setSpeed(0)
    psm.screen.termPrintAt(firstLine+1, str(int((end-start) * 1000)) + " ms" )



psm.screen.termPrintAt(0,"TEST MOTOR")
writeMotor(numWrites=1000, firstLine=1)
writeMotor(numWrites=10000, firstLine=3)
writeMotor(numWrites=20000, firstLine=5)


#
# END LOOP
#


doExit = False
while(not doExit):
    if(psm.isKeyPressed() == True):
        doExit = True
