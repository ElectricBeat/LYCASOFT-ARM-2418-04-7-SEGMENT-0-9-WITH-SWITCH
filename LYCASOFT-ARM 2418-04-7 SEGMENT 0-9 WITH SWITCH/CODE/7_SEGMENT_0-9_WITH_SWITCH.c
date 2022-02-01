#include<lpc21xx.h>
#include "LPC2148_delay.h"

char DIG[10]={0x3f,0X06,0X5b,0X4F,0X66,0x6d,0x7d,0x07,0x7f,0x6f};			//comman cathode type;
//char DIG[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};			//comman anode type;

int Count=0;

int main()
{
	PINSEL0 = 0x00000000;
	IODIR0 = 0x000000ff;
	
	while(1)
	{	
		while(IOPIN0 == 0x80000000)
		{
			IOCLR0=DIG[Count];
			Count++;
			while(IOPIN0 == 0x80000000);
		}

		IOSET0=DIG[Count];
		
		if(Count >= 10)
		{
			Count = 0;
		}
	}
}