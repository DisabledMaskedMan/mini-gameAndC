#include <REGX52.H>
#include <delay.h>
#include <timer0.h>

sbit ENA = P0^0;
sbit IN1 = P0^1;
sbit IN2 = P0^2;
sbit IN3 = P0^3;
sbit IN4 = P0^4;
sbit ENB = P0^5;
sbit ENA2 = P1^0;
sbit IN12 = P1^1;
sbit IN22 = P1^2;
sbit IN32 = P1^3;
sbit IN42 = P1^4;
sbit ENB2 = P1^5;
sbit AOB = P0^6;

unsigned char time;

void main()
{
	Timer0_Init();
	ENA = 1;
	ENA2 = 1;
	
	IN1 = 0;
	IN12 = 0;
	IN2 = 1;
	IN22 = 1;
	
	ENB = 1;
	ENB2 = 1;
	
	IN3 = 0;
	IN32 = 0;
	IN4 = 1;
	IN42 = 1;
	
	
	//delay(2000);
	
	while(1)
	{
		if(AOB == 0)
		{
			//停下，左转
			ENA = 0;
			ENA2 = 0;
			ENB = 0;
			ENB2 = 0;
			delay(250);
					
			IN3 = 1;
			IN32 = 1;
			IN4 = 0;
			IN42 = 0;	
			time = 0;
			delay(750);
			
			//停下，直行	
			ENA = 0;
			ENA2 = 0;
			ENB = 0;
			ENB2 = 0;
			delay(250);			
			
			IN1 = 0;
			IN12 = 0;
			IN2 = 1;
			IN22 = 1;
			IN3 = 0;
			IN32 = 0;
			IN4 = 1;
			IN42 = 1;
			delay(500);
			
			//停下，右转
			ENA = 0;
			ENA2 = 0;
			ENB = 0;
			ENB2 = 0;
			delay(450);
			
			IN1 = 1;
			IN12 = 1;	
			IN2 = 0;
			IN22 = 0;
			
			IN3 = 0;
			IN32 = 0;
			IN4 = 1;
			IN42 = 1;
			time = 0;
			delay(900);
				
			//停下，直行	
			ENA = 0;
			ENA2 = 0;
			ENB = 0;
			ENB2 = 0;
			delay(250);	
			
			IN1 = 0;
			IN12 = 0;
			IN2 = 1;
			IN22 = 1;
			IN3 = 0;	
			IN32 = 0;
			IN4 = 1;
			IN42 = 1;
			delay(1150);
			
			//停下，左转
			ENA = 0;
			ENA2 = 0;
			ENB = 0;
			ENB2 = 0;
			delay(250);
			
			IN3 = 1;
			IN32 = 1;
			IN4 = 0;
			IN42 = 0;
			time = 0;
			delay(500);
			
			//停下，直行	
			ENA = 0;
			ENA2 = 0;
			ENB = 0;
			ENB2 = 0;
			delay(350);	
			
			IN1 = 0;
			IN12 = 0;
			IN2 = 1;	
			IN22 = 1;
			IN3 = 0;
			IN32 = 0;
			IN4 = 1;
			IN42 = 1;
		}
	}
}

void Timer0_Rountine() interrupt 1
{
	static unsigned int count;
	TL0 = 0xD7;
	TH0 = 0xFD;
	count++;
	if(count == 100)
	{
		count = 0;
		time++;
		if(time > 25)
			time = 25;
	}
	if(count >= time)
	{
		ENA = 0;
		ENA2 = 0;
		ENB = 0;
		ENB2 = 0;
	}
	if(count < time)
	{
		ENA = 1;
		ENA2 = 1;
		ENB = 1;
		ENB2 = 1;
	}
	
}