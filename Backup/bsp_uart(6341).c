#include "bsp.h"

void UART_Config(void)
{
	NVIC_InitTypeDef NVIC_UART;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_UART.NVIC_IRQChannel = USART1_IRQn;
	NVIC_UART.NVIC_IRQChannelCmd = ENABLE;
	NVIC_UART.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_UART.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_UART);

	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOA, GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource_9|GPIO_PinSource_10, GPIO_AF_USART1);
	
	
	USART_InitTypeDef USART_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_Init(USART1, &USART_InitStructure);

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART1, ENABLE);


//	EXTI_InitTypeDef EXTI_InitUART;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
//	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);	
//	EXTI_InitUART.EXTI_Line = EXTI_Line0;
//	EXTI_InitUART.EXTI_LineCmd = ENABLE;
//	EXTI_InitUART.EXTI_Mode = EXTI_Mode_Interrupt;
//	EXTI_InitUART.EXTI_Trigger = EXTI_Trigger_Rising_Falling;	
//	EXTI_Init(&EXTI_InitUART);
	
}

void USART1_IRQnHandler(void)
{
	uint8_t ucTemp;
	if(USART_GetITStatus(USART1,USART_IT_RXNE)!=RESET)
	{
		ucTemp = USART_ReceiveData(USART1);
		USART_SendData(USART1,ucTemp);
	}
}
