/*
 * reports.c
 *
 *  Created on: 20 avr. 2014
 *      Author: nicolas
 */

#include "reports.h"

uint8_t _iCurrentSub;
PP_REPORTS_SubData_t _subData[N_SUBREPORT];

void PP_REPORTS_NewSub (void) {
	PP_REPORTS_SubData_t newSub = {
			.max_speed = -999,
			.min_speed = 999,
			.total_pulse_count = 0,
			.total_rtc_count = 0,
			.dirX = 0,
			.dirY = 0,
			.temp = 0,
			.pression = 0
		};
	PP_REPORTS_CurrentSub = newSub;
}

void PP_REPORTS_Transmit(void) {
	uint8_t sigfoxFrame[12];

	uint8_t dir[N_SUBREPORT];
	uint8_t vmax[N_SUBREPORT];
	uint8_t vmin[N_SUBREPORT];
	uint8_t vmoy[N_SUBREPORT];

	int32_t pression = 0;

	int i;
	for (i=0; i<N_SUBREPORT; i++) {

		if (_subData[i].min_speed > 127.) {
			vmin[i]=0x7F;
		} else {
			vmin[i] = (int)(float)(_subData[i].min_speed + 0.5);
		}

		if (_subData[i].moy_speed > 127.) {
			vmoy[i]=0x7F;
		} else {
			vmoy[i] = (int)(float)(_subData[i].moy_speed + 0.5);
		}

		if (_subData[i].max_speed > 127.) {
			vmax[i]=0x7F;
		} else {
			vmax[i] = (int)(float)(_subData[i].max_speed + 0.5);
		}

		dir[i] = (int)(float)((atan2(_subData[i].dirY, _subData[i].dirX) / GIROUETTE_STEP_RADIANS) + 16.5) % 16;
		//tfp_printf("dirX %d dirY %d moy %d\r\n", (int)_subData[i].dirX, (int)_subData[i].dirY, moy_dir[i]);
		pression += _subData[i].pression;
	}

	// press : 512 - 1100   16384   4000 11000 -- 2^13
	// temp −50 - 50;

	pression /= N_SUBREPORT;
	pression = (pression + 5) / 10 - 4000;

	sigfoxFrame[0] = (vmin[0] << 1) + (vmoy[0] >> 6);
	sigfoxFrame[1] = (vmoy[0] << 2) + (vmax[0] >> 5);
	sigfoxFrame[2] = (vmax[0] << 3) + (vmin[1] >> 4);
	sigfoxFrame[3] = (vmin[1] << 4) + (vmoy[1] >> 3);
	sigfoxFrame[4] = (vmoy[1] << 5) + (vmax[1] >> 2);
	sigfoxFrame[5] = (vmax[1] << 6) + (vmin[2] >> 1);
	sigfoxFrame[6] = (vmin[2] << 7) + vmoy[2];
	sigfoxFrame[7] = (vmax[2] << 1) + (pression >> 12);
	sigfoxFrame[8] = (dir[0] << 4) + dir[1];
	sigfoxFrame[9] = (dir[2] << 4) + ((pression >> 8) & 0xF);
	sigfoxFrame[10] = pression & 0xFF;
	sigfoxFrame[11] = TD_MEASURE_VoltageTemperature(false);

	// 1/10s of mV plus 2 V if MSB is 0, or plus 3 V if MSB is 1.


	//tfp_printf("dir %d %d %d\r\n", moy_dir[0], moy_dir[1], moy_dir[2]);
	//tfp_printf("temp %d press  %d  volt %d\r\n", moy_temp, moy_pression, voltage);


	/*tfp_printf("sigfox %d %d %d %d %d %d %d %d %d %d %d %d\r\n",
			sigfoxFrame[0],
			sigfoxFrame[1],
			sigfoxFrame[2],
			sigfoxFrame[3],
			sigfoxFrame[4],
			sigfoxFrame[5],
			sigfoxFrame[6],
			sigfoxFrame[7],
			sigfoxFrame[8],
			sigfoxFrame[9],
			sigfoxFrame[10],
			sigfoxFrame[11]);*/

	if (TD_SIGFOX_Send(sigfoxFrame,12,2)) {
		//tfp_printf("sigfox sent");
	} else {
		//tfp_printf("sigfox error");
	}
}

void PP_REPORTS_ScheduledSubReport(uint32_t arg, uint8_t repetition) {
	//tfp_printf("sub %d\r\n", _iCurrentSub);

	_subData[_iCurrentSub] = PP_REPORTS_CurrentSub;
	PP_REPORTS_NewSub();

	if (_subData[_iCurrentSub].max_speed < -998)
		_subData[_iCurrentSub].max_speed = 0;

	if (_subData[_iCurrentSub].min_speed > 998)
		_subData[_iCurrentSub].min_speed = 0;

	//tfp_printf("pulses %d\trtc %d\r\n", _subData[_iCurrentSub].total_pulse_count, _subData[_iCurrentSub].total_rtc_count);

	if (_subData[_iCurrentSub].total_rtc_count == 0) {
		_subData[_iCurrentSub].moy_speed = 0;
	} else {
		_subData[_iCurrentSub].moy_speed = (float)_subData[_iCurrentSub].total_pulse_count
			/ ((float)_subData[_iCurrentSub].total_rtc_count
			/ (float)RTC_FREQUENCY) * ANEMO_HZ_TO_KMH;
	}

	PP_PRESSION_Read (&_subData[_iCurrentSub].temp, &_subData[_iCurrentSub].pression);

	if (_iCurrentSub == N_SUBREPORT-1) {
		//tfp_printf("report %d\t%d\t%d\t%d\t%d\t%d\r\n", (int)(_subData[0].max_speed*100), (int)(_subData[1].max_speed*100), (int)(_subData[2].max_speed*100), (int)(_subData[3].max_speed*100));
		//tfp_printf("report %d\t%d\t%d\t%d\t%d\t%d\r\n", (int)(_subData[0].min_speed*100), (int)(_subData[1].min_speed*100), (int)(_subData[2].min_speed*100), (int)(_subData[3].min_speed*100));
		//tfp_printf("report %d\t%d\t%d\t%d\t%d\t%d\r\n", (int)(_subData[0].moy_speed*100), (int)(_subData[1].moy_speed*100), (int)(_subData[2].moy_speed*100), (int)(_subData[3].moy_speed*100));
		PP_REPORTS_Transmit();
		_iCurrentSub=0;
	} else {
		_iCurrentSub++;
	}

	//TD_WATCHDOG_Feed();
}

void PP_REPORTS_Init(void) {
	TD_SCHEDULER_Append(SUBREPORT_PERIOD, 0, 0, TD_SCHEDULER_INFINITE, PP_REPORTS_ScheduledSubReport, 0);
}


