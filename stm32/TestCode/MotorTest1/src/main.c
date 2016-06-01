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
 * standby			0						PA_3, PA_8
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
	GPIO_conf_OutputPin(GPIOA, GPIO_Pin_3); 						// standby
	GPIO_conf_OutputPin(GPIOA, GPIO_Pin_8); 						// standby bth test
	GPIO_conf_InputPin(GPIOA, GPIO_Pin_10); 						// decoder
	GPIO_conf_PwmPin(GPIOB, GPIO_Pin_4, GPIO_PinSource4); 			// pwm
	GPIO_conf_OutputPin(GPIOB, GPIO_Pin_10); 						// in1
	GPIO_conf_OutputPin(GPIOA, GPIO_Pin_9); 						// in2
	GPIO_conf_InterruptPin(GPIOA, GPIO_Pin_10);  					// decoder interrupt
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
	uint32_t i = 123456;
	while (i > 0) {
		i--;
	}
}

void left_wheel(bool forward, uint16_t velocity, uint32_t steps) {
	GPIO_AnalogWrite(GPIOB, GPIO_Pin_4, velocity); // bth commented
	counter = 0;
	GPIO_DigitalWrite(GPIOA, GPIO_Pin_3, HIGH); // bth moved outside of the loop - no idea why it is in there.
	GPIO_DigitalWrite(GPIOA, GPIO_Pin_8, HIGH); // bth moved outside of the loop - no idea why it is in there.
	while (counter < steps) {
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
	GPIO_DigitalWrite(GPIOA, GPIO_Pin_3, LOW);  //bth added
	GPIO_DigitalWrite(GPIOA, GPIO_Pin_8, LOW);  //bth added
}

void main(int argc, char* argv[]) {
	setup();

	while (1) {
		left_wheel(true, 50, 5);
		//left_wheel(true, 50, 100);
		delay();
		//left_wheel(false, 100, 10);
		left_wheel(false, 100, 5);
	}
}

#pragma GCC diagnostic pop
