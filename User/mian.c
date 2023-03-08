#include "stm32f4xx.h"
#include "bsp_led.h"

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}

int main(void)
{
	LED_GPIO_Config();
	while(1) {
        GPIO_ResetBits(GPIOH, GPIO_Pin_12);		
		Delay(0xFFFFF);
        GPIO_SetBits(GPIOH, GPIO_Pin_12);
        Delay(0xFFFFF);
		
	}
	return 0;

}



