#include "bsp_key.h"

//按键引脚初始化
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitKey;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

	GPIO_InitKey.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitKey.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitKey.GPIO_Speed = GPIO_High_Speed;
//	GPIO_InitKey.GPIO_OType = GPIO_OType_PP;  //输入模式无需配置输出
	GPIO_InitKey.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOA, &GPIO_InitKey);
}

uint8_t Key_Detect(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 1) {
		while (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 1);
		return 1;
	}
	else
		return 0;
}
