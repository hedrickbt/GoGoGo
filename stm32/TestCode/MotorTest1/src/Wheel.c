#include "Wheel.h"


static volatile uint32_t left_wheel_counter = 0;
static volatile uint32_t right_wheel_counter = 0;
static volatile bool is_stopped = true;

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
		left_wheel_counter++;
	}
	if ((EXTI->PR & EXTI_PR_PR8) != (uint32_t)0) {
		EXTI->PR = EXTI_PR_PR8;
		//trace_print("pulse");
		right_wheel_counter++;
	}
	if ((EXTI->PR & EXTI_PR_PR13) != (uint32_t)0) {
		EXTI->PR = EXTI_PR_PR13;
		//trace_print("pulse");
		is_stopped = !is_stopped;
	}
	NVIC_ClearPendingIRQ(EXTI4_15_IRQn);
}


void Wheel_TurnLeftWheel(bool forward, uint16_t velocity, uint32_t steps) {
	if (is_stopped) return;

	GPIO_AnalogWrite(GPIOB, GPIO_Pin_4, velocity); // bth commented
	left_wheel_counter = 0;
	//GPIO_DigitalWrite(GPIOA, GPIO_Pin_8, HIGH); // bth moved outside of the loop - no idea why it is in there.
	GPIO_DigitalWrite(GPIOB, GPIO_Pin_5, HIGH); // bth moved outside of the loop - no idea why it is in there.
	while (left_wheel_counter < steps) {
		if (is_stopped) break;
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
	if (is_stopped) return;

	GPIO_AnalogWrite(GPIOB, GPIO_Pin_1, velocity); // bth commented
	right_wheel_counter = 0;
	//GPIO_DigitalWrite(GPIOA, GPIO_Pin_8, HIGH); // bth moved outside of the loop - no idea why it is in there.
	GPIO_DigitalWrite(GPIOB, GPIO_Pin_15, HIGH); // bth moved outside of the loop - no idea why it is in there.
	while (right_wheel_counter < steps) {
		if (is_stopped) break;
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


