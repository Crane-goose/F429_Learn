 #include "bsp.h"   

 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)
{	
	GPIO_InitTypeDef GPIO_InitLED;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH,ENABLE);

	GPIO_InitLED.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitLED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitLED.GPIO_Speed = GPIO_High_Speed;
	GPIO_InitLED.GPIO_OType = GPIO_OType_PP;
	GPIO_InitLED.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOH, &GPIO_InitLED);
	
}


/*********************************************END OF FILE**********************/
