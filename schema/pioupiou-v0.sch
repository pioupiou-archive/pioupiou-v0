EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:td1208
LIBS:bmp180
LIBS:hmc5883l
LIBS:spv1040
LIBS:antenna
LIBS:ina216
LIBS:si1869dh
LIBS:pcb-cache
EELAYER 24 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Pioupiou"
Date "16 may 2014"
Rev "0.2"
Comp "Nicolas BALDECK / BAC Plus Zéro SASU"
Comment1 "Open Hardware"
Comment2 "Licence : https://open.pioupiou.fr/Licence"
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 3750 1400 0    60   ~ 0
Alkalines\nRechargeables
$Comp
L GND #PWR01
U 1 1 532EAEE8
P 3700 7200
F 0 "#PWR01" H 3700 7200 30  0001 C CNN
F 1 "GND" H 3700 7130 30  0001 C CNN
F 2 "" H 3700 7200 60  0001 C CNN
F 3 "" H 3700 7200 60  0001 C CNN
	1    3700 7200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 532EAEA9
P 3700 7500
F 0 "#PWR02" H 3700 7500 30  0001 C CNN
F 1 "GND" H 3700 7430 30  0001 C CNN
F 2 "" H 3700 7500 60  0001 C CNN
F 3 "" H 3700 7500 60  0001 C CNN
	1    3700 7500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 532EAEA5
P 2000 7500
F 0 "#PWR03" H 2000 7500 30  0001 C CNN
F 1 "GND" H 2000 7430 30  0001 C CNN
F 2 "" H 2000 7500 60  0001 C CNN
F 3 "" H 2000 7500 60  0001 C CNN
	1    2000 7500
	1    0    0    -1  
$EndComp
Text Notes 750  5100 0    60   ~ 0
Cerveau + Modem
$Comp
L GND #PWR04
U 1 1 532DC76C
P 4500 2200
F 0 "#PWR04" H 4500 2200 30  0001 C CNN
F 1 "GND" H 4500 2130 30  0001 C CNN
F 2 "" H 4500 2200 60  0001 C CNN
F 3 "" H 4500 2200 60  0001 C CNN
	1    4500 2200
	1    0    0    -1  
$EndComp
$Comp
L BATTERY BT2
U 1 1 532DC760
P 4500 1850
F 0 "BT2" H 4500 2050 50  0000 C CNN
F 1 "AAA" H 4500 1660 50  0000 C CNN
F 2 "" H 4500 1850 60  0001 C CNN
F 3 "" H 4500 1850 60  0001 C CNN
	1    4500 1850
	0    1    1    0   
$EndComp
$Comp
L BATTERY BT1
U 1 1 532DC74D
P 4500 1200
F 0 "BT1" H 4500 1400 50  0000 C CNN
F 1 "AAA" H 4500 1010 50  0000 C CNN
F 2 "" H 4500 1200 60  0001 C CNN
F 3 "" H 4500 1200 60  0001 C CNN
	1    4500 1200
	0    1    1    0   
$EndComp
Text Label 4800 900  0    60   ~ 0
VBAT
$Comp
L CONN_2 P1
U 1 1 532DAEB7
P 900 1000
F 0 "P1" V 850 1000 40  0000 C CNN
F 1 "SOLAR" V 950 1000 40  0000 C CNN
F 2 "" H 900 1000 60  0001 C CNN
F 3 "" H 900 1000 60  0001 C CNN
	1    900  1000
	-1   0    0    -1  
$EndComp
Text Notes 5850 2700 0    60   ~ 0
Boussole (option)
NoConn ~ 6800 4350
$Comp
L GND #PWR05
U 1 1 532DA721
P 6900 4750
F 0 "#PWR05" H 6900 4750 30  0001 C CNN
F 1 "GND" H 6900 4680 30  0001 C CNN
F 2 "" H 6900 4750 60  0001 C CNN
F 3 "" H 6900 4750 60  0001 C CNN
	1    6900 4750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 532DA6F5
P 7400 4600
F 0 "#PWR06" H 7400 4600 30  0001 C CNN
F 1 "GND" H 7400 4530 30  0001 C CNN
F 2 "" H 7400 4600 60  0001 C CNN
F 3 "" H 7400 4600 60  0001 C CNN
	1    7400 4600
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 532DA6CB
P 7400 4350
F 0 "C11" H 7450 4450 50  0000 L CNN
F 1 "4.7uF" H 7450 4250 50  0000 L CNN
F 2 "" H 7400 4350 60  0001 C CNN
F 3 "" H 7400 4350 60  0001 C CNN
	1    7400 4350
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 532DA64D
P 7200 3850
F 0 "C9" H 7250 3950 50  0000 L CNN
F 1 "220nF" H 7250 3750 50  0000 L CNN
F 2 "" H 7200 3850 60  0001 C CNN
F 3 "" H 7200 3850 60  0001 C CNN
	1    7200 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 532DA5F4
P 7400 3600
F 0 "#PWR07" H 7400 3600 30  0001 C CNN
F 1 "GND" H 7400 3530 30  0001 C CNN
F 2 "" H 7400 3600 60  0001 C CNN
F 3 "" H 7400 3600 60  0001 C CNN
	1    7400 3600
	1    0    0    -1  
$EndComp
Text Label 7700 3150 0    60   ~ 0
VBAT
Text Label 6800 3650 0    60   ~ 0
SDA
Text Label 6800 3550 0    60   ~ 0
SCL
$Comp
L C C7
U 1 1 532DA592
P 7400 3350
F 0 "C7" H 7450 3450 50  0000 L CNN
F 1 "100nF" H 7450 3250 50  0000 L CNN
F 2 "" H 7400 3350 60  0001 C CNN
F 3 "" H 7400 3350 60  0001 C CNN
	1    7400 3350
	1    0    0    -1  
$EndComp
$Comp
L HMC5883L IC2
U 1 1 532DA54B
P 5950 2950
F 0 "IC2" H 6250 1050 60  0000 C CNN
F 1 "HMC5883L" H 6250 2950 60  0000 C CNN
F 2 "" H 5950 2950 60  0001 C CNN
F 3 "" H 5950 2950 60  0001 C CNN
	1    5950 2950
	1    0    0    -1  
$EndComp
Text Notes 5200 5350 0    60   ~ 0
Reset / Bouton Power 
Text Label 5400 5650 2    60   ~ 0
RST
$Comp
L GND #PWR08
U 1 1 532C2CA7
P 6300 5700
F 0 "#PWR08" H 6300 5700 30  0001 C CNN
F 1 "GND" H 6300 5630 30  0001 C CNN
F 2 "" H 6300 5700 60  0001 C CNN
F 3 "" H 6300 5700 60  0001 C CNN
	1    6300 5700
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 532C2C7B
P 5850 5650
F 0 "SW2" H 6000 5760 50  0000 C CNN
F 1 "SW_PUSH" H 5850 5570 50  0000 C CNN
F 2 "" H 5850 5650 60  0001 C CNN
F 3 "" H 5850 5650 60  0001 C CNN
	1    5850 5650
	1    0    0    -1  
$EndComp
Text Notes 6750 5350 0    60   ~ 0
Debug
Text Label 7350 6100 0    60   ~ 0
TX
Text Label 7350 5900 0    60   ~ 0
RST
Text Label 7350 5700 0    60   ~ 0
SWDIO
Text Label 7350 5800 0    60   ~ 0
SWDCLK
Text Label 7350 6000 0    60   ~ 0
GND
Text Label 7350 5600 0    60   ~ 0
VBAT
Text Notes 8350 2700 0    60   ~ 0
Pression / Température (option)
$Comp
L GND #PWR09
U 1 1 532C1C27
P 9750 3700
F 0 "#PWR09" H 9750 3700 30  0001 C CNN
F 1 "GND" H 9750 3630 30  0001 C CNN
F 2 "" H 9750 3700 60  0001 C CNN
F 3 "" H 9750 3700 60  0001 C CNN
	1    9750 3700
	1    0    0    -1  
$EndComp
Text Label 10600 3150 0    60   ~ 0
VBAT
$Comp
L C C8
U 1 1 532C1BB2
P 10100 3350
F 0 "C8" H 10150 3450 50  0000 L CNN
F 1 "100nF" H 10150 3250 50  0000 L CNN
F 2 "" H 10100 3350 60  0001 C CNN
F 3 "" H 10100 3350 60  0001 C CNN
	1    10100 3350
	1    0    0    -1  
$EndComp
Text Label 1050 6650 2    60   ~ 0
VBAT
Text Label 1050 5800 2    60   ~ 0
VBAT
$Comp
L R R14
U 1 1 532C1A50
P 1450 6050
F 0 "R14" V 1530 6050 50  0000 C CNN
F 1 "10k" V 1450 6050 50  0000 C CNN
F 2 "" H 1450 6050 60  0001 C CNN
F 3 "" H 1450 6050 60  0001 C CNN
	1    1450 6050
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 532C1A49
P 1250 6050
F 0 "R13" V 1330 6050 50  0000 C CNN
F 1 "10k" V 1250 6050 50  0000 C CNN
F 2 "" H 1250 6050 60  0001 C CNN
F 3 "" H 1250 6050 60  0001 C CNN
	1    1250 6050
	1    0    0    -1  
$EndComp
Text Label 8650 3350 2    60   ~ 0
SCL
Text Label 8650 3150 2    60   ~ 0
SDA
$Comp
L BMP180 IC3
U 1 1 532C18EF
P 9150 3550
F 0 "IC3" H 9150 3550 60  0000 C CNN
F 1 "BMP180" H 9150 4150 60  0000 C CNN
F 2 "" H 9150 3550 60  0001 C CNN
F 3 "" H 9150 3550 60  0001 C CNN
	1    9150 3550
	1    0    0    -1  
$EndComp
Text Notes 2550 2600 0    60   ~ 0
Girouette
Text Label 4600 3400 1    60   ~ 0
LED_DIR4
Text Label 4050 3400 1    60   ~ 0
LED_DIR3
Text Label 3500 3400 1    60   ~ 0
LED_DIR2
Text Label 2950 3400 1    60   ~ 0
LED_DIR1
Text Label 5050 3750 1    60   ~ 0
OPTO_SIGNAL
$Comp
L OPTO_NPN Q1
U 1 1 532C1018
P 5150 4200
F 0 "Q1" H 5300 4250 50  0000 L CNN
F 1 "OPTO_NPN" V 5450 4050 50  0000 L CNN
F 2 "" H 5150 4200 60  0001 C CNN
F 3 "" H 5150 4200 60  0001 C CNN
	1    5150 4200
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 532C0E80
P 2950 4200
F 0 "D2" H 2950 4300 50  0000 C CNN
F 1 "LED" H 2950 4100 50  0000 C CNN
F 2 "" H 2950 4200 60  0001 C CNN
F 3 "" H 2950 4200 60  0001 C CNN
	1    2950 4200
	0    -1   1    0   
$EndComp
Text Notes 750  2650 0    60   ~ 0
Anémomètre
$Comp
L GND #PWR010
U 1 1 532C0D02
P 1100 4650
F 0 "#PWR010" H 1100 4650 30  0001 C CNN
F 1 "GND" H 1100 4580 30  0001 C CNN
F 2 "" H 1100 4650 60  0001 C CNN
F 3 "" H 1100 4650 60  0001 C CNN
	1    1100 4650
	1    0    0    -1  
$EndComp
Text Label 1600 3450 0    60   ~ 0
REED_SIGNAL
Text Label 1600 2850 0    60   ~ 0
VBAT
$Comp
L R R7
U 1 1 532C0CB1
P 1100 3100
F 0 "R7" V 1180 3100 50  0000 C CNN
F 1 "1M" V 1100 3100 50  0000 C CNN
F 2 "" H 1100 3100 60  0001 C CNN
F 3 "" H 1100 3100 60  0001 C CNN
	1    1100 3100
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 532C0C66
P 1450 4050
F 0 "C10" H 1500 4150 50  0000 L CNN
F 1 "C" H 1500 3950 50  0000 L CNN
F 2 "" H 1450 4050 60  0001 C CNN
F 3 "" H 1450 4050 60  0001 C CNN
	1    1450 4050
	1    0    0    -1  
$EndComp
$Comp
L SPST SW1
U 1 1 532C0C5C
P 1100 4050
F 0 "SW1" H 1100 3800 70  0000 C CNN
F 1 "CT10-1540-G4" H 1100 3900 70  0000 C CNN
F 2 "" H 1100 4050 60  0001 C CNN
F 3 "" H 1100 4050 60  0001 C CNN
	1    1100 4050
	0    1    1    0   
$EndComp
Text Label 1050 6550 2    60   ~ 0
SCL
Text Label 1050 6450 2    60   ~ 0
SDA
Text Label 2100 6350 2    60   ~ 0
SWDIO
Text Label 2100 6250 2    60   ~ 0
SWDCLK
Text Label 3600 6650 0    60   ~ 0
RST
Text Label 4450 6350 0    60   ~ 0
TX
$Comp
L GND #PWR011
U 1 1 532C096A
P 1250 7150
F 0 "#PWR011" H 1250 7150 30  0001 C CNN
F 1 "GND" H 1250 7080 30  0001 C CNN
F 2 "" H 1250 7150 60  0001 C CNN
F 3 "" H 1250 7150 60  0001 C CNN
	1    1250 7150
	1    0    0    -1  
$EndComp
$Comp
L C C14
U 1 1 532C095D
P 1250 6850
F 0 "C14" H 1300 6950 50  0000 L CNN
F 1 "10uF 6V3" H 1300 6750 50  0000 L CNN
F 2 "" H 1250 6850 60  0001 C CNN
F 3 "" H 1250 6850 60  0001 C CNN
	1    1250 6850
	1    0    0    -1  
$EndComp
$Comp
L TD1208 IC4
U 1 1 532C0932
P 2600 6150
F 0 "IC4" H 2550 6600 60  0000 C CNN
F 1 "TD1208" H 2650 6700 60  0000 C CNN
F 2 "" H 2600 6150 60  0001 C CNN
F 3 "" H 2600 6150 60  0001 C CNN
	1    2600 6150
	1    0    0    -1  
$EndComp
$Comp
L CONN_1 P2
U 1 1 5339947A
P 7050 5600
F 0 "P2" H 7130 5600 40  0000 L CNN
F 1 "CONN_1" H 7050 5655 30  0001 C CNN
F 2 "" H 7050 5600 60  0000 C CNN
F 3 "" H 7050 5600 60  0000 C CNN
	1    7050 5600
	-1   0    0    1   
$EndComp
$Comp
L CONN_1 P3
U 1 1 53399489
P 7050 5700
F 0 "P3" H 7130 5700 40  0000 L CNN
F 1 "CONN_1" H 7050 5755 30  0001 C CNN
F 2 "" H 7050 5700 60  0000 C CNN
F 3 "" H 7050 5700 60  0000 C CNN
	1    7050 5700
	-1   0    0    1   
$EndComp
$Comp
L CONN_1 P4
U 1 1 53399498
P 7050 5800
F 0 "P4" H 7130 5800 40  0000 L CNN
F 1 "CONN_1" H 7050 5855 30  0001 C CNN
F 2 "" H 7050 5800 60  0000 C CNN
F 3 "" H 7050 5800 60  0000 C CNN
	1    7050 5800
	-1   0    0    1   
$EndComp
$Comp
L CONN_1 P5
U 1 1 533994A7
P 7050 5900
F 0 "P5" H 7130 5900 40  0000 L CNN
F 1 "CONN_1" H 7050 5955 30  0001 C CNN
F 2 "" H 7050 5900 60  0000 C CNN
F 3 "" H 7050 5900 60  0000 C CNN
	1    7050 5900
	-1   0    0    1   
$EndComp
$Comp
L CONN_1 P6
U 1 1 533994B6
P 7050 6000
F 0 "P6" H 7130 6000 40  0000 L CNN
F 1 "CONN_1" H 7050 6055 30  0001 C CNN
F 2 "" H 7050 6000 60  0000 C CNN
F 3 "" H 7050 6000 60  0000 C CNN
	1    7050 6000
	-1   0    0    1   
$EndComp
$Comp
L CONN_1 P7
U 1 1 533994C5
P 7050 6100
F 0 "P7" H 7130 6100 40  0000 L CNN
F 1 "CONN_1" H 7050 6155 30  0001 C CNN
F 2 "" H 7050 6100 60  0000 C CNN
F 3 "" H 7050 6100 60  0000 C CNN
	1    7050 6100
	-1   0    0    1   
$EndComp
$Comp
L R R8
U 1 1 5366AFAC
P 2950 3750
F 0 "R8" V 3030 3750 40  0000 C CNN
F 1 "Rdir" V 2957 3751 40  0000 C CNN
F 2 "~" V 2880 3750 30  0000 C CNN
F 3 "~" H 2950 3750 30  0000 C CNN
	1    2950 3750
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 5366B366
P 3500 4200
F 0 "D3" H 3500 4300 50  0000 C CNN
F 1 "LED" H 3500 4100 50  0000 C CNN
F 2 "" H 3500 4200 60  0001 C CNN
F 3 "" H 3500 4200 60  0001 C CNN
	1    3500 4200
	0    -1   1    0   
$EndComp
$Comp
L R R9
U 1 1 5366B372
P 3500 3750
F 0 "R9" V 3580 3750 40  0000 C CNN
F 1 "Rdir" V 3507 3751 40  0000 C CNN
F 2 "~" V 3430 3750 30  0000 C CNN
F 3 "~" H 3500 3750 30  0000 C CNN
	1    3500 3750
	1    0    0    -1  
$EndComp
$Comp
L LED D4
U 1 1 5366B380
P 4050 4200
F 0 "D4" H 4050 4300 50  0000 C CNN
F 1 "LED" H 4050 4100 50  0000 C CNN
F 2 "" H 4050 4200 60  0001 C CNN
F 3 "" H 4050 4200 60  0001 C CNN
	1    4050 4200
	0    -1   1    0   
$EndComp
$Comp
L R R10
U 1 1 5366B38C
P 4050 3750
F 0 "R10" V 4130 3750 40  0000 C CNN
F 1 "Rdir" V 4057 3751 40  0000 C CNN
F 2 "~" V 3980 3750 30  0000 C CNN
F 3 "~" H 4050 3750 30  0000 C CNN
	1    4050 3750
	1    0    0    -1  
$EndComp
$Comp
L LED D5
U 1 1 5366B399
P 4600 4200
F 0 "D5" H 4600 4300 50  0000 C CNN
F 1 "LED" H 4600 4100 50  0000 C CNN
F 2 "" H 4600 4200 60  0001 C CNN
F 3 "" H 4600 4200 60  0001 C CNN
	1    4600 4200
	0    -1   1    0   
$EndComp
$Comp
L R R11
U 1 1 5366B3A5
P 4600 3750
F 0 "R11" V 4680 3750 40  0000 C CNN
F 1 "Rdir" V 4607 3751 40  0000 C CNN
F 2 "~" V 4530 3750 30  0000 C CNN
F 3 "~" H 4600 3750 30  0000 C CNN
	1    4600 3750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 5366B578
P 2950 4600
F 0 "#PWR012" H 2950 4600 30  0001 C CNN
F 1 "GND" H 2950 4530 30  0001 C CNN
F 2 "" H 2950 4600 60  0000 C CNN
F 3 "" H 2950 4600 60  0000 C CNN
	1    2950 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 5366B587
P 3500 4600
F 0 "#PWR013" H 3500 4600 30  0001 C CNN
F 1 "GND" H 3500 4530 30  0001 C CNN
F 2 "" H 3500 4600 60  0000 C CNN
F 3 "" H 3500 4600 60  0000 C CNN
	1    3500 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 5366B596
P 4050 4600
F 0 "#PWR014" H 4050 4600 30  0001 C CNN
F 1 "GND" H 4050 4530 30  0001 C CNN
F 2 "" H 4050 4600 60  0000 C CNN
F 3 "" H 4050 4600 60  0000 C CNN
	1    4050 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 5366B5A5
P 4600 4600
F 0 "#PWR015" H 4600 4600 30  0001 C CNN
F 1 "GND" H 4600 4530 30  0001 C CNN
F 2 "" H 4600 4600 60  0000 C CNN
F 3 "" H 4600 4600 60  0000 C CNN
	1    4600 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 5366B5B4
P 5250 4600
F 0 "#PWR016" H 5250 4600 30  0001 C CNN
F 1 "GND" H 5250 4530 30  0001 C CNN
F 2 "" H 5250 4600 60  0000 C CNN
F 3 "" H 5250 4600 60  0000 C CNN
	1    5250 4600
	1    0    0    -1  
$EndComp
Text Notes 850  1400 0    60   ~ 0
4V\n35mA
$Comp
L DIODESCH D1
U 1 1 5366DA6B
P 3900 900
F 0 "D1" H 3900 1000 40  0000 C CNN
F 1 "BAT54CLT1G" H 3900 800 40  0000 C CNN
F 2 "~" H 3900 900 60  0000 C CNN
F 3 "~" H 3900 900 60  0000 C CNN
	1    3900 900 
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5368A999
P 6350 1650
F 0 "R4" V 6430 1650 40  0000 C CNN
F 1 "0R" V 6357 1651 40  0000 C CNN
F 2 "~" V 6280 1650 30  0000 C CNN
F 3 "~" H 6350 1650 30  0000 C CNN
	1    6350 1650
	0    -1   -1   0   
$EndComp
$Comp
L NPN Q3
U 1 1 5368A9A8
P 6850 1650
F 0 "Q3" H 6850 1500 50  0000 R CNN
F 1 "0R" H 6850 1800 50  0000 R CNN
F 2 "~" H 6850 1650 60  0000 C CNN
F 3 "~" H 6850 1650 60  0000 C CNN
	1    6850 1650
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5368A9B7
P 7400 1450
F 0 "R3" V 7480 1450 40  0000 C CNN
F 1 "1K" V 7407 1451 40  0000 C CNN
F 2 "~" V 7330 1450 30  0000 C CNN
F 3 "~" H 7400 1450 30  0000 C CNN
	1    7400 1450
	0    -1   -1   0   
$EndComp
$Comp
L SPEAKER SP1
U 1 1 5368A9C6
P 8050 1550
F 0 "SP1" H 7950 1800 70  0000 C CNN
F 1 "PS1240P02CT3" H 7900 1150 70  0000 C CNN
F 2 "~" H 8050 1550 60  0000 C CNN
F 3 "~" H 8050 1550 60  0000 C CNN
	1    8050 1550
	1    0    0    -1  
$EndComp
Text Label 7700 1150 0    60   ~ 0
VBAT
$Comp
L GND #PWR017
U 1 1 5368AD90
P 6950 1950
F 0 "#PWR017" H 6950 1950 30  0001 C CNN
F 1 "GND" H 6950 1880 30  0001 C CNN
F 2 "" H 6950 1950 60  0000 C CNN
F 3 "" H 6950 1950 60  0000 C CNN
	1    6950 1950
	1    0    0    -1  
$EndComp
Text Notes 700  650  0    60   ~ 0
Alimentation
Text Notes 5650 900  0    60   ~ 0
Buzzer
Text Notes 1600 1650 0    60   ~ 0
pull down uc 40k
Text Label 1600 1500 0    60   ~ 0
SOLAR_SENSE
$Comp
L R R1
U 1 1 536D06FD
P 1500 1250
F 0 "R1" V 1580 1250 40  0000 C CNN
F 1 "40k" V 1507 1251 40  0000 C CNN
F 2 "~" V 1430 1250 30  0000 C CNN
F 3 "~" H 1500 1250 30  0000 C CNN
	1    1500 1250
	1    0    0    -1  
$EndComp
Text Label 6100 1650 2    60   ~ 0
BUZZ
Text Label 3600 6350 0    60   ~ 0
SOLAR_SENSE
Text Label 3600 6550 0    60   ~ 0
BUZZ
Text Label 2100 6750 2    60   ~ 0
REED_SIGNAL
Text Label 3600 6450 0    60   ~ 0
LED_DIR1
Text Label 3600 6150 0    60   ~ 0
LED_DIR2
Text Label 3600 6050 0    60   ~ 0
LED_DIR3
Text Label 3600 6750 0    60   ~ 0
OPTO_SIGNAL
Text Label 3600 5950 0    60   ~ 0
LED_DIR4
$Comp
L GND #PWR018
U 1 1 53709C31
P 1250 1250
F 0 "#PWR018" H 1250 1250 30  0001 C CNN
F 1 "GND" H 1250 1180 30  0001 C CNN
F 2 "" H 1250 1250 60  0000 C CNN
F 3 "" H 1250 1250 60  0000 C CNN
	1    1250 1250
	1    0    0    -1  
$EndComp
Text Label 4750 1550 0    60   ~ 0
BAT_SENSE
Text Label 4450 6250 0    60   ~ 0
SOLAR_SW
Text Label 2100 6150 2    60   ~ 0
BAT_SENSE
$Comp
L ANTENNA ANT1
U 1 1 5370A7A7
P 3750 5500
F 0 "ANT1" H 3950 5600 60  0000 C CNN
F 1 "ANTENNA" H 3900 5700 60  0001 C CNN
F 2 "" H 3750 5500 60  0000 C CNN
F 3 "" H 3750 5500 60  0000 C CNN
	1    3750 5500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 5370A8F1
P 3900 5650
F 0 "#PWR019" H 3900 5650 30  0001 C CNN
F 1 "GND" H 3900 5580 30  0001 C CNN
F 2 "" H 3900 5650 60  0000 C CNN
F 3 "" H 3900 5650 60  0000 C CNN
	1    3900 5650
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 53726778
P 5250 3550
F 0 "R6" V 5330 3550 40  0000 C CNN
F 1 "vide" V 5257 3551 40  0000 C CNN
F 2 "~" V 5180 3550 30  0000 C CNN
F 3 "~" H 5250 3550 30  0000 C CNN
	1    5250 3550
	1    0    0    -1  
$EndComp
Text Label 5250 3300 1    60   ~ 0
VBAT
$Comp
L SI1869DH IC1
U 1 1 53739498
P 3050 1000
F 0 "IC1" H 3160 850 60  0000 C CNN
F 1 "SI1869DH" H 3550 1200 60  0000 C CNN
F 2 "~" H 3000 1005 60  0000 C CNN
F 3 "~" H 3000 1005 60  0000 C CNN
	1    3050 1000
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 53739C2B
P 2300 1000
F 0 "R2" V 2200 1000 40  0000 C CNN
F 1 "1M" V 2307 1001 40  0000 C CNN
F 2 "~" V 2230 1000 30  0000 C CNN
F 3 "~" H 2300 1000 30  0000 C CNN
	1    2300 1000
	0    -1   -1   0   
$EndComp
$Comp
L R R5
U 1 1 53739D78
P 3000 1800
F 0 "R5" V 3080 1800 40  0000 C CNN
F 1 "0R" V 3007 1801 40  0000 C CNN
F 2 "~" V 2930 1800 30  0000 C CNN
F 3 "~" H 3000 1800 30  0000 C CNN
	1    3000 1800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 5373A046
P 3000 2150
F 0 "#PWR020" H 3000 2150 30  0001 C CNN
F 1 "GND" H 3000 2080 30  0001 C CNN
F 2 "" H 3000 2150 60  0000 C CNN
F 3 "" H 3000 2150 60  0000 C CNN
	1    3000 2150
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5373A05F
P 3400 1250
F 0 "C1" H 3400 1350 40  0000 L CNN
F 1 "vide" H 3406 1165 40  0000 L CNN
F 2 "~" H 3438 1100 30  0000 C CNN
F 3 "~" H 3400 1250 60  0000 C CNN
	1    3400 1250
	1    0    0    -1  
$EndComp
Connection ~ 10100 3150
Wire Wire Line
	1050 6650 2100 6650
Wire Notes Line
	750  7700 5050 7700
Wire Notes Line
	750  5200 750  7700
Wire Wire Line
	3700 7500 3700 7400
Wire Wire Line
	3700 7400 3600 7400
Connection ~ 3600 7150
Connection ~ 2100 7300
Connection ~ 2100 7400
Connection ~ 3600 7400
Wire Wire Line
	3600 7400 3600 7300
Wire Wire Line
	2100 7200 2100 7400
Connection ~ 6800 4650
Wire Wire Line
	6900 4750 6900 4650
Wire Wire Line
	6900 4650 6800 4650
Wire Wire Line
	7400 4550 7400 4600
Wire Wire Line
	6800 3950 7000 3950
Wire Wire Line
	7000 3950 7000 4050
Wire Wire Line
	7000 4050 7200 4050
Connection ~ 6800 3250
Connection ~ 6800 3150
Connection ~ 7400 3150
Wire Wire Line
	7400 3550 7400 3600
Wire Notes Line
	5200 5850 5200 5400
Wire Notes Line
	5200 5850 6450 5850
Wire Notes Line
	6450 5850 6450 5400
Wire Notes Line
	6450 5400 5200 5400
Wire Wire Line
	6300 5700 6300 5650
Wire Wire Line
	6300 5650 6150 5650
Wire Notes Line
	6850 5400 6750 5400
Wire Notes Line
	6750 5400 6750 6250
Wire Notes Line
	6750 6250 7850 6250
Wire Notes Line
	7850 6250 7850 5400
Wire Notes Line
	7850 5400 6800 5400
Connection ~ 9750 3150
Connection ~ 9750 3550
Wire Wire Line
	9750 3350 9750 3700
Wire Wire Line
	9750 3150 10600 3150
Connection ~ 1250 6650
Connection ~ 1100 4550
Connection ~ 1250 5800
Wire Wire Line
	1050 5800 1450 5800
Connection ~ 1250 6450
Wire Wire Line
	1250 6300 1250 6450
Wire Wire Line
	1050 6550 2100 6550
Wire Notes Line
	750  2700 2350 2700
Wire Notes Line
	750  2700 750  4750
Wire Wire Line
	1600 2850 1100 2850
Wire Wire Line
	1450 4550 1100 4550
Connection ~ 1100 3450
Wire Wire Line
	1250 7050 1250 7150
Wire Wire Line
	1100 3350 1100 3550
Wire Wire Line
	1450 3850 1450 3450
Connection ~ 1450 3450
Wire Wire Line
	1450 4550 1450 4250
Wire Wire Line
	1100 4550 1100 4650
Wire Wire Line
	1100 3450 1600 3450
Wire Notes Line
	2550 2650 5700 2650
Wire Wire Line
	1050 6450 2100 6450
Wire Wire Line
	1450 6300 1450 6550
Connection ~ 1450 6550
Wire Wire Line
	9750 3150 9750 3250
Wire Wire Line
	10100 3550 9750 3550
Wire Notes Line
	10950 2750 8350 2750
Wire Notes Line
	10950 2750 10950 3850
Wire Notes Line
	10950 3850 8350 3850
Wire Notes Line
	8350 3850 8350 2750
Wire Wire Line
	5550 5650 5400 5650
Wire Wire Line
	6800 3150 6800 3350
Wire Wire Line
	6800 3150 7700 3150
Wire Wire Line
	7200 3650 7000 3650
Wire Wire Line
	7000 3650 7000 3850
Wire Wire Line
	7000 3850 6800 3850
Wire Wire Line
	6800 4150 7400 4150
Wire Wire Line
	6800 4650 6800 4550
Wire Notes Line
	8050 2750 5850 2750
Wire Notes Line
	8050 2750 8050 4950
Wire Notes Line
	8050 4950 5850 4950
Wire Notes Line
	5850 4950 5850 2750
Wire Notes Line
	2350 2700 2350 4850
Wire Notes Line
	2350 4850 750  4850
Wire Notes Line
	750  4850 750  4700
Wire Wire Line
	4500 2150 4500 2200
Wire Wire Line
	3600 7050 3600 7150
Wire Wire Line
	3700 7200 3700 7150
Wire Wire Line
	3700 7150 3600 7150
Wire Wire Line
	2100 7400 2000 7400
Wire Wire Line
	2000 7400 2000 7500
Wire Wire Line
	7200 5600 7350 5600
Wire Wire Line
	7350 5700 7200 5700
Wire Wire Line
	7200 5800 7350 5800
Wire Wire Line
	7350 5900 7200 5900
Wire Wire Line
	7200 6000 7350 6000
Wire Wire Line
	7350 6100 7200 6100
Wire Notes Line
	2550 2650 2550 4900
Wire Notes Line
	2550 4900 5700 4900
Wire Notes Line
	5700 4900 5700 2650
Wire Wire Line
	3500 4400 3500 4600
Wire Wire Line
	4050 4400 4050 4600
Wire Wire Line
	4600 4400 4600 4600
Wire Wire Line
	4500 1550 4500 1500
Wire Wire Line
	6950 1450 7150 1450
Wire Wire Line
	7650 1450 7750 1450
Wire Wire Line
	7700 1450 7700 1150
Connection ~ 7700 1450
Wire Wire Line
	7750 1650 7100 1650
Wire Wire Line
	7100 1650 7100 1450
Connection ~ 7100 1450
Wire Wire Line
	6950 1850 6950 1950
Wire Notes Line
	5650 2100 8550 2100
Wire Notes Line
	8550 2100 8550 950 
Wire Notes Line
	8550 950  5650 950 
Wire Notes Line
	5650 950  5650 2100
Wire Wire Line
	6600 1650 6650 1650
Connection ~ 1500 900 
Wire Wire Line
	4600 3500 4600 3400
Wire Wire Line
	4050 3500 4050 3400
Wire Wire Line
	3500 3500 3500 3400
Wire Wire Line
	2950 3500 2950 3400
Wire Wire Line
	5250 4400 5250 4600
Wire Wire Line
	2950 4400 2950 4600
Wire Wire Line
	1500 900  1500 1000
Wire Wire Line
	1500 1500 1600 1500
Wire Wire Line
	1250 1100 1250 1250
Wire Wire Line
	4500 1550 4750 1550
Wire Notes Line
	700  700  5300 700 
Wire Notes Line
	5300 700  5300 2350
Wire Notes Line
	5300 2350 700  2350
Wire Notes Line
	700  2350 700  700 
Wire Wire Line
	4100 900  4800 900 
Wire Wire Line
	3600 5700 3750 5700
Wire Wire Line
	3900 5550 3900 5650
Connection ~ 4350 6250
Wire Wire Line
	3600 6250 4450 6250
Wire Wire Line
	4450 6350 4350 6350
Wire Wire Line
	4350 6350 4350 6250
Connection ~ 4500 900 
Wire Wire Line
	5250 3800 5250 4000
Wire Wire Line
	5250 3900 5050 3900
Wire Wire Line
	5050 3900 5050 3750
Connection ~ 5250 3900
Wire Wire Line
	3350 1000 3400 1000
Wire Wire Line
	3400 900  3400 1050
Connection ~ 3400 900 
Wire Wire Line
	2550 1000 2750 1000
Wire Wire Line
	2050 1000 2000 1000
Wire Wire Line
	2000 1000 2000 900 
Connection ~ 2000 900 
Wire Wire Line
	3000 1300 3000 1550
Wire Wire Line
	3000 2050 3000 2150
Connection ~ 3400 1000
Wire Wire Line
	2600 1450 3400 1450
Wire Wire Line
	2600 1000 2600 1450
Connection ~ 2600 1000
Wire Wire Line
	3700 900  3350 900 
Wire Wire Line
	2750 900  1250 900 
Text Label 2400 1300 2    60   ~ 0
SOLAR_SW
Wire Wire Line
	2750 1100 2500 1100
Wire Wire Line
	2500 1100 2500 1300
Wire Wire Line
	2500 1300 2400 1300
Wire Notes Line
	750  5200 5050 5200
Wire Notes Line
	5050 5200 5050 7700
$EndSCHEMATC
