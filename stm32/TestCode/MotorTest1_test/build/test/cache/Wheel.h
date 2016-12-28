#include "cmsis_device.h"
#include "GPIO.h"
#include "GPIO_conf.h"












void Wheel_Initialize(void);

void EXTI4_15_IRQHandler(void);

void Wheel_Straight(_Bool forward, uint16_t velocity);

void Wheel_TurnLeftWheel(_Bool forward, uint16_t velocity);

void Wheel_TurnRightWheel(_Bool forward, uint16_t velocity);

void Wheel_StopLeftWheel(void);

void Wheel_StopRightWheel(void);
