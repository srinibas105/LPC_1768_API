#include"lpc17xx.h"
void delay()
{
		volatile int i=0,j=0;
		for(i=0;i<1000;i++)
	{
		for(j=0;j<10000;j++);
	}
}

int main()
{
	while(1)
	{
		LPC_GPIO2->FIODIR = (1<<11);
		
	LPC_GPIO2->FIOSET = (1<<11);
	delay();
	
	LPC_GPIO2->FIOCLR = (1<<11);
	delay();
		delay();
	}
			
}