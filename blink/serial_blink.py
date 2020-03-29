        
# File.arduino.py
# For Raspbery Pi
# Run with 'sudo python arduino.py'

import serial
import RPi.GPIO as GPIO
import time

ser=serial.Serial("/dev/ttyACM0",9600)  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=9600

def blink(rate, pin):
  GPIO.output(pin,GPIO.HIGH)
  time.sleep(rate)  
  GPIO.output(pin,GPIO.LOW)  
  time.sleep(rate)  
  return

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(11, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(13, GPIO.OUT, initial=GPIO.LOW)

print "Warming up"
count = 0
while count < 30:
  count = count + 1
  blink(0.05, 11)

count = 0
while True:
  count = count + 1
  print "wait (" + str(count) + ")"
  read_ser=ser.readline()
  print read_ser.replace("\r\n", "")
  if(read_ser == "Hello From Arduino!\r\n"):
    blink(1, 13)
  else: 
   print "No blink"

count = 0
while count < 10:
  count = count + 1
  blink(0.2, 11)
