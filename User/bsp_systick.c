#include "bsp.h"

static __IO u32 TimingDelay;

void SysTick_Init(void)
{
	if(SysTick_Config(SystemCoreClock / 100000)) {
		while(1);
	}
}

void Delay_us(__IO u32 nTime)
{
	TimingDelay = nTime;
	while(TimingDelay != 0);
}

void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00) {
		TimingDelay--;
	}
}

void SysTick_Handler(void)
{
	TimingDelay_Decrement();
}


