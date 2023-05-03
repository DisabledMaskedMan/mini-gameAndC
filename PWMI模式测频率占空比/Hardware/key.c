#include "stm32f10x.h"  // Device header
#include "delay.h"

void Key_Init()
{
	GPIO_InitTypeDef GPIO_INITSTRUCTURE;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_INITSTRUCTURE.GPIO_Mode = GPIO_Mode_IPU ; // GPIO_Mode_Out_PP	GPIO_Mode_Out_PP
	GPIO_INITSTRUCTURE.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
	GPIO_INITSTRUCTURE.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_INITSTRUCTURE);
	
}

uint8_t Key_GetNum()
{
	uint8_t KeyNum = 0;
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0){}
		Delay_ms(20);
		KeyNum = 1;
	}
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0){}
		Delay_ms(20);
		KeyNum = 2;
	}
	
	return KeyNum;
}

void Led1_Turn()
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 0)
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	else
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

void Led2_Turn()
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0)
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
	else
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}
