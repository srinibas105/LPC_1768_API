#include "lpc17xx.h"
#include "lcd_sri.h"

	void GLCD_Init(void)
{
		LPC_GPIO2->FIODIR |= LCD_DATA_MASKING;
	LPC_GPIO1->FIODIR	|= LCD_CONTROL_MASKING;
	LPC_GPIO1->FIOPIN |= LCD_B;
}

void cmdLCD(uint8_t cmd){
	send_Nibble(((cmd ) >> 0x04) & 0x0F);
	LPC_GPIO1->FIOPIN &= ~RS;
	LPC_GPIO1->FIOPIN &= ~RW;
	LPC_GPIO1->FIOPIN |= EN;
	delay();
	LPC_GPIO1->FIOPIN &= ~EN;	
		delay();
	
	//(For Lower Nibble)
	
	send_Nibble(cmd & 0x0F);
	LPC_GPIO1->FIOPIN &= ~RS;
	LPC_GPIO1->FIOPIN &= ~RW;
	LPC_GPIO1->FIOPIN |= EN;
	delay();
	LPC_GPIO1->FIOPIN &= ~EN;	
		delay();
}
	
void delay()
{
		volatile int i=0,j=0;
		for(i=0;i<10;i++)
	{
		for(j=0;j<10000;j++);
	}
}

void send_Nibble(uint8_t nibble)
{
		LPC_GPIO1->FIOPIN;							//		DATA PORT		
		LPC_GPIO2->FIOPIN;							//		CONTROL PORT

	//char nibble;
	LPC_GPIO2->FIOPIN &= ~(LCD_DATA_MASKING);									//	CLEAR DATA
	
	LPC_GPIO2->FIOPIN |= ((( nibble >>0x00) & 0x01) << 4);
	LPC_GPIO2->FIOPIN |= (((nibble >> 0x01) & 0x01) << 5);
	LPC_GPIO2->FIOPIN |=(((nibble >> 0x02) & 0x01) << 6);
	LPC_GPIO2->FIOPIN |=(((nibble >> 0x03) & 0x01) << 7);
}

int main()
{
	
	void GLCD_Init(void);
	
			cmdLCD(0x02);
			cmdLCD(0x28);
			cmdLCD(0x0E);
			cmdLCD(0x01);
			cmdLCD(0x80);
	
		//		dataLCD('A');

	while(1)
	{}
}
