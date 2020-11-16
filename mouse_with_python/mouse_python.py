# initial code from https://create.arduino.cc/projecthub/shubhamsantosh99/joystick-controlled-mouse-af2939
#
# Required libs to run this script
#1. cd <paste the path of the python file>
#2. py –m pip install –-upgrade pip
#3. py –m pip install pyautogui
#4. py -m pip install pyserial

import pyautogui, sys
import time 
import serial

pyautogui.FAILSAFE=False
ArduinoSerial=serial.Serial('com5',9600)  #Specify the correct COM port
time.sleep(1)                             #delay of 1 second

while 1:
   data=str(ArduinoSerial.readline().decode('ascii'))   #read the data
   (x,y,z)=data.split(":")           # assigns to x,y and z
   (X,Y)=pyautogui.position()        #read the cursor's current position
   x=int(x)                           #convert to int
   y=int(y)
   pyautogui.moveTo(X+x,Y-y)           #move cursor to desired position
   if '1' in z:                        # read the Status of SW
      pyautogui.click(button="left")    # clicks left button
     