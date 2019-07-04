#include "lpc17xx.h"
#include "lcd_sri.h"

void GLCD_Init(void)
{
	LPC_GPIO2->FIODIR |= LCD_DATA_MASKING;
	LPC_GPIO1->FIODIR	|= LCD_CONTROL_MASKING;
	LPC_GPIO1->FIOPIN |= LCD_B;
	
			cmdWrite(0x02);
			cmdWrite(0x28);
			cmdWrite(0x0E);
			cmdWrite(0x01);
			cmdWrite(0x80);
}

void cmdWrite(uint8_t cmd)
	{
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
void dataWrite(uint8_t data)
	{
	send_Nibble(((data ) >> 0x04) & 0x0F);
	LPC_GPIO1->FIOPIN |= RS;
	LPC_GPIO1->FIOPIN &= ~RW;
	LPC_GPIO1->FIOPIN |= EN;
	delay();
	LPC_GPIO1->FIOPIN &= ~EN;	
		delay();
	
	//(For Lower Nibble)
	
	send_Nibble(data & 0x0F);
	LPC_GPIO1->FIOPIN |= RS;
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

	void PrintString(uint8_t *str,uint8_t line)
{
	while(*str!='\0')
	{
		dataWrite(*str);
			str++;
	}
}

void GLCD_Clear(uint8_t line)
{
					cmdWrite(0x01);

}	
int main()
{
		 GLCD_Init();
	PrintString("SRINIBAS",0);
					cmdWrite(0xC0);
		PrintString("MOHAPATRA",0);


			
	
	/*		dataWrite('W');
	dataWrite('E');
	dataWrite('L');
	dataWrite('C');
	dataWrite('O');
	dataWrite('M');
	dataWrite('E');
				cmdWrite(0xC0);
		dataWrite('T');
	dataWrite('O');
	dataWrite(' ');
	dataWrite('L');
	dataWrite('C');
	dataWrite('D');
	*/
	while(1)
{}
		
}





