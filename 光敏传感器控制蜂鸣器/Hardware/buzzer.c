#include "stm32f10x.h"                  // Device header

void Buzzer_Init()
{
	GPIO_InitTypeDef GPIO_INITSTRUCTURE;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_INITSTRUCTURE.GPIO_Mode = GPIO_Mode_Out_PP ; // GPIO_Mode_Out_PP
	GPIO_INITSTRUCTURE.GPIO_Pin = GPIO_Pin_12;
	GPIO_INITSTRUCTURE.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_INITSTRUCTURE);
	
}

void Buzzer_ON()
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);
}

void Buzzer_Off()
{
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

