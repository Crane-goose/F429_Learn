#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "stm32f4xx.h"
void Key_GPIO_Config(void);
uint8_t Key_Detect(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


#endif //_BSP_KEY_H
