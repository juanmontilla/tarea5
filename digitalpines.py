#DIGITALWRITE
import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)      #escoge cual configuracion va usar para el manejo de pines (CENTRO)
#el otro es: GPIO.setmode(GPIO.BCM) (EXTERNOS)
RED=11 #Numero del pin a utilizar
GPIO.setup(red, GPIO.OUT) 	#declarar el pin como pin de salida
GPIO.output(red, True)		#escribir un 1 en el pin de salida
time.sleep(1)
GPIO.output(red, False)		#escribir un 0 en el pin de salida...tambien se puede GPIP.output(red, GPIO.LOW)
time.sleep(1)
GPIO.output(red, True)
time.sleep(1)
GPIO.output(red, False)
GPIO.cleanup()

#correr un archivo de python en frambuesa
#sudo python nombre.py

#DIGITALREAD

#import RPi.GPIO as GPIO
#from time import sleep
#GPIO.setmode(GPIO.BOARD)
#button1=16
#button2=12 
#GPIO.setup(button1, GPIO.IN,pull_up_down=GPIO.PUD_UP) #declarar el pin como pin de entrada
#GPIO.setup(button2, GPIO.IN,pull_up_down=GPIO.PUD_UP)
#while(1):
#	if GPIO.input(button1)==0:
#	print "Button 1 Pressed"
#	sleep(.1)
#	if GPIO.input(button2)==0:
#	print "Button 2 Pressed"
#	sleep(.1)
#GPIO.cleanup()

