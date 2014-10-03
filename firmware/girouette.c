/*
 * girouette.c
 *
 *  Created on: 3 juin 2014
 *      Author: nicolas
 */
#include "girouette.h"

const GPIO_Port_TypeDef ledPorts[4] = {
		GIROUETTE_LED_PORT_A,
		GIROUETTE_LED_PORT_B,
		GIROUETTE_LED_PORT_C,
		GIROUETTE_LED_PORT_D
};

const int ledPins[4] = {
		GIROUETTE_LED_PIN_A,
		GIROUETTE_LED_PIN_B,
		GIROUETTE_LED_PIN_C,
		GIROUETTE_LED_PIN_D
};

const int dirTable[16] = {11, 14, 12, 13, 10, 15, 9, 0, 6, 3, 5, 4, 7, 2, 8, 1};


void PP_GIROUETTE_OptoInit () {

	GPIO_PinModeSet(GIROUETTE_SENSE_PORT, GIROUETTE_SENSE_PORT, gpioModeDisabled, 0);

	ACMP_Init_TypeDef init = ACMP_INIT_DEFAULT;

	init.fullBias                 = 0;
	init.halfBias                 = 1;
	init.biasProg                 = 12;
	init.warmTime                 = acmpWarmTime512;
	init.hysteresisLevel          = acmpHysteresisLevel5;
	init.lowPowerReferenceEnabled = 0;
	init.vddLevel                 = 55; // TODO
	init.interruptOnFallingEdge   = 0;
	init.interruptOnRisingEdge    = 0;
	init.inactiveValue            = 0;

	CMU_ClockEnable(cmuClock_ACMP0, true);

	ACMP_Init(ACMP0, &init);
	ACMP_ChannelSet(ACMP0, acmpChannelVDD, acmpChannel1);

	ACMP_Disable(ACMP0);

	CMU_ClockEnable(cmuClock_ACMP0, false);


}


void PP_GIROUETTE_Init() {

	int i;
	for (i=0; i<4; i++) {
		GPIO_PinModeSet(ledPorts[i], ledPins[i], gpioModePushPullDrive, 0);
		GPIO_DriveModeSet(ledPorts[i], gpioDriveModeHigh);
	}

	PP_GIROUETTE_OptoInit();
}

void PP_GIROUETTE_OptoEnable () {

	CMU_ClockEnable(cmuClock_ACMP0, true);

	//pull-up pour activer l'opto
	GPIO_PinModeSet(GIROUETTE_SENSE_PORT, GIROUETTE_SENSE_PIN, gpioModeInputPull, 1);

	ACMP_Enable(ACMP0);

	/* Wait for warmup */
	while (!(ACMP0->STATUS & ACMP_STATUS_ACMPACT)) ;
}

void PP_GIROUETTE_OptoDisable () {

	ACMP_Disable(ACMP0);

	GPIO_PinModeSet(GIROUETTE_SENSE_PORT, GIROUETTE_SENSE_PORT, gpioModeDisabled, 0);
	CMU_ClockEnable(cmuClock_ACMP0, false);

}

int PP_GIROUETTE_Read () {

	PP_GIROUETTE_OptoEnable();

	int i,j;
	int dirRaw = 0;
	for (i=0; i<4; i++) {
		int val;
		GPIO_PinOutSet(ledPorts[i], ledPins[i]);
		for (j=0; j<1500; j++) {} // latence de la led TODO: régler la valeur
		val = (int) ((ACMP0->STATUS & ACMP_STATUS_ACMPOUT) >> _ACMP_STATUS_ACMPOUT_SHIFT);
		GPIO_PinOutClear(ledPorts[i], ledPins[i]);
		dirRaw += val << i;
	}

	PP_GIROUETTE_OptoDisable();

	return dirTable[dirRaw];

}

void PP_GIROUETTE_Test () {

	TD_WATCHDOG_Enable(false, false);



	while (1) {
		PP_GIROUETTE_OptoEnable();

		int dirRaw = 0;
		int val[4];
		int i, j;
		int dir;
			for (i=0; i<4; i++) {

				GPIO_PinOutSet(ledPorts[i], ledPins[i]);
				for (j=0; j<1500; j++) {}
				val[i] = (int) ((ACMP0->STATUS & ACMP_STATUS_ACMPOUT) >> _ACMP_STATUS_ACMPOUT_SHIFT);
				GPIO_PinOutClear(ledPorts[i], ledPins[i]);
				dirRaw += val[i] << i;
			}
		dir = dirTable[dirRaw];

		tfp_printf("%d %d %d %d %d\n", val[0], val[1], val[2], val[3], dir);

		PP_GIROUETTE_OptoDisable();
		TD_RTC_Delay(T100MS);
	}


}
