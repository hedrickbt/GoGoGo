//#include <stdio.h>
//#include <stdlib.h>
//#include "diag/Trace.h"


#include "WheelTest.h"
#include "Drivetrain.h"
#include "DelayTimer.h"
#include "WheelEncoder.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"


void main(int argc, char* argv[]) {
	//Wheel_Initialize();
	DelayTimer_Initialize();
	Drivetrain_Initialize();

	while (1) {
		if (!WheelEncoder_GetIsStopped()) {
			DelayTimer_Sleep(TIMER_FREQUENCY_HZ * 2); //2 seconds

			WheelTest_StraightForward();
			DelayTimer_Sleep(TIMER_FREQUENCY_HZ * 8); //8 seconds

			WheelTest_StraightReverse();
			DelayTimer_Sleep(TIMER_FREQUENCY_HZ * 8); //8 seconds

			WheelTest_FigureEight();
			DelayTimer_Sleep(TIMER_FREQUENCY_HZ * 8); //8 seconds

			WheelTest_SmallCircle();
			DelayTimer_Sleep(TIMER_FREQUENCY_HZ * 8); //8 seconds

	//		Wheel_TurnLeftWheel(true, 50);
	//		//left_wheel(true, 50, 100);
	//		//delay();
	//		//left_wheel(false, 100, 10);
	//		//left_wheel(false, 100, 5);
	//
	//		//delay();

	//		Wheel_TurnRightWheel(true, 50);
	//		//left_wheel(true, 50, 100);
	//		delay();
	//		//left_wheel(false, 100, 10);
	//		//right_wheel(false, 100, 5);
		}
	}
}

#pragma GCC diagnostic pop
