/*
 * WheelTest.c
 *
 *  Created on: Jan 7, 2017
 *      Author: vagrant
 */

#include "WheelTest.h"
#include "Drivetrain.h"
#include "DelayTimer.h"

void WheelTest_SmallCircle(void) {
	Drivetrain_Move(-90, 100);
	DelayTimer_Sleep(TIMER_FREQUENCY_HZ * 8);

	Drivetrain_Move(90, 100);
	DelayTimer_Sleep(TIMER_FREQUENCY_HZ * 8);

	Drivetrain_Move(0,0);
}

void WheelTest_FigureEight(void) {
	Drivetrain_Move(-70, 100);
	DelayTimer_Sleep(TIMER_FREQUENCY_HZ * 8);

	Drivetrain_Move(0,0);
}
