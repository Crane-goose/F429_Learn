#include "bsp.h"
void Bsp_Init(void)
{
	LED_GPIO_Config();
	//Key_GPIO_Config();
	//NVIC_Config();
	//EXTI_Config();
	SysTick_Init();
}
