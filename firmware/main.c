#include <em_cmu.h>
#include <em_leuart.h>

#include <td_core.h>
#include <td_uart.h>
#include <td_printf.h>
#include <td_watchdog.h>

#include "power.h"
#include "anemo.h"
#include "girouette.h"
#include "pression.h"
#include "reports.h"


/* This file declare all "dynamic" library data. It should be last included file
 * Standard size value can be override before including this file
 */
#define CHIP_TD1208
#define TD_SENSOR_USE_CODE 0
#define TD_GEOLOC_USE_CODE 0
#define PRODUCT_BOOTLOADER_SKIP 1
#include <td_config.h>

void SERIAL_DEBUG_Putc(void * p, char c) {
	LEUART_Tx(LEUART0, c);
}
void SERIAL_DEBUG_Void(void * p) {}
void* SERIAL_DEBUG_VoidVoid() {}


void SERIAL_DEBUG_Init() {

	CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
	CMU_ClockSelectSet(cmuClock_LFB, cmuSelect_LFXO);
	CMU_ClockEnable(cmuClock_CORELE, true);
	CMU_ClockEnable( cmuClock_LEUART0, true );

	LEUART_Init_TypeDef leuart0Init =
	{
	  .enable   = leuartEnableTx,       /* Activate data reception on LEUn_TX pin. */
	  .refFreq  = 0,                    /* Inherit the clock frequenzy from the LEUART clock source */
	  .baudrate = 9600,                 /* Baudrate = 9600 bps */
	  .databits = leuartDatabits8,      /* Each LEUART frame containes 8 databits */
	  .parity   = leuartNoParity,       /* No parity bits in use */
	  .stopbits = leuartStopbits2,      /* Setting the number of stop bits in a frame to 2 bitperiods */
	};

	//LEUART_Reset(LEUART0);
	LEUART_Init(LEUART0, &leuart0Init);

	LEUART0->ROUTE = LEUART_ROUTE_TXPEN | LEUART_ROUTE_LOCATION_LOC0;

	GPIO_PinModeSet(gpioPortD,                /* GPIO port */
				  4,                        /* GPIO port number */
				  gpioModePushPull,         /* Pin mode is set to push pull */
				  1);

	init_printf(SERIAL_DEBUG_VoidVoid(), SERIAL_DEBUG_Putc, SERIAL_DEBUG_Void,SERIAL_DEBUG_Void);
}


void TD_USER_Setup(void)
{


	PP_POWER_Init();
	PP_REPORTS_Init();
	PP_GIROUETTE_Init();
	PP_PRESSION_Init();
	PP_ANEMO_Init();

	//SERIAL_DEBUG_Init();


	//tfp_printf("Start test\r\n");

	//PP_GIROUETTE_Test ();

	//PP_PRESSION_Init();
	//PP_PRESSION_Read();

	//while (true) {
	//	tfp_printf("%d\n", PP_GIROUETTE_Read());
	//	TD_RTC_Delay(T200MS);
	//}






	/*while (true) {
		GPIO_PinOutToggle(DAC0_PORT, DAC0_BIT);
		int i;
		for(i=0; i<1000; i++) {}
	}*/


	/*PP_REPORTS_Init();

	PP_ANEMO_Init();
	PP_I2C_Init();
	PP_Boussole_Init();

	while (true) {

		uint8_t data[6];
		PP_I2C_Read6bytesReg(HMC_ADDR, HMC_DATA_REG_X_MSB, data);

		int x = (int16_t)((data[0] << 8) | data[1]);
		int y = (int16_t)((data[2] << 8) | data[3]);
		int z = (int16_t)((data[4] << 8) | data[5]);
		int dir = atan2(y, x)*180./3.14;

		tfp_printf("%d\t%d\t%d\t%d\n", x, y, z, dir);

		TD_RTC_Delay(67*32768/1000); // wait 67 ms

	}*/

}

void TD_USER_Loop(void)
{
	//tfp_printf("Loop %d %d\r\n", RTC_CounterGet()/32768, TD_RTC_GetOverflowCounter());
}
