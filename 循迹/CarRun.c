#include <REGX52.H>
#include <motoset.h>

void CarLeft()
{
	Moto_Right_Up_Forward();
	Moto_Right_Under_Forward;
	Moto_Left_Up_Back();
	Moto_Left_Under_Back();
}

void CarRight()
{
	Moto_Left_Up_Forward();
	Moto_Left_Under_Forward();
	Moto_Right_Up_Back();
	Moto_Right_Under_Back();
}

void CarGo()
{
	Moto_Right_Up_Forward();
	Moto_Right_Under_Forward();
	Moto_Left_Up_Forward();
	Moto_Left_Under_Forward;
}

void CarBack()
{
	Moto_Right_Up_Back();
	Moto_Right_Under_Back();
	Moto_Left_Up_Back();
	Moto_Left_Under_Back();
}

void CarStop()
{
	Motto_Right_Up_Stop();
	Motto_Right_Under_Stop();
	Moto_Left_Up_Stop();
	Moto_Left_Under_Stop();
}

void Car_Left_Shift()
{
	Moto_Right_Up_Forward();
	Moto_Right_Under_Forward();
	Moto_Left_Up_Stop();
	Moto_Left_Under_Stop();
}

void Car_Right_Shift()
{
	Moto_Left_Up_Forward();
	Moto_Left_Under_Forward();
	Motto_Right_Up_Stop();
	Motto_Right_Under_Stop();
}