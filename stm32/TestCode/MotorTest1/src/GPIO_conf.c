/*
 * GPIO_conf.c
 *
 *  Created on: May 24, 2016
 *      Author: vagrant
 */

#include "GPIO_conf.h"

#include "cmsis_device.h"

void GPIO_conf_OutputPin(GPIO_TypeDef *port, uint16_t pin) {

	if (port == GPIOA) {
		RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	} else if (port == GPIOB) {
		RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	} else if (port == GPIOC) {
		RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	} else {
		// Now what?!
	}

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(port, &GPIO_InitStructure);

}

void GPIO_conf_InputPin(GPIO_TypeDef *port, uint16_t pin) {
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(port, &GPIO_InitStructure);
}

void GPIO_conf_PwmPin(GPIO_TypeDef *port, uint16_t pin) {
	GPIO_InitTypeDef 			GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef 	TIM_TimeBaseStructure;
	TIM_OCInitTypeDef 			TIM_OCInitStructure;

	GPIO_InitStructure.GPIO_Pin = pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(port, &GPIO_InitStructure);

	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = ( SystemCoreClock / 1000 ) - 1;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;

	if (port == GPIOB) {
		if (pin == GPIO_Pin_4) {
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

			GPIO_PinAFConfig(port, pin, GPIO_AF_1);
			TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
			TIM_OC1Init(TIM3, &TIM_OCInitStructure);

			TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
			TIM_SelectOnePulseMode(TIM3, TIM_OPMode_Repetitive);

			TIM_Cmd(TIM3, ENABLE);
			TIM_CtrlPWMOutputs(TIM3, ENABLE);
		}
	}

}
