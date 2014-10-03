/*
 * reports.h
 *
 *  Created on: 20 avr. 2014
 *      Author: nicolas
 */

#ifndef PIOUPIOU_REPORTS_H_
#define PIOUPIOU_REPORTS_H_

#include <math.h>

#include <td_core.h>
#include <td_scheduler.h>
#include <td_sigfox.h>
#include <td_rtc.h>
#include <td_measure.h>
#include <td_watchdog.h>
#include <td_uart.h>
#include <td_printf.h>

#include "reglages.h"
#include "girouette.h"
#include "pression.h"

typedef struct PP_REPORTS_SubData_t {
	float max_speed;
	float min_speed;
	float moy_speed;
	uint32_t total_pulse_count;
	uint32_t total_rtc_count;
	float dirX;
	float dirY;
	int32_t temp;
	int32_t pression;
} PP_REPORTS_SubData_t;

PP_REPORTS_SubData_t PP_REPORTS_CurrentSub;

void PP_REPORTS_NewSub(void);
void PP_REPORTS_Init(void);


#endif /* REPORTS_H_ */
