/*
 * power.h
 *
 *  Created on: 2 juin 2014
 *      Author: nicolas
 */

#ifndef PIOUPIOU_POWER_H_
#define PIOUPIOU_POWER_H_

#include <em_emu.h>
#include <em_cmu.h>
#include <em_rmu.h>
#include <em_gpio.h>
#include <em_acmp.h>
#include <em_vcmp.h>

#include <td_measure.h>
#include <td_rtc.h>
#include <td_scheduler.h>
#include <td_watchdog.h>
#include <td_sigfox.h>

#define BATTERY_HARD_LIMIT 1250 // millivolts
#define BATTERY_SOFT_LIMIT 1400
#define BATTERY_CHARGE_LIMIT 1600
#define BATTERY_WAKECHARGED_LIMIT 1400

#define BATTERY_CHECK_PERIOD 10 // secondes

#define BATTERY_SENSE_PORT gpioPortC
#define BATTERY_SENSE_PIN 14

#define SOLAR_SENSE_PORT gpioPortC
#define SOLAR_SENSE_PIN	15

#define SOLAR_SWITCH_PORT gpioPortD
#define SOLAR_SWITCH_PIN 4

#define DIAG_MSG_POWERON 0x01
#define DIAG_MSG_POWEROFF 0x02
#define DIAG_MSG_POWERSLEEP 0x03
#define DIAG_MSG_POWERWAKE 0x04

//#define SOLAR_SWITCH_PORT gpioPortC
//#define SOLAR_SWITCH_PIN 14

#define BEEP_PORT gpioPortB
#define BEEP_PIN 11

typedef enum {
	BEEP_STARTUP,
	BEEP_LOWBAT,
	BEEP_SHUTDOWN
} beepModeTypedef;


void PP_POWER_Init(void);

#endif /* PIOUPIOU_POWER_H_ */
