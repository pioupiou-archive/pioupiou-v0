/*
 * reglages.h
 *
 *  Created on: 17 avr. 2014
 *      Author: nicolas
 */

#ifndef PIOUPIOU_REGLAGES_H_
#define PIOUPIOU_REGLAGES_H_

// == HARDWARE ============



// == EMISSION ===============

// temps entre chaque emission (secondes)
#define REPORT_PERIOD 720 // 12 minutes

// nombre de tranches de donnée (secondes)
#define N_SUBREPORT 3 // toutes les 4 minutes

#define SUBREPORT_PERIOD REPORT_PERIOD/N_SUBREPORT

#define RTC_FREQUENCY 32768
#define RTC_SECONDS_OVERFLOW 512
#define RTC_OVERFLOW RTC_FREQUENCY*RTC_SECONDS_OVERFLOW


// == ANEMO ==================

// temps echantillonage en secondes
// (pas trop gros, pour les rafales)
#define ANEMO_SAMPLE_TIME 2.00

// nombre d'impulsions pour déterminer la
// vitesse initiale
#define ANEMO_START_PULSES 10
#define ANEMO_MIN_PULSES 5
#define ANEMO_MAX_PULSES 100

// calibration
#define ANEMO_HZ_TO_KMH 4.4

#endif /* PIOUPIOU_REGLAGES_H_ */
