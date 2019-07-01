#include"lpc17xx.h"
#include "type.h"

 LPC_SC->PCONP |= (1<<12);						//SET PCDAC
LPC_ADC->ADCR |=	(1<<21);						//ENABLE ADC, POWER UP
LPC_ADC->ADCR |= (0x01<<0);						//AD0.0 SELECTED

//LPC_ADC->ADCR &=	~(1<<21);						//CLEAR PDN BIT
//LPC_SC->PCONP &= ~(1<<12);						//CLEAR PCADC				

LPC_SC->PCLKSEL0 |= (0x00<<24); 	
LPC_ADC->ADCR |= (0x01<<8);							//CLKDIV
LPC_PINCON->PINSEL1 = (0x01<<14);
LPC_PINCON->PINMODE1 = 0X01<<14;
	LPC_ADC->ADCR |= (0x01<<24);					//SET 001 for start conversion