#ifndef INCLUDE_WHEEL_H_
#define INCLUDE_WHEEL_H_

#include "GPIO_conf.h"
#include "GPIO.h"

#include "cmsis_device.h"

#include <stdbool.h>
#include <stdint.h>


/* LEFT
 * usage			Arduino					stm32
 * standby			4						PB_5 (NOT PA_3, PA_8)
 * decoder			2						PB_9
 * pwm				5						PB_4
 * in1				6						PB_10
 * in2				8						PB_3
 */

/* RIGHT
 * usage			Arduino					stm32
 * standby			?						PB_15
 * decoder			?						PB_8
 * pwm				?						PB_1
 * in1				?						PB_14
 * in2				?						PB_13
 */

void Wheel_Initialize(void);
void EXTI4_15_IRQHandler(void);
void Wheel_Straight(bool forward, uint16_t velocity);
void Wheel_TurnLeftWheel(bool forward, uint16_t velocity);
void Wheel_TurnRightWheel(bool forward, uint16_t velocity);
void Wheel_StopLeftWheel(void);
void Wheel_StopRightWheel(void);




#endif /* INCLUDE_WHEEL_H_ */
