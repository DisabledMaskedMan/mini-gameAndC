#include "stm32f10x.h"  // Device header
#include "Delay.h"
#include "led.h"
#include "key.h"
#include "buzzer.h"
#include "Light_Sensor.h"



uint8_t KeyNum;

int main()
{
	GM_Init();
	Buzzer_Init();
	while(1)
	{
		KeyNum = GM_Num();
		if(KeyNum == 1)
		{
			Buzzer_ON();
		}
		
		if(KeyNum == 2)
		{
			Buzzer_Off();
		}
	}
}
