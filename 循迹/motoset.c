#include <REGX52.H>

//电机L298N
sbit IN1 = P0^1;
sbit IN2 = P0^2;
sbit IN3 = P0^3;
sbit IN4 = P0^4;

//电机L298N
sbit IN12 = P1^1;
sbit IN22 = P1^2;
sbit IN32 = P1^3;
sbit IN42 = P1^4;

void Moto_Right_Up_Forward()
{
	IN1 = 0;
	IN2 = 1;
}

void Moto_Right_Under_Forward()
{
	IN12 = 0;
	IN22 = 1;
}

void Moto_Left_Up_Forward()
{
	IN3 = 0;
	IN4 = 1;
}

void Moto_Left_Under_Forward()
{
	IN32 = 0;
	IN42 = 1;
}

void Moto_Right_Up_Back()
{
	IN1 = 1;
	IN2 = 0;
}

void Moto_Right_Under_Back()
{
	IN12 = 1;
	IN22 = 0;
}

void Moto_Left_Up_Back()
{
	IN3 = 1;
	IN4 = 0;
}

void Moto_Left_Under_Back()
{
	IN32 = 1;
	IN42 = 0;
}

void Motto_Right_Up_Stop()
{
	IN1 = 0;
	IN2 = 0;
}

void Motto_Right_Under_Stop()
{
	IN12 = 0;
	IN22 = 0;
}

void Moto_Left_Up_Stop()
{
	IN3 = 0;
	IN4 = 0;
}

void Moto_Left_Under_Stop()
{
	IN32 = 0;
	IN42 = 0;
}