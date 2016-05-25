/*
 * GPIO_conf.c
 *
 *  Created on: May 24, 2016
 *      Author: vagrant
 */

#include "GPIO_conf.h"

#include "cmsis_device.h"

void GPIO_conf_OutputPin(GPIO_TypeDef* GPIOx, uint16_t pin) {

	if (GPIOx == GPIOA) {
		RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	} else if (GPIOx == GPIOB) {
		RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	} else if (GPIOx == GPIOC) {
		RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	} else {
		// Now what?!
	}

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOx, &GPIO_InitStructure);

}
