#include "lpc17xx.h"

#define RS (1<<24)
#define EN (1<<22)
#define RW (1<<23)
#define LCD_B (1<<21)

#define D4 (1<<4)
#define D5 (1<<5)
#define D6 (1<<6)
#define D7 (1<<7)

#define LCD_DATA_MASKING ((1<<4) | (1<<5) | (1<<6) | (1<<7))
#define LCD_CONTROL_MASKING ( (1<<24) | (1<<22) | (1<<23) | (1<<21))


//typedef unsigned int U32;
	//typedef unsigned char U8;
	
	void delay(void);
	void GLCD_Init(void);
	void cmdWrite(uint8_t cmd);
	void dataWrite(uint8_t data);
	void GLCD_Clear(uint8_t line);
	void PrintString(uint8_t *str,uint8_t line);
	void send_Nibble(uint8_t nibble);
	



