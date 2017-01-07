/*
 * DelayTimer.c
 *
 *  Created on: Jan 7, 2017
 *      Author: vagrant
 */

#include "DelayTimer.h"

volatile uint32_t DelayTimer_DelayCount;

void DelayTimer_Initialize(void){
	SysTick_Config(SystemCoreClock / TIMER_FREQUENCY_HZ);
}

void DelayTimer_Sleep(uint32_t ticks) {
	DelayTimer_DelayCount = ticks;
	while (DelayTimer_DelayCount != 0u)
		;
}

void DelayTimer_Tick(void) {
	if (DelayTimer_DelayCount != 0u) {
		--DelayTimer_DelayCount;
	}
}

void Systick_Handler(void) {
	DelayTimer_Tick();
}
