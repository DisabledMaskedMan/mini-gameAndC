#include <REGX52.H>
#include "DS18B20.h"
#include "AT24C02.h"
#include "LCD1602.h"
#include "key.h"
#include "delay.h"
#include "Timer0.h"

unsigned char KeyNum;
float Temperature;
char Tlow,Thigh;

void main()
{
	LCD_Init();
	Timer0_Init();
	LCD_ShowString(1, 1, "T:");
	DS18B20_ConvetT();
	delay(1000);
	Thigh = AT24C02_Read(0);
	Tlow = AT24C02_Read(1);
	LCD_ShowString(2,1,"TH:");
	LCD_ShowString(2,9,"TL:");
	LCD_ShowSignedNum(2,4,Thigh,3);
	LCD_ShowSignedNum(2,12,Tlow,3);
	if(Thigh > 125 || Thigh <= Tlow || Tlow < -55)
	{
		Thigh = 20;
		Tlow = -15;
	}
	while(1)
	{
		KeyNum = Key();
		
		DS18B20_ConvetT();
		Temperature = DS18B20_ReadT();
		if(Temperature < 0)
		{
			LCD_ShowChar(1, 3, '-');
			Temperature = - Temperature;
		}
		else
		{
			LCD_ShowChar(1, 3, '+');
		}
		LCD_ShowNum(1, 4, Temperature, 3);
		LCD_ShowChar(1, 7, '.');
		LCD_ShowNum(1, 8, (unsigned long)(Temperature*10000)%10000, 4);
		if(KeyNum == 1)
		{
			Thigh++;
			if(Thigh > 125)
				Thigh = 125;
		}
		if(KeyNum == 2)
		{
			Thigh--;
			if(Thigh == Tlow)
				Thigh++;
		}
		if(KeyNum == 3)
		{
			Tlow++;
			if(Tlow == Thigh)
				Tlow--;
		}
		if(KeyNum == 4)
		{
			Tlow--;
			if(Tlow < -55)
				Tlow = -55;
		}
		LCD_ShowSignedNum(2,4,Thigh,3);
		LCD_ShowSignedNum(2,12,Tlow,3);
		AT24C02_Write(0, Thigh);
		delay(5);
		AT24C02_Write(1, Tlow);
		delay(5);
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=20)
	{
		T0Count=0;
		Key_Loop();
	}
}