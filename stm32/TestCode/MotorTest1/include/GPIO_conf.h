/*
 * GPIO_conf.h
 *
 *  Created on: May 24, 2016
 *      Author: vagrant
 */

#ifndef INCLUDE_GPIO_CONF_H_
#define INCLUDE_GPIO_CONF_H_

#include <stdint.h>
#include "cmsis_device.h"

#define LOW 0
#define HIGH 1

void GPIO_conf_OutputPin(GPIO_TypeDef *port, uint16_t pin);
void GPIO_conf_InputPin(GPIO_TypeDef *port, uint16_t pin);
void GPIO_conf_PwmPin(GPIO_TypeDef *port, uint16_t pin, uint8_t pinSource);
void GPIO_conf_InterruptPin(GPIO_TypeDef *port, uint16_t pin);


#endif /* INCLUDE_GPIO_CONF_H_ */
