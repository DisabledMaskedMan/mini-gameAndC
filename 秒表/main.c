#include <REGX52.H>
#include "AT24C02.h"
#include "timer0.h"
#include "Nixie.h"
#include "delay.h"
#include "Key.h"

unsigned char KeyNum;
unsigned char minute,second,minisec;
unsigned char timeflag;

void main()
{
	Timer0_Init();
	
	while(1)
	{
		KeyNum = key();
		if(KeyNum == 1)
			timeflag = !timeflag;
		if(KeyNum == 2)
		{
			minute = 0;
			second = 0;
			minisec = 0;
		}
		if(KeyNum == 3)
		{
			AT24C02_Write(0, minute);
			delay(5);
			AT24C02_Write(1, second);
			delay(5);
			AT24C02_Write(2, minisec);
			delay(5);
		}
		if(KeyNum == 4)
		{
			minute = AT24C02_Read(0);
			second = AT24C02_Read(1);
			minisec = AT24C02_Read(2);
		}
		Nixie_SetBuf(1, minute / 10);
		Nixie_SetBuf(2, minute % 10);
		Nixie_SetBuf(3, 11);
		Nixie_SetBuf(4, second / 10);
		Nixie_SetBuf(5, second % 10);
		Nixie_SetBuf(6, 11);
		Nixie_SetBuf(7, minisec / 10);
		Nixie_SetBuf(8, minisec % 10);
	}
}

void SecLoop()
{
	if(timeflag)
	{
		minisec++;
		if(minisec > 99)
		{
			second++;
			minisec = 0;
			if(second > 59)
			{
				second = 0;
				minute++;
				if(minute > 59)
					minute = 0;
			}
		}
	}
	
}

void Timer0_Rountine() interrupt 1
{
	static unsigned int count1, count2, count3;
	TL0 = 0x66;
	TH0 = 0xFC;
	count1++;
	if(count1 == 20)
	{
		count1 = 0;
		KeyLoop();
	}
	count2++;
	if(count2 == 2)
	{
		count2 = 0;
		Nixie_Loop();
	}
	count3++;
	if(count3 == 10)
	{
		count3 = 0;
		SecLoop();
	}
}