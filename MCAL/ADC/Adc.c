/*
 * Adc.c
 *
 *  Created on: Apr 1, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Bit_utils.h"
#include "Adc.h"
#include "avr/io.h"


void Adc_vidInit()
{
	SET_BIT(ADMUX,REFS0); // configure vref to avcc
	SET_BIT(ADCSRA,ADEN); // enable ADC
}
Adc_enuErrorStatus Adc_enuGetReading( pu16 Add_pu16Reading )
{
	Adc_enuErrorStatus Loc_enuError = AdcOk;

	if(Add_pu16Reading == NULL)
	{
		Loc_enuError = AdcNok;
	}

	while(GET_BIT(ADCSRA,ADIF)==0);
	*Add_pu16Reading = ADCL | ((u16)(ADCH)<< 8) ;
	SET_BIT(ADCSRA,ADIF);
	return Loc_enuError;
}
