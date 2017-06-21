#-*- coding: utf-8 -*-
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

MATRIX = [
    ["A","B","C","D"],
    ["E","F","G","H"],
    ["I","J","K","L"],
    ["M","N","O","P"]
    ]

ROW = [7, 11, 13, 15]
COL = [12, 16, 18, 22]

for j in range(4):
	GPIO.setup(COL[j], GPIO.OUT)
	GPIO.output(COL[j], 1)

for i in range(4):
	GPIO.setup(ROW[i], GPIO.IN, pull_up_down = GPIO.PUD_UP)

try:
	while(True):
		for j in range(4):
			GPIO.output(COL[j],0)

			for i in range(4):
				if GPIO.input(ROW[i]) == 0:
					print MATRIX[i][j]
					while(GPIO.input(ROW[i]) == 0):
						pass

			GPIO.output(COL[j], 1)
except KeyboardInterrupt:
	GPIO.cleanup()




