#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "Wheel.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

void delay(void);

void delay(void){
	uint32_t i = 1234567890;
	while (i > 0) {
		i--;
	}
}

void main(int argc, char* argv[]) {
	Wheel_Initialize();

	while (1) {
		Wheel_TurnLeftWheel(true, 50, 100);
		//left_wheel(true, 50, 100);
		//delay();
		//left_wheel(false, 100, 10);
		//left_wheel(false, 100, 5);

		//delay();

		Wheel_TurnRightWheel(true, 50, 100);
		//left_wheel(true, 50, 100);
		delay();
		//left_wheel(false, 100, 10);
		//right_wheel(false, 100, 5);
	}
}

#pragma GCC diagnostic pop
