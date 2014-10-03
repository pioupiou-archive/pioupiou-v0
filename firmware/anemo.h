/*
 * anemo.h
 *
 *  Created on: 18 avr. 2014
 *      Author: nicolas
 */

#ifndef PIOUPIOU_ANEMO_H_
#define PIOUPIOU_ANEMO_H_

#include <math.h>

#include <em_pcnt.h>
#include <em_cmu.h>
#include <em_gpio.h>
#include <em_rtc.h>
#include <td_core.h>
#include <td_module.h>
#include <td_uart.h>
#include <td_printf.h>

#include "reglages.h"
#include "reports.h"
#include "girouette.h"

#define REED_SIGNAL_PORT	gpioPortC
#define REED_SIGNAL_BIT		0

void PP_ANEMO_Init(void);

#endif /* PIOUPIOU_ANEMO_H_ */
