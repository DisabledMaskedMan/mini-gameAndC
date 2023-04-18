#include <REGX52.H>
#include "delay.h"

unsigned char KeyNumber = 0;
unsigned char last = 0;
unsigned char now = 0;

unsigned char key()
{
	unsigned char tmp = KeyNumber;
	KeyNumber = 0;
	return tmp;
}

unsigned char Key_GetState()
{
	if(P3_1 == 0)
		return 1;
	if(P3_0 == 0)
		return 2;
	if(P3_2 == 0)
		return 3;
	if(P3_3 == 0)
		return 4;
	return 0;
}

void KeyLoop()
{
	last = now;
	now = Key_GetState();
	if(now ==0 && last ==1)
		KeyNumber = 1;
	if(now ==0 && last ==2)
		KeyNumber = 2;
	if(now ==0 && last ==3)
		KeyNumber = 3;
	if(now ==0 && last ==4)
		KeyNumber = 4;
}