#include <REGX52.H>
#include <timer0.h>
#include <CarRun.h>
#include <delay.h>

sbit ENA = P0^0;
sbit ENB = P0^5;
sbit ENA2 = P1^0;
sbit ENB2 = P1^5;

sbit AOB = P0^6;		//E18D80Nk


sbit PML1 = P2^0;		//左光敏
sbit PML2 = P2^1;
sbit PML3 = P2^2;
sbit PML4 = P2^3;


sbit PMR1 = P3^4;		//右光敏
sbit PMR2 = P3^5;
sbit PMR3 = P3^6;
sbit PMR4 = P3^7;

unsigned char pwm_right, pwm_left;
unsigned char pwm_right_time, pwm_left_time;
unsigned char n = 3;


void main()
{
	Timer0_Init();
	pwm_right = 25;
	pwm_left = 25;
	while(1)
	{
		if(PML3 == 0 && PML4 == 1 && PMR1 == 1 && PMR2 == 1 && PMR3 == 1)
		{
			pwm_right = 15;
			pwm_right_time =15;
			pwm_left = 25;
			pwm_left_time = 25;
			while(!(PML1 == 0 && PML2 == 0 && PML3 == 1 && PML4 == 1 
				&& PMR1 == 1 && PMR2 == 1 && PMR3 == 0 && PMR4 == 0))
			{
				
			}
		}
		
		if(PML2 == 1 && PML3 == 1 && PML4 == 1 && PMR1 == 1 && PMR2 == 0)
		{
			pwm_right = 25;
			pwm_right_time = 25;
			pwm_left = 15;
			pwm_left_time = 15;
			while(!(PML1 == 0 && PML2 == 0 && PML3 == 1 && PML4 == 1 
				&& PMR1 == 1 && PMR2 == 1 && PMR3 == 0 && PMR4 == 0))
			{
				
			}
		}
		
		if(PML1 == 1 && PML2 == 1 && PML3 == 1 && PML4 == 1)
		{
			pwm_right = 25;
			pwm_right_time = 25;
			pwm_left = 5;
			pwm_left_time = 5;
			while(!(PML1 == 0 && PML2 == 0 && PML3 == 1 && PML4 == 1 
				&& PMR1 == 1 && PMR2 == 1 && PMR3 == 0 && PMR4 == 0))
			{
				
			}
		}
		
		if(PMR1 == 1 && PMR2 == 1 && PMR3 == 1 && PMR4 == 1)
		{
			pwm_right = 5;
			pwm_right_time =5;
			pwm_left = 25;
			pwm_left_time = 25;
			while(!(PML1 == 0 && PML2 == 0 && PML3 == 1 && PML4 == 1 
				&& PMR1 == 1 && PMR2 == 1 && PMR3 == 0 && PMR4 == 0))
			{
				
			}
		}
		
		if(PML3 == 1 && PML4 == 1 && PMR1 == 1 && PMR2 == 1 && PMR3 == 1 && PMR4 == 1)
		{
			CarStop();
			delay(100);
			CarRight();
		}
		
		if(PML1 == 1 && PML2 == 1 && PML3 == 1 && PML4 == 1 && PMR1 == 1 && PMR2 == 1)
		{
			CarStop();
			delay(100);
			CarLeft();
		}
		
		if(PML1 == 1 && PML2 == 1 && PML3 == 1 && PML4 == 1 
			&& PMR1 == 1 && PMR2 == 1 && PMR3 == 1 && PMR4 == 1)
		{
			delay(100);
			if(PML1 == 0 && PML2 == 0 && PML3 == 0 && PML4 == 0 
				&& PMR1 == 0 && PMR2 == 0 && PMR3 == 0 && PMR4 == 0)
			{
				CarStop();
				delay(2000);
				n--;
				if(n == 0)
				{
					while(1)
					{
						
					}
				}
			}
		}
		
		if(AOB == 0)
		{
			Car_Left_Shift();
			pwm_right = 25;
			pwm_right_time = 25;
			delay(500);
			
			Car_Right_Shift();
			pwm_left = 25;
			pwm_left_time = 25;
			while(!(PML1 == 0 && PML2 == 0 && PML3 == 1 && PML4 == 1 
				&& PMR1 == 1 && PMR2 == 1 && PMR3 == 0 && PMR4 == 0))
			{
				
			}
			CarGo();
			pwm_left = 25;
			pwm_left_time = 25;
			pwm_right = 25;
			pwm_right_time = 25;
			
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
		pwm_right_time++;
		if(pwm_right_time > pwm_right)
			pwm_right_time = pwm_right;
		pwm_left_time++;
		if(pwm_left_time > pwm_left)
			pwm_left_time = pwm_left;
	}
	if(count >= pwm_right_time)
	{
		ENA = 0;
		ENA2 = 0;
	}
	if(count >= pwm_left_time)
	{
		ENB = 0;
		ENB2 = 0;
	}
	if(count < pwm_right_time)
	{
		ENA = 1;
		ENA2 = 1;
	}
	if(count < pwm_left_time)
	{
		ENB = 1;
		ENB2 = 1;
	}
}