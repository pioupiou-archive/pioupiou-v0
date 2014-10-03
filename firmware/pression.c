/*
 * pression.c
 *
 *  Created on: 5 juin 2014
 *      Author: nicolas
 */
#include "pression.h"

int16_t AC1;
int16_t AC2;
int16_t AC3;
uint16_t AC4;
uint16_t AC5;
uint16_t AC6;
int16_t B1;
int16_t B2;
int16_t MB;
int16_t MC;
int16_t MD;

I2C_TransferReturn_TypeDef I2CDRV_Transfer(I2C_TransferSeq_TypeDef *seq) {
	uint32_t timeout = 100000;
	I2C_TransferReturn_TypeDef ret;

	/* Do a polled transfer */
	ret = I2C_TransferInit(I2C0, seq);
	while (ret == i2cTransferInProgress && timeout--) {
		ret = I2C_Transfer(I2C0);
	}

	return(ret);
}

uint16_t BMP180_ReadReg (uint8_t addr, uint8_t reg ) {

	I2C_TransferSeq_TypeDef seq;
	I2C_TransferReturn_TypeDef ret;
	uint8_t regid[1];
	uint8_t data[2];

	seq.addr = addr;
	seq.flags = I2C_FLAG_WRITE_READ;
	/* Select register to be read */
	regid[0] = reg;
	seq.buf[0].data = regid;
	seq.buf[0].len = 1;


	/* 2 bytes reg */
	data[0] = 0;
	data[1] = 0;
	seq.buf[1].data = data;
	seq.buf[1].len = 2;


	ret = I2CDRV_Transfer(&seq);
	if (ret != i2cTransferDone) {
		return(0);
	}

	return((data[0] << 8) | data[1]);

}


uint8_t BMP180_Read8bitReg(uint8_t addr, uint8_t reg){

	I2C_TransferSeq_TypeDef seq;
	I2C_TransferReturn_TypeDef ret;
	uint8_t regid[1];
	uint8_t data[2];

	seq.addr = addr;
	seq.flags = I2C_FLAG_WRITE_READ;
	/* Select register to be read */
	regid[0] = reg;
	seq.buf[0].data = regid;
	seq.buf[0].len = 1;


	/* 1 bytes reg */
	data[0] = 0;
	seq.buf[1].data = data;
	seq.buf[1].len = 1;


	ret = I2CDRV_Transfer(&seq);
	if (ret != i2cTransferDone) {
		return(0);
	}

	return (data[0]);

}

int BMP180_WriteReg(uint8_t addr, uint8_t reg, uint8_t value){

	I2C_TransferSeq_TypeDef seq;
	I2C_TransferReturn_TypeDef ret;
	uint8_t data[3];

	seq.addr = addr;
	seq.flags = I2C_FLAG_WRITE;

	/* Select register to be written */
	data[0] = reg;
	seq.buf[0].data = data;

	/* Only 1 byte reg */
	data[1] = value;
	seq.buf[0].len = 2;

	ret = I2CDRV_Transfer(&seq);
	if (ret != i2cTransferDone) {
		return((int)ret);
	}

	return(ret);

}

void BMP180_GetCalData(void){

	AC1 = BMP180_ReadReg(0xee, 0xaa);
	AC2 = BMP180_ReadReg(0xee, 0xac);
	AC3 = BMP180_ReadReg(0xee, 0xae);
	AC4 = BMP180_ReadReg(0xee, 0xb0);
	AC5 = BMP180_ReadReg(0xee, 0xb2);
	AC6 = BMP180_ReadReg(0xee, 0xb4);
	B1 = BMP180_ReadReg(0xee, 0xb6);
	B2 = BMP180_ReadReg(0xee, 0xb8);
	MB = BMP180_ReadReg(0xee, 0xba);
	MC = BMP180_ReadReg(0xee, 0xbc);
	MD = BMP180_ReadReg(0xee, 0xbe);

}

int32_t BMP180_GetTempData(void){

  BMP180_WriteReg(0xee, 0xf4, 0x2e);

  TD_RTC_Delay(T5MS);

  return BMP180_ReadReg(0xee, 0xf6);
}

int32_t BMP180_GetPressureData(void){

	uint16_t MSB;
	uint8_t XLSB;

	BMP180_WriteReg(0xee, 0xf4, 0x34 + (0 << 6));

	TD_RTC_Delay(T5MS);

	MSB = BMP180_ReadReg(0xee, 0xf6);
	XLSB = BMP180_Read8bitReg(0xee, 0xf8);

	return ( ( MSB << 8 ) + XLSB ) >> 8;

}

void BMP180_CalculateTempPressure(int32_t UT, int32_t UP, int32_t* T_return, int32_t* P_return) {

	int32_t X1;
	int32_t X2;
	int32_t X3;
	int32_t B3;
	uint32_t B4;
	int32_t B5;
	int32_t B6;
	int32_t B7;
	int32_t T;
	int32_t P;

	X1 = (UT - AC6) * AC5 / (1 << 15);
	X2 = MC * (1 << 11) / (X1 + MD);
	B5 = X1 + X2;

	T = (B5 + 8)/(1 << 4);

	B6 = B5 - 4000;
	X1 = (B2 * (B6 * B6 / (1<<12) )) / (1<<11);
	X2 = AC2 * B6 / (1<<11);
	X3 = X1 + X2;
	B3 = ((AC1 * 4 + X3) + 2) / 4;
	X1 = AC3 * B6 / (1<<13);
	X2 = (B1 * (B6 * B6 / (1<<12))) / (1<<16);
	X3 = ((X1 + X2) + 2) / (1<<2);
	B4 = AC4 * (uint32_t)(X3 + 32768) / (1<<15);
	B7 = ((uint32_t) UP - B3) * 50000;

	if(B7 < 0x80000000){
		P = (B7 * 2) / B4;
	} else{
		P = (B7 / B4) * 2;
	}

	X1 = (P / (1<<8)) * (P / (1<<8));
	X1 = (X1 * 3038) / (1<<16);
	X2 = (-7357 * P) / (1<<16);

	P = P + (X1 + X2 + 3791) / (1<<4);

	*T_return = T;
	*P_return = P;

}

void PP_PRESSION_Init (void) {

	CMU_ClockEnable(cmuClock_I2C0, true);

	GPIO_PinModeSet(I2C_SDA_PORT, I2C_SDA_PIN, gpioModeWiredAndPullUp, 1);
	GPIO_PinModeSet(I2C_SCL_PORT, I2C_SCL_PIN, gpioModeWiredAndPullUp, 1);

	I2C0->ROUTE |= I2C_ROUTE_SDAPEN | I2C_ROUTE_SCLPEN;

	const I2C_Init_TypeDef init = I2C_INIT_DEFAULT;
	I2C_Init(I2C0, &init);

	BMP180_GetCalData();

	I2C_Enable(I2C0, false);
	CMU_ClockEnable(cmuClock_I2C0, false);

}

void PP_PRESSION_Read (int32_t* T_return, int32_t* P_return) {

	CMU_ClockEnable(cmuClock_I2C0, true);
	I2C_Enable(I2C0, true);

	int32_t temp_pressure_sensor_raw, pressure_raw;

	temp_pressure_sensor_raw = BMP180_GetTempData();
	pressure_raw = BMP180_GetPressureData();

	BMP180_CalculateTempPressure(temp_pressure_sensor_raw, pressure_raw, T_return, P_return);

	I2C_Enable(I2C0, false);
	CMU_ClockEnable(cmuClock_I2C0, false);

}
