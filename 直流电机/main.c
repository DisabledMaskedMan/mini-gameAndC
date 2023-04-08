#include <REGX52.H>
#include <delay.h>

sbit ENA = P0^0;
sbit IN1 = P0^1;
sbit IN2 = P0^2;
sbit IN3 = P0^3;
sbit IN4 = P0^4;
sbit ENB = P0^5;


void main()
{
	ENA = 1;
	IN1 = 0;
	IN2 = 1;
	ENB = 1;
	IN3 = 0;
	IN4 = 1;
	
	delay(2000);
	ENA = 0;
	ENB = 0;
	while(1)
	{
		
	}
}