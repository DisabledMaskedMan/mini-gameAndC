#include <REGX52.H>
#include "DS1302.h"
#include "LCD1602.h"
#include "delay.h"
#include "timer0.h"
#include "key.h"

unsigned char Mode, KeyNum, TimeSetSelect, Flag;

void DS1302_ShowTime()
{
	DS1302_ReadTime();
	LCD_ShowNum(1, 1, DS1302_Time[0], 2);
	LCD_ShowNum(1, 4, DS1302_Time[1], 2);
	LCD_ShowNum(1, 7, DS1302_Time[2], 2);
	LCD_ShowNum(2, 1, DS1302_Time[3], 2);
	LCD_ShowNum(2, 4, DS1302_Time[4], 2);
	LCD_ShowNum(2, 7, DS1302_Time[5], 2);
}

void DS1302_TimeSet()
{
	if(KeyNum == 2)
	{
		TimeSetSelect++;
		TimeSetSelect %= 6;
	}
	if(KeyNum == 3)
	{
		DS1302_Time[TimeSetSelect]++;
		if(DS1302_Time[0] > 99)
			DS1302_Time[0] = 0;
		if(DS1302_Time[1] > 12)
			DS1302_Time[1] = 1;
		if( DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 || 
			DS1302_Time[1]==8 || DS1302_Time[1]==10 || DS1302_Time[1]==12)
		{
			if(DS1302_Time[2] > 31)
				DS1302_Time[2] = 1;
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 || DS1302_Time[1]==11)
		{
			if(DS1302_Time[2] > 30)
				DS1302_Time[2] = 1;
		}
		else if(DS1302_Time[1]==2)
		{
			if(DS1302_Time[0] % 4 == 0)
			{
				if(DS1302_Time[2] > 29){DS1302_Time[2] = 1;}//闰年2月
			}
			else
			{
				if(DS1302_Time[2] > 28){DS1302_Time[2] = 1;}//平年2月
			}
		}
		if(DS1302_Time[3] > 23)
			DS1302_Time[3] = 0;
		if(DS1302_Time[4] > 59)
			DS1302_Time[4] = 0;
		if(DS1302_Time[5] > 59)
			DS1302_Time[5] = 0;
	}
	if(KeyNum == 4)
	{
		DS1302_Time[TimeSetSelect]--;
		if(DS1302_Time[0] < 0)
			DS1302_Time[0] = 99;
		if(DS1302_Time[1] < 1)
			DS1302_Time[1] = 12;
		if( DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 || 
			DS1302_Time[1]==8 || DS1302_Time[1]==10 || DS1302_Time[1]==12)
		{
			if(DS1302_Time[2] < 1)
				DS1302_Time[2] = 31;
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 || DS1302_Time[1]==11)
		{
			if(DS1302_Time[2] < 1)
				DS1302_Time[2] = 30;
		}
		else if(DS1302_Time[1]==2)
		{
			if(DS1302_Time[0] % 4 == 0)
			{
				if(DS1302_Time[2] < 1){DS1302_Time[2] = 29;}//闰年2月
				if(DS1302_Time[2] > 29){DS1302_Time[2] = 1;}
			}
			else
			{
				if(DS1302_Time[2] < 1){DS1302_Time[2] = 28;}//平年2月
				if(DS1302_Time[2] > 28){DS1302_Time[2] = 1;}
			}
		}
		if(DS1302_Time[3] < 0)
			DS1302_Time[3] = 59;
		if(DS1302_Time[4] < 0)
			DS1302_Time[4] = 59;
		if(DS1302_Time[5] < 0)
			DS1302_Time[5] = 59;
	}
	if(TimeSetSelect == 0 && Flag == 1)LCD_ShowString(1, 1, "  ");
	else LCD_ShowNum(1, 1, DS1302_Time[0]);
	if(TimeSetSelect==1 && Flag==1){LCD_ShowString(1,4,"  ");}
	else {LCD_ShowNum(1,4,DS1302_Time[1],2);}
	if(TimeSetSelect==2 && Flag==1){LCD_ShowString(1,7,"  ");}
	else {LCD_ShowNum(1,7,DS1302_Time[2],2);}
	if(TimeSetSelect==3 && Flag==1){LCD_ShowString(2,1,"  ");}
	else {LCD_ShowNum(2,1,DS1302_Time[3],2);}
	if(TimeSetSelect==4 && Flag==1){LCD_ShowString(2,4,"  ");}
	else {LCD_ShowNum(2,4,DS1302_Time[4],2);}
	if(TimeSetSelect==5 && Flag==1){LCD_ShowString(2,7,"  ");}
	else {LCD_ShowNum(2,7,DS1302_Time[5],2);}
	DS1302_SetTime();
}

void main()
{
	LCD_Init();
	DS1302_Init();
	Timer0_Init();
	LCD_ShowString(1, 1, "  -  -  "); 
	LCD_ShowString(2, 1, "  :  :  "); 
	
	DS1302_SetTime();
	while(1)
	{
		KeyNum = key();
		if(KeyNum == 1)
		{
			if(Mode == 1)
			{
				Mode = 0;
				TimeSetSelect = 0;
			}
			else if(Mode == 0)
			{
				Mode = 1;
				DS1302_SetTime();
			}
		}
		switch(Mode)
		{
			case 1:
				DS1302_TimeSet();
				break;
			case 0:
				DS1302_ShowTime();
				break;
		}
	}
}

void Timer0_Rountine() interrupt 1
{
	static unsigned int count;
	TL0 = 0x66;
	TH0 = 0xFC;
	count++;
	if(count == 1000)
	{
		count = 0;
		Flag = !Flag;
	}
}