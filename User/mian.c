#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_key.h"


int main(void)
{
	LED_GPIO_Config();
	Key_GPIO_Config();
	while(1) {
		if (Key_Detect(GPIOA, GPIO_Pin_0) == 1) {
			GPIO_ToggleBits(GPIOH, GPIO_Pin_12);
		}
	}
	return 0;
}



