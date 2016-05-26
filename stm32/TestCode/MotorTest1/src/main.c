#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "GPIO_conf.h"
#include "GPIO.h"
#include "cmsis_device.h"
#include <stdbool.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

/*
 * usage			Arduino					stm32
 * standby			0						PA_3
 * decoder			2						PA_10
 * pwm				5						PB_4
 * in1				6						PB_10
 * in2				8						PA_9
 */

void setup(void);
void EXTI4_15_IRQHandler(void);
void delay(void);
void left_wheel(bool forward, uint16_t velocity, uint32_t steps);

uint32_t counter = 0;

void setup(void) {
	GPIO_conf_OutputPin(GPIOA, GPIO_Pin_3); 		// standby
	GPIO_conf_InputPin(GPIOA, GPIO_Pin_10); 		// decoder
	GPIO_conf_PwmPin(GPIOB, GPIO_Pin_4); 			// pwm
	GPIO_conf_OutputPin(GPIOB, GPIO_Pin_10); 		// in1
	GPIO_conf_OutputPin(GPIOA, GPIO_Pin_9); 		// in2
	GPIO_conf_InterruptPin(GPIOA, GPIO_Pin_10);  	// decoder interrupt
}

void EXTI4_15_IRQHandler(void) {
	if ((EXTI->PR & EXTI_PR_PR10) != (uint32_t)0) { // line 10 aka pin 10
		EXTI->PR = EXTI_PR_PR10;
		//trace_print("pulse");
		counter++;
		NVIC_ClearPendingIRQ(EXTI4_15_IRQn);
	}
}

void delay(void){
	uint32_t i = 12345;
	while (i > 0) {
		i--;
	}
}

void left_wheel(bool forward, uint16_t velocity, uint32_t steps) {
	GPIO_AnalogWrite(GPIOB, GPIO_Pin_4, velocity);
	counter = 0;
	while (counter < steps) {
		GPIO_DigitalWrite(GPIOA, GPIO_Pin_3, HIGH);
		if (forward) {
			GPIO_DigitalWrite(GPIOB, GPIO_Pin_10, HIGH);
			GPIO_DigitalWrite(GPIOA, GPIO_Pin_9, LOW);
		} else {
			GPIO_DigitalWrite(GPIOB, GPIO_Pin_10, LOW);
			GPIO_DigitalWrite(GPIOA, GPIO_Pin_9, HIGH);
		}
	}

	GPIO_DigitalWrite(GPIOB, GPIO_Pin_10, HIGH);
	GPIO_DigitalWrite(GPIOA, GPIO_Pin_9, HIGH);
}

void main(int argc, char* argv[]) {
	while (1) {
		left_wheel(true, 50, 100);
		delay();
		left_wheel(false, 100, 10);
	}
}

#pragma GCC diagnostic pop
