#include "bsp.h"

void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_Key;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	NVIC_Key.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_Key.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Key.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_Key.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_Key);
}

void EXTI_Config(void)
{
	EXTI_InitTypeDef EXTI_InitKey;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
	
	EXTI_InitKey.EXTI_Line = EXTI_Line0;
	EXTI_InitKey.EXTI_LineCmd = ENABLE;
	EXTI_InitKey.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitKey.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	
	EXTI_Init(&EXTI_InitKey);
}
