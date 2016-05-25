#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "GPIO_conf.h"
#include "cmsis_device.h"

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

void setup(void) {
	GPIO_conf_OutputPin(GPIOA, GPIO_Pin_3); 		// standby
	GPIO_conf_InputPin(GPIOA, GPIO_Pin_10); 		// decoder
	GPIO_conf_PwmPin(GPIOB, GPIO_Pin_4); 			// pwm
	GPIO_conf_OutputPin(GPIOB, GPIO_Pin_10); 		// in1
	GPIO_conf_OutputPin(GPIOA, GPIO_Pin_9); 		// in2
	GPIO_conf_InterruptPin(GPIOA, GPIO_Pin_10);  	// decoder interrupt
}


void main(int argc, char* argv[]) {
	while (1) {
		// Add your code here.
	}
}

#pragma GCC diagnostic pop
