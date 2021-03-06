#include "Drivetrain.h"
#include "Wheel.h"
#include <assert.h>
//#include <stdio.h>
#include <stdlib.h>



volatile int8_t robot_direction = 0;
volatile int16_t robot_velocity = 0;

void Drivetrain_Initialize(void){
	Wheel_Initialize();
	Wheel_StopLeftWheel();
	Wheel_StopRightWheel();
	robot_direction = 0;
	robot_velocity = 0;
}

void Drivetrain_FullStop(void) {
	Wheel_StopLeftWheel();
	Wheel_StopRightWheel();
	robot_direction = 0;
	robot_velocity = 0;
}

int8_t Drivetrain_GetDirection(void) {
	return robot_direction;
}

int8_t Drivetrain_GetVelocity(void) {
	return robot_velocity;
}

/*
 * Velocity > 0 Forward
 * Velocity < 0 Reverse
 * Velocity = 0 Stop
 * Direction < 0 Left
 * Direction > 0 Right
 * Direction = 0 Straight
 */
void Drivetrain_Move(int8_t direction, int16_t velocity) {
	//printf("Drivetrain_Move: %d, %d \n", direction, velocity);

	if (direction < -90) {
		robot_direction = -90;
	} else if  (direction > 90) {
		robot_direction = 90;
	} else {
		robot_direction = direction;
	}

	if (velocity < -255) {
		robot_velocity = -255;
	} else if (velocity > 255) {
		robot_velocity = 255;
	} else {
		robot_velocity = velocity;
	}

	/*
	 * If direction =   0, LV=velocity,  RV=velocity  Straight
	 * If direction = -90, LV=0,         RV=velocity  Full Left
	 * If direction = -90, LV=velocity,  RV=0    	  Full Right
	 * Otherwise wheel velocity of turning wheel = (90-abs(direction))/direction * velocity
	 */

	if (robot_velocity > 0) {
		if (robot_direction > 0) {
			Wheel_TurnLeftWheel(true, robot_velocity);
			Wheel_TurnRightWheel(true, (int16_t)((90-abs(robot_direction))/90.0 * robot_velocity));
		} else if (robot_direction < 0) {
			Wheel_TurnLeftWheel(true, (int16_t)((90-abs(robot_direction))/90.0 * robot_velocity));
			Wheel_TurnRightWheel(true, robot_velocity);
		} else {
			Wheel_Straight(true, robot_velocity);
		}
	} else if (robot_velocity < 0) {
		if (robot_direction > 0) {
			Wheel_TurnRightWheel(false, abs(robot_velocity));
			Wheel_TurnLeftWheel(false, (int16_t)((90-abs(robot_direction))/90.0 * abs(robot_velocity)));
		} else if (robot_direction < 0) {
			Wheel_TurnRightWheel(false, (int16_t)((90-abs(robot_direction))/90.0 * abs(robot_velocity)));
			Wheel_TurnLeftWheel(false, abs(robot_velocity));
		} else {
			Wheel_Straight(false, abs(robot_velocity));
		}
	} else {
		Wheel_StopLeftWheel();
		Wheel_StopRightWheel();
	}
}
