/*
 * pioupiou_anemo.c
 *
 *  Created on: 15 avr. 2014
 *      Author: nicolas
 */

#include "anemo.h"

uint32_t _sample_rtc;
uint32_t _sample_pulses;

void PP_ANEMO_Sample() {

	uint32_t now = RTC_CounterGet();
	uint32_t dt;

	float dir = GIROUETTE_STEP_RADIANS * PP_GIROUETTE_Read();

	float freq;
	float speed;

	if (_sample_rtc > now) {
		// overflow
		dt = now + (RTC_OVERFLOW - _sample_rtc);
	} else {
		dt = now - _sample_rtc;
	}

	_sample_pulses++;

	PP_REPORTS_CurrentSub.total_pulse_count += _sample_pulses;
	PP_REPORTS_CurrentSub.total_rtc_count += dt;

	if (dt == 0) {
		freq = 0;
	} else {
		freq = (float)_sample_pulses / ((float)dt / (float)RTC_FREQUENCY);
	}
	speed = freq * ANEMO_HZ_TO_KMH;

	if (speed > PP_REPORTS_CurrentSub.max_speed) {
		PP_REPORTS_CurrentSub.max_speed = speed;
	}

	if (speed < PP_REPORTS_CurrentSub.min_speed) {
		PP_REPORTS_CurrentSub.min_speed = speed;
	}


	PP_REPORTS_CurrentSub.dirX += speed * cos(dir);
	PP_REPORTS_CurrentSub.dirY += speed * sin(dir);


	//tfp_printf("pulses %d\tfreq %d\tspeed %d\tmax %d\tmin %d\tnext %d\r\n", anemo_sample_pulses, (int)(float)(freq*100), (int)(float)(speed*100), (int)(float)(anemo_max_speed*100), (int)(float)(anemo_min_speed*100), (int)(float)(freq * ANEMO_SAMPLE_TIME + 0.5));

	//tfp_printf("%d\t%d\t%d\r\n", _sample_pulses, dt, (int)(float)(speed*100));


	_sample_pulses = (int)(float)(freq * ANEMO_SAMPLE_TIME + 0.5);
	if (_sample_pulses < ANEMO_MIN_PULSES) {
		_sample_pulses = ANEMO_MIN_PULSES;
	} else if (_sample_pulses > ANEMO_MAX_PULSES) {
		_sample_pulses = ANEMO_MAX_PULSES;
	}
	PCNT_TopSet(PCNT0, _sample_pulses);
	_sample_rtc = now;

	//tfp_printf("temps %d\r\n", RTC_CounterGet()-now);
	//tfp_printf("%d\t%d\t%d\r\n", PP_REPORTS_CurrentSub.total_rtc_count, PP_REPORTS_CurrentSub.total_pulse_count, (int)(float)(speed*100));

}

void PCNT0_IRQHandler(void) {
	PP_ANEMO_Sample();
	PCNT_IntClear(PCNT0, PCNT_IF_OF);
}

void PP_ANEMO_Init(void) {

	CMU_ClockEnable(cmuClock_PCNT0, true);

	GPIO_PinModeSet(REED_SIGNAL_PORT, REED_SIGNAL_BIT, gpioModeInput, 1);
	PCNT0->ROUTE = (PCNT0->ROUTE & ~_PCNT_ROUTE_LOCATION_MASK) | PCNT_ROUTE_LOCATION_LOC2;

	PCNT_Init_TypeDef pcntInit = {
			.mode		= pcntModeOvsSingle,
			.counter	= 0,
			.top		= ANEMO_START_PULSES,
			.negEdge	= true,
			.countDown	= false,
			.filter		= true
	};
	PCNT_Init(PCNT0, &pcntInit);
	PCNT_IntEnable(PCNT0, PCNT_IF_OF);
	NVIC_EnableIRQ(PCNT0_IRQn);


	PCNT_CounterTopSet(PCNT0, 0, ANEMO_START_PULSES);
	_sample_rtc = RTC_CounterGet();
	_sample_pulses = ANEMO_START_PULSES;

	PP_REPORTS_NewSub();
}
