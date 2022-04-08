/*
 * Adc.h
 *
 *  Created on: Apr 1, 2022
 *      Author: WINDOWS
 */

#ifndef ADC_H_
#define ADC_H_

typedef enum{
	AdcOk,
	AdcNok
}Adc_enuErrorStatus;


void Adc_vidInit(void);
Adc_enuErrorStatus Adc_enuGetReading( pu16 Add_pu16Reading );



#endif /* ADC_H_ */
