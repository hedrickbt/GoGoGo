#include "WheelEncoder.h"
#include "Wheel.h"
#include <stdio.h>



static void LeftWheel_Init(void);
static void RightWheel_Init(void);

void Wheel_Initialize(void) {
	// Left Wheel
	//GPIO_conf_OutputPin(GPIOA, GPIO_Pin_3); 						// standby
	//GPIO_conf_OutputPin(GPIOA, GPIO_Pin_8); 						// standby bth test
	GPIO_conf_OutputPin(GPIOB, GPIO_Pin_5); 						// standby
	GPIO_conf_OutputPin(GPIOB, GPIO_Pin_10); 						// in1
	GPIO_conf_OutputPin(GPIOB, GPIO_Pin_3); 						// in2
	GPIO_conf_InputPin(GPIOB, GPIO_Pin_9); 							// decoder
	GPIO_conf_PwmPin(GPIOB, GPIO_Pin_4, GPIO_PinSource4); 			// pwm
	GPIO_conf_InterruptPin(GPIOB, GPIO_Pin_9);  					// decoder interrupt

	// Right Wheel
	GPIO_conf_OutputPin(GPIOB, GPIO_Pin_15); 						// standby
	GPIO_conf_OutputPin(GPIOB, GPIO_Pin_14); 						// in1
	GPIO_conf_OutputPin(GPIOB, GPIO_Pin_13); 						// in2
	GPIO_conf_InputPin(GPIOB, GPIO_Pin_8); 							// decoder
	GPIO_conf_PwmPin(GPIOB, GPIO_Pin_1, GPIO_PinSource1); 			// pwm
	GPIO_conf_InterruptPin(GPIOB, GPIO_Pin_8);  					// decoder interrupt

	// Interface
	GPIO_conf_InputPin(GPIOC, GPIO_Pin_13); 						// start/stop button
	GPIO_conf_InterruptPin(GPIOC, GPIO_Pin_13);  					// start/stop button
}


void EXTI4_15_IRQHandler(void) {
	// we really shouldn't clear the pending IRQ until both checks have run
	if ((EXTI->PR & EXTI_PR_PR9) != (uint32_t)0) { // line 9 aka pin 9
		EXTI->PR = EXTI_PR_PR9;
		//trace_print("pulse");
		WheelEncoder_SetLeftWheelCounter(WheelEncoder_GetLeftWheelCounter()+1);
	}
	if ((EXTI->PR & EXTI_PR_PR8) != (uint32_t)0) {
		EXTI->PR = EXTI_PR_PR8;
		//trace_print("pulse");
		WheelEncoder_SetRightWheelCounter(WheelEncoder_GetRightWheelCounter()+1);
	}
	if ((EXTI->PR & EXTI_PR_PR13) != (uint32_t)0) {
		EXTI->PR = EXTI_PR_PR13;
		//trace_print("pulse");
		WheelEncoder_SetIsStopped(!WheelEncoder_GetIsStopped());
	}
	NVIC_ClearPendingIRQ(EXTI4_15_IRQn);
}

void Wheel_TurnLeftWheel(bool forward, uint16_t velocity, uint32_t steps) {
	if (WheelEncoder_GetIsStopped()) return;

	GPIO_AnalogWrite(GPIOB, GPIO_Pin_4, velocity); // bth commented
	WheelEncoder_SetLeftWheelCounter(0);
	//GPIO_DigitalWrite(GPIOA, GPIO_Pin_8, HIGH); // bth moved outside of the loop - no idea why it is in there.
	GPIO_DigitalWrite(GPIOB, GPIO_Pin_5, HIGH); // bth moved outside of the loop - no idea why it is in there.
	while (WheelEncoder_IsStepping(WheelEncoder_GetLeftWheelCounter(),steps)) {
		if (WheelEncoder_GetIsStopped()) break;
		if (forward) {
			GPIO_DigitalWrite(GPIOB, GPIO_Pin_10, HIGH);
			GPIO_DigitalWrite(GPIOB, GPIO_Pin_3, LOW);
		} else {
			GPIO_DigitalWrite(GPIOB, GPIO_Pin_10, LOW);
			GPIO_DigitalWrite(GPIOB, GPIO_Pin_3, HIGH);
		}
	}

	LeftWheel_Init();
}

void Wheel_TurnRightWheel(bool forward, uint16_t velocity, uint32_t steps) {
	if (WheelEncoder_GetIsStopped()) return;

	GPIO_AnalogWrite(GPIOB, GPIO_Pin_1, velocity); // bth commented
	WheelEncoder_SetRightWheelCounter(0);
	//GPIO_DigitalWrite(GPIOA, GPIO_Pin_8, HIGH); // bth moved outside of the loop - no idea why it is in there.
	GPIO_DigitalWrite(GPIOB, GPIO_Pin_15, HIGH); // bth moved outside of the loop - no idea why it is in there.
	while (WheelEncoder_IsStepping(WheelEncoder_GetRightWheelCounter(),steps)) {
		if (WheelEncoder_GetIsStopped()) break;
		if (forward) {
			GPIO_DigitalWrite(GPIOB, GPIO_Pin_14, HIGH);
			GPIO_DigitalWrite(GPIOB, GPIO_Pin_13, LOW);
		} else {
			GPIO_DigitalWrite(GPIOB, GPIO_Pin_14, LOW);
			GPIO_DigitalWrite(GPIOB, GPIO_Pin_13, HIGH);
		}
	}

	RightWheel_Init();
}

void Wheel_Straight(bool forward, uint16_t velocity, uint32_t steps) {
	printf("Wheel_Straight\n");
	if (WheelEncoder_GetIsStopped()) return;
	GPIO_AnalogWrite(GPIOB, GPIO_Pin_4, velocity); // bth commented
	GPIO_AnalogWrite(GPIOB, GPIO_Pin_1, velocity); // bth commented

	GPIO_DigitalWrite(GPIOB, GPIO_Pin_5, HIGH); // bth moved outside of the loop - no idea why it is in there.
	GPIO_DigitalWrite(GPIOB, GPIO_Pin_15, HIGH); // bth moved outside of the loop - no idea why it is in there.

	WheelEncoder_SetLeftWheelCounter(0);
	WheelEncoder_SetRightWheelCounter(0);

	while ((WheelEncoder_IsStepping(WheelEncoder_GetLeftWheelCounter(),steps)) &&  (WheelEncoder_IsStepping(WheelEncoder_GetRightWheelCounter(),steps))) {
		if (WheelEncoder_GetIsStopped()) return;
		printf("\tLoop\n");
		if (forward) {
			printf("\t\tForward\n");
			if (WheelEncoder_IsStepping(WheelEncoder_GetLeftWheelCounter(),steps)) {
				printf("\t\t\tGo Left\n");
				GPIO_DigitalWrite(GPIOB, GPIO_Pin_10, HIGH);
				GPIO_DigitalWrite(GPIOB, GPIO_Pin_3, LOW);
			} else {
				LeftWheel_Init();
			}

			if (WheelEncoder_IsStepping(WheelEncoder_GetRightWheelCounter(),steps)) {
				printf("\t\t\tGo Right\n");
				GPIO_DigitalWrite(GPIOB, GPIO_Pin_14, HIGH);
				GPIO_DigitalWrite(GPIOB, GPIO_Pin_13, LOW);
			} else {
				RightWheel_Init();
			}
		} else {
			printf("\t\tReverse\n");
			if (WheelEncoder_IsStepping(WheelEncoder_GetLeftWheelCounter(),steps)) {
				printf("\t\t\tGo Left\n");
				GPIO_DigitalWrite(GPIOB, GPIO_Pin_10, LOW);
				GPIO_DigitalWrite(GPIOB, GPIO_Pin_3, HIGH);
			} else {
				LeftWheel_Init();
			}

			if (WheelEncoder_IsStepping(WheelEncoder_GetRightWheelCounter(),steps)) {
				printf("\t\t\tGo Right\n");
				GPIO_DigitalWrite(GPIOB, GPIO_Pin_14, LOW);
				GPIO_DigitalWrite(GPIOB, GPIO_Pin_13, HIGH);
			} else {
				RightWheel_Init();
			}
		}
	}
	LeftWheel_Init();
	RightWheel_Init();
}


static void LeftWheel_Init(void) {
	GPIO_AnalogWrite(GPIOB, GPIO_Pin_4, 0);
	GPIO_DigitalWrite(GPIOB, GPIO_Pin_10, LOW); // was HIGH
	GPIO_DigitalWrite(GPIOB, GPIO_Pin_3, LOW); // was HIGH
	GPIO_DigitalWrite(GPIOB, GPIO_Pin_5, LOW);
}

static void RightWheel_Init(void) {
	GPIO_AnalogWrite(GPIOB, GPIO_Pin_1, 0);
	GPIO_DigitalWrite(GPIOB, GPIO_Pin_14, LOW); // was HIGH
	GPIO_DigitalWrite(GPIOB, GPIO_Pin_13, LOW); // was HIGH
	GPIO_DigitalWrite(GPIOB, GPIO_Pin_15, LOW);
}


