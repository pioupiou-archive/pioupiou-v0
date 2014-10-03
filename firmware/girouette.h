/*
 * girouette.h
 *
 *  Created on: 3 juin 2014
 *      Author: nicolas
 */

#ifndef PIOUPIOU_GIROUETTE_H_
#define PIOUPIOU_GIROUETTE_H_

#include <em_cmu.h>
#include <em_gpio.h>
#include <em_acmp.h>

#include <td_rtc.h>
#include <td_watchdog.h>

#define GIROUETTE_SENSE_PORT gpioPortC
#define GIROUETTE_SENSE_PIN 1

#define GIROUETTE_LED_PORT_A gpioPortB
#define GIROUETTE_LED_PIN_A 13

#define GIROUETTE_LED_PORT_B gpioPortD
#define GIROUETTE_LED_PIN_B 5

#define GIROUETTE_LED_PORT_C gpioPortD
#define GIROUETTE_LED_PIN_C 6

#define GIROUETTE_LED_PORT_D gpioPortD
#define GIROUETTE_LED_PIN_D 7

#define GIROUETTE_STEP_RADIANS 0.392699082 //22.5 °

void PP_GIROUETTE_Init(void);
int PP_GIROUETTE_Read(void);
void PP_GIROUETTE_Test (void);
#endif /* PIOUPIOU_GIROUETTE_H_ */
