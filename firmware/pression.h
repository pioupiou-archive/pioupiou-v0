/*
 * pression.h
 *
 *  Created on: 5 juin 2014
 *      Author: nicolas
 */

#ifndef PIOUPIOU_PRESSION_H_
#define PIOUPIOU_PRESSION_H_


#include <em_emu.h>
#include <em_cmu.h>
#include <em_gpio.h>
#include <em_i2c.h>

#include <td_rtc.h>
#include <td_printf.h>

#define I2C_SDA_PORT gpioPortA
#define I2C_SDA_PIN	0

#define I2C_SCL_PORT gpioPortA
#define I2C_SCL_PIN	1

void PP_PRESSION_Init(void);
void PP_PRESSION_Read(int32_t* T_return, int32_t* P_return);

#endif /* PIOUPIOU_PRESSION_H_ */
