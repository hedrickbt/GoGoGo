#include "cmsis_device.h"








void GPIO_conf_OutputPin(GPIO_TypeDef *port, uint16_t pin);

void GPIO_conf_InputPin(GPIO_TypeDef *port, uint16_t pin);

void GPIO_conf_PwmPin(GPIO_TypeDef *port, uint16_t pin, uint8_t pinSource);

void GPIO_conf_InterruptPin(GPIO_TypeDef *port, uint16_t pin);
