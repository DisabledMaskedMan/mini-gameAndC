#include "stm32f10x.h"                  // Device header

void Led_Init(void)
{
	GPIO_InitTypeDef GPIO_INITSTRUCTURE;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_INITSTRUCTURE.GPIO_Mode = GPIO_Mode_Out_PP ; // GPIO_Mode_Out_PP	GPIO_Mode_Out_PP
	GPIO_INITSTRUCTURE.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_INITSTRUCTURE.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_INITSTRUCTURE);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);
}

void Led1_NO(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

void Led1_Off(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

void Led2_NO(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}

void Led2_Off(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}
