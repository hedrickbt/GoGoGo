#include "WheelEncoder.h"

volatile uint32_t left_wheel_counter = 0;
volatile uint32_t right_wheel_counter = 0;
volatile bool is_stopped = true;


bool WheelEncoder_IsStepping(uint32_t current_step, uint32_t steps){
	return current_step < steps;
}

bool WheelEncoder_GetIsStopped(void){
	return is_stopped;
}

void WheelEncoder_SetIsStopped(bool value){
	is_stopped = value;
}

uint32_t WheelEncoder_GetLeftWheelCounter(void) {
	return left_wheel_counter;
}

void WheelEncoder_SetLeftWheelCounter(uint32_t value) {
	left_wheel_counter = value;
}

uint32_t WheelEncoder_GetRightWheelCounter(void) {
	return right_wheel_counter;
}

void WheelEncoder_SetRightWheelCounter(uint32_t value) {
	right_wheel_counter = value;
}

