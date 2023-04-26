#include "stm32f10x.h"                  // Device header

void GM_Init()
{
	GPIO_InitTypeDef GPIO_INITSTRUCTURE;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_INITSTRUCTURE.GPIO_Mode = GPIO_Mode_IPU ; // GPIO_Mode_Out_PP
	GPIO_INITSTRUCTURE.GPIO_Pin = GPIO_Pin_13;
	GPIO_INITSTRUCTURE.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_INITSTRUCTURE);
	
}

uint8_t GM_Num()
{
	uint8_t GM_Num = 2;
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13) == 0)
		GM_Num = 1;
	
	return GM_Num;
}
