#include "stm32f10x.h"                  // Device header

void IC_Init(void)
{
	TIM_TimeBaseInitTypeDef TimeBaseInit_Structure;
	TIM_ICInitTypeDef ICInit_Structure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	TIM_InternalClockConfig(TIM3);
	TimeBaseInit_Structure.TIM_ClockDivision = TIM_CKD_DIV1;
	TimeBaseInit_Structure.TIM_CounterMode = TIM_CounterMode_Up;
	TimeBaseInit_Structure.TIM_Period = 65536 - 1;
	TimeBaseInit_Structure.TIM_Prescaler = 72 - 1;
	TimeBaseInit_Structure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &TimeBaseInit_Structure);
	
	ICInit_Structure.TIM_Channel = TIM_Channel_1;
	ICInit_Structure.TIM_ICFilter = 0xF;
	ICInit_Structure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	ICInit_Structure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	ICInit_Structure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_PWMIConfig(TIM3, &ICInit_Structure);
	
	TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1);
	TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_Cmd(TIM3, ENABLE);
}

uint32_t IC_GetFreq(void)
{
	return 1000000 / TIM_GetCapture1(TIM3);
}

uint16_t IC_GetPWMDuty(void)
{
	return ((TIM_GetCapture2(TIM3) + 1) * 100) / (TIM_GetCapture1(TIM3) + 1);
}
