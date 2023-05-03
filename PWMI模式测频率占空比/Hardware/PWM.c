#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	TIM_TimeBaseInitTypeDef TimeBaseInit_Structure;
	TIM_OCInitTypeDef OCInit_Structure;
	GPIO_InitTypeDef GPIOInit_Structure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	TIM_InternalClockConfig(TIM2);
	TimeBaseInit_Structure.TIM_ClockDivision = TIM_CKD_DIV1;
	TimeBaseInit_Structure.TIM_CounterMode = TIM_CounterMode_Up;
	TimeBaseInit_Structure.TIM_Period = 100 - 1;
	TimeBaseInit_Structure.TIM_Prescaler = 720 - 1;
	TimeBaseInit_Structure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TimeBaseInit_Structure);
	
	TIM_OCStructInit(&OCInit_Structure);
	OCInit_Structure.TIM_OCMode = TIM_OCMode_PWM1;
	OCInit_Structure.TIM_OCPolarity = TIM_OCPolarity_High;
	OCInit_Structure.TIM_OutputState = TIM_OutputState_Enable;
	OCInit_Structure.TIM_Pulse = 0;
	TIM_OC1Init(TIM2, &OCInit_Structure);
	
	GPIOInit_Structure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIOInit_Structure.GPIO_Pin = GPIO_Pin_0;
	GPIOInit_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOInit_Structure);
	
	TIM_Cmd(TIM2, ENABLE);
	
}

void Set_Compare1(uint16_t Compare1)
{
	TIM_SetCompare1(TIM2, Compare1);
}
