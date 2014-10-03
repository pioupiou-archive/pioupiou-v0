/*
 * power.c
 *
 *  Created on: 2 juin 2014
 *      Author: nicolas
 */
#include "power.h"

bool lowBatMode = false;

void PP_POWER_ChargeInit () {
	GPIO_PinModeSet(SOLAR_SWITCH_PORT, SOLAR_SWITCH_PIN, gpioModePushPull, 0);
}

void PP_POWER_SolarSenseInit () {
	GPIO_PinModeSet(SOLAR_SENSE_PORT, SOLAR_SENSE_PIN, gpioModeDisabled, 0);
}

void PP_POWER_BatterySenseInit () {
	GPIO_PinModeSet(BATTERY_SENSE_PORT, BATTERY_SENSE_PIN, gpioModeInput, 0);
}

void PP_POWER_BeepInit() {
	GPIO_PinModeSet(BEEP_PORT, BEEP_PIN, gpioModePushPull, 1);
}

void PP_POWER_Beep(beepModeTypedef beepMode) {

	int i,j,k;

	switch (beepMode) {

		case BEEP_STARTUP:
			for (i=0; i<1118; i++) {
				GPIO_PinOutToggle(BEEP_PORT, BEEP_PIN);
				for(j=0; j<313; j++) {}
			}
			for (i=0; i<1400; i++) {
					GPIO_PinOutToggle(BEEP_PORT, BEEP_PIN);
					int j;
					for(j=0; j<250; j++) {}
			}
			for (i=0; i<1659; i++) {
				GPIO_PinOutToggle(BEEP_PORT, BEEP_PIN);
				int j;
				for(j=0; j<211; j++) {}
			}
			break;

		case BEEP_SHUTDOWN:
			for (i=0; i<1659; i++) {
				GPIO_PinOutToggle(BEEP_PORT, BEEP_PIN);
				int j;
				for(j=0; j<211; j++) {}
			}
			for (i=0; i<1400; i++) {
					GPIO_PinOutToggle(BEEP_PORT, BEEP_PIN);
					int j;
					for(j=0; j<250; j++) {}
			}
			for (i=0; i<1118; i++) {
				GPIO_PinOutToggle(BEEP_PORT, BEEP_PIN);
				for(j=0; j<313; j++) {}
			}
			break;

		case BEEP_LOWBAT:
			for (k=0; k<5; k++) {
				for (i=0; i<800; i++) {
					GPIO_PinOutToggle(BEEP_PORT, BEEP_PIN);
					for(j=0; j<211; j++) {}
				}
				for (i=0; i<1E4; i++) {}
			}
			break;

	}

	GPIO_PinOutSet(BEEP_PORT, BEEP_PIN);
}

void PP_POWER_DiagMessage(uint8_t messageType) {
	uint8_t sigfoxFrame[2] = {messageType, TD_MEASURE_VoltageTemperature(false)};
	TD_SIGFOX_Send(sigfoxFrame, 2,2);
}

void PP_POWER_ChargeDisable () {
	GPIO_PinOutClear(SOLAR_SWITCH_PORT, SOLAR_SWITCH_PIN);
}
void PP_POWER_ChargeEnable () {
	GPIO_PinOutSet(SOLAR_SWITCH_PORT, SOLAR_SWITCH_PIN);
}
bool PP_POWER_IsCharging () {
	return GPIO_PinOutGet(SOLAR_SWITCH_PORT, SOLAR_SWITCH_PIN);
}

bool batteryIsCharged;

void VCMP_IRQHandler() {
	if (VCMP->IF & VCMP_IF_EDGE) {
	    batteryIsCharged = true;
	    VCMP_IntClear(VCMP_IFC_EDGE);
	  }
}

void PP_POWER_SleepUntilCharged () {
	PP_POWER_Beep(BEEP_LOWBAT);

	PP_POWER_DiagMessage(DIAG_MSG_POWERSLEEP);

	// wake quand batterie chargée

	VCMP_Init_TypeDef init = VCMP_INIT_DEFAULT;

	init.halfBias     = 1;
	init.biasProg     = 7;
	init.irqFalling   = 0;
	init.irqRising    = 1;
	init.warmup       = vcmpWarmTime4Cycles;
	init.hyst         = vcmpHyst20mV;
	init.lowPowerRef  = 1;
	init.triggerLevel = VCMP_VoltageToLevel((float)BATTERY_WAKECHARGED_LIMIT/500.);

	CMU_ClockEnable(cmuClock_VCMP, true);

	VCMP_Init(&init);

	NVIC_EnableIRQ(VCMP_IRQn);
	VCMP_IntEnable(VCMP_IEN_EDGE);

	VCMP_Enable();
	while (!VCMP_Ready()) ;

	PP_POWER_ChargeEnable();

	batteryIsCharged = false;

	while (batteryIsCharged == false) {
		EMU_EnterEM3(true);
	}

	PP_POWER_ChargeDisable();

	VCMP_Disable();
	CMU_ClockEnable(cmuClock_VCMP, false);

	PP_POWER_DiagMessage(DIAG_MSG_POWERWAKE);

}

void PP_POWER_LowBatModeSet () {
	lowBatMode = true;
}
void PP_POWER_LowBatModeClear () {
	lowBatMode = false;
}
bool PP_POWER_LowBatModeGet () {
	return lowBatMode;
}

void PP_POWER_CheckBattery () {

	int32_t voltage; // millivolts

	voltage = TD_MEASURE_VoltageTemperatureExtended(false);

	if (voltage >= BATTERY_CHARGE_LIMIT*2) {
		PP_POWER_ChargeDisable();
	} else if (voltage <= BATTERY_HARD_LIMIT*2) {
		PP_POWER_SleepUntilCharged();
		PP_POWER_Beep(BEEP_STARTUP);
	} else {
		PP_POWER_ChargeEnable();
		if (voltage  <= BATTERY_SOFT_LIMIT*2) {
			PP_POWER_LowBatModeSet();
		} else {
			PP_POWER_LowBatModeClear();
		}
	}

	//TODO : prendre en compte la mesure intermediaire

}

void PP_POWER_Shutdown () {
	// peut-être reveillé uniquement par un reset

	// TODO: envoyer un message ?

	PP_POWER_ChargeDisable();

	RMU_ResetCauseClear();

	EMU_EnterEM4();
	//TODO: voir si EM4 conserve l'état des pins.
	// sinon faire un while (1) { EMU_EnterEM3(false) };

}


bool PP_POWER_IsUnderSunlight () {

	bool wasCharging = PP_POWER_IsCharging();
	PP_POWER_ChargeDisable();

	CMU_ClockEnable(cmuClock_ACMP1, true);

	ACMP_Init_TypeDef init = ACMP_INIT_DEFAULT;
	init.fullBias                 = 0;
	init.halfBias                 = 1;
	init.biasProg                 = 12;
	init.warmTime                 = acmpWarmTime512;
	init.hysteresisLevel          = acmpHysteresisLevel5;
	init.lowPowerReferenceEnabled = 0;
	init.vddLevel                 = 18; //  0,3x VDD
	init.interruptOnFallingEdge   = 0;
	init.interruptOnRisingEdge    = 0;
	init.inactiveValue            = 0;

	ACMP_Init(ACMP1, &init);
	ACMP_ChannelSet(ACMP1, acmpChannelVDD, acmpChannel7);

	// pull-down
	GPIO_PinModeSet(SOLAR_SENSE_PORT, SOLAR_SENSE_PIN, gpioModeInputPull, 0);

	/* Wait for warmup */
	while (!(ACMP1->STATUS & ACMP_STATUS_ACMPACT)) ;

	bool isUnderSunlight = (int) ((ACMP1->STATUS & ACMP_STATUS_ACMPOUT) >> _ACMP_STATUS_ACMPOUT_SHIFT);

	// pull-up
	GPIO_PinModeSet(SOLAR_SENSE_PORT, SOLAR_SENSE_PIN, gpioModeDisabled, 0);

	ACMP_Reset(ACMP1);
	CMU_ClockEnable(cmuClock_ACMP1, false);

	if (wasCharging) PP_POWER_ChargeEnable();

	return isUnderSunlight;
}

void PP_POWER_Scheduler(uint32_t arg, uint8_t repetition) {
	TD_WATCHDOG_Feed();
	PP_POWER_CheckBattery();
}

void PP_POWER_Init () {

	uint32_t resetCause = RMU_ResetCauseGet();
	RMU_ResetCauseClear();

	PP_POWER_BatterySenseInit();
	PP_POWER_SolarSenseInit();
	PP_POWER_ChargeInit();
	PP_POWER_BeepInit();

	TD_WATCHDOG_Init(32);

	PP_POWER_CheckBattery();
	TD_WATCHDOG_Enable(true, false);

	//TODO/BUG on a RMU_RSTCAUSE_BODUNREGRST quand on sort de EM4
	if ((resetCause & RMU_RSTCAUSE_EXTRST) == RMU_RSTCAUSE_EXTRST) {
		if (!PP_POWER_IsUnderSunlight()) {
			PP_POWER_Beep(BEEP_SHUTDOWN);
			PP_POWER_DiagMessage(DIAG_MSG_POWEROFF);
			PP_POWER_Shutdown();
		}
	}

	PP_POWER_Beep(BEEP_STARTUP);

	TD_RTC_Delay(T5S);
	PP_POWER_DiagMessage(DIAG_MSG_POWERON);

	TD_SCHEDULER_Append(BATTERY_CHECK_PERIOD, 0, 0, TD_SCHEDULER_INFINITE, PP_POWER_Scheduler, 0);

}
