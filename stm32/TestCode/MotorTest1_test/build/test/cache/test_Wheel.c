#include "cmsis_device.h"
#include "mock_WheelEncoder.h"
#include "mock_GPIO_conf.h"
#include "mock_GPIO.h"
#include "Wheel.h"
#include "fff.h"
#include "unity.h"














extern uint32_t left_wheel_counter;

extern uint32_t right_wheel_counter;

extern _Bool is_stopped;





void setUp(void) {

    is_stopped = 0;

    { WheelEncoder_IsStepping_reset(); };

    fff.call_history_idx = 0;;

}



void test_whenWheelsAreInitialized_thenWeSetTheCorrectPins() {

    Wheel_Initialize();



    if ((0 < GPIO_conf_OutputPin_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(28)));};

}



void test_whenWheelIsGoForward_thenWeSetTheCorrectDirectionPinsForLeftWheel() {

    _Bool counterReturnValues[4] = {1,1,1,0};

    WheelEncoder_IsStepping_fake.return_val_seq = counterReturnValues; WheelEncoder_IsStepping_fake.return_val_seq_len = 4;;



    Wheel_Straight(1, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(37)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(39)));};

    if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(40)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(41)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(43)));};

    if ((((uint16_t)0x0008) == GPIO_DigitalWrite_fake.arg1_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(44)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(45)));};

}



void test_whenWheelIsGoForward_thenWeSetTheCorrectEnablePinForLeftWheel() {

    Wheel_Straight(1, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(51)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(52)));};

    if ((((uint16_t)0x0020) == GPIO_DigitalWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(53)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(54)));};

}



void test_whenWheelIsGoForward_thenWeSetTheVelocityForLeftWheel() {

    uint16_t velocity = 100;

    Wheel_Straight(1, velocity, 6);



    if ((1 <= GPIO_AnalogWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(61)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_AnalogWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(62)));};

    if ((((uint16_t)0x0010) == GPIO_AnalogWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(63)));};

    if ((velocity == GPIO_AnalogWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(64)));};

}



void test_whenWheelIsGoForward_thenWeSetTheCorrectDirectionPinsForRightWheel() {

    _Bool counterReturnValues[5] = {1,1,1,1,0};

    WheelEncoder_IsStepping_fake.return_val_seq = counterReturnValues; WheelEncoder_IsStepping_fake.return_val_seq_len = 5;;



    Wheel_Straight(1, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(73)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(75)));};

    if ((((uint16_t)0x4000) == GPIO_DigitalWrite_fake.arg1_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(76)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(77)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(79)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(80)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(81)));};

}



void test_whenWheelIsGoForward_thenWeSetTheCorrectEnablePinForRightWheel() {

    is_stopped = 0;

    { WheelEncoder_IsStepping_reset(); };

    _Bool counterReturnValues[2] = {1,0};

    WheelEncoder_IsStepping_fake.return_val_seq = counterReturnValues; WheelEncoder_IsStepping_fake.return_val_seq_len = 2;;



    Wheel_Straight(1, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(92)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(93)));};

    if ((((uint16_t)0x8000) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(94)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(95)));};

}



void test_whenWheelIsGoForward_thenWeSetTheVelocityForRightWheel() {

    uint16_t velocity = 100;

    Wheel_Straight(1, velocity, 6);



    if ((1 <= GPIO_AnalogWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(102)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_AnalogWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(103)));};

    if ((((uint16_t)0x0002) == GPIO_AnalogWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(104)));};

    if ((velocity == GPIO_AnalogWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(105)));};

}



void test_whenWheelIsGoBackward_thenWeSetTheCorrectDirectionPinsForLeftWheel() {

    _Bool counterReturnValues[4] = {1,1,1,0};

    WheelEncoder_IsStepping_fake.return_val_seq = counterReturnValues; WheelEncoder_IsStepping_fake.return_val_seq_len = 4;;



    Wheel_Straight(0, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(114)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(116)));};

    if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(117)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(118)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(120)));};

    if ((((uint16_t)0x0008) == GPIO_DigitalWrite_fake.arg1_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(121)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(122)));};

}



void test_whenWheelIsGoBackward_thenWeSetTheCorrectDirectionPinsForRightWheel() {

    _Bool counterReturnValues[5] = {1,1,1,1,0};

    WheelEncoder_IsStepping_fake.return_val_seq = counterReturnValues; WheelEncoder_IsStepping_fake.return_val_seq_len = 5;;



    Wheel_Straight(0, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(131)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(133)));};

    if ((((uint16_t)0x4000) == GPIO_DigitalWrite_fake.arg1_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(134)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(135)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(137)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(138)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(139)));};

}



void test_whenWheelsGoStraight_thenWeInitializeTheWheelStepCounters() {

    Wheel_Straight(1, 100, 6);



    if ((0 == left_wheel_counter)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(145)));};

    if ((0 == right_wheel_counter)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(146)));};

}



void test_whenWheelsGoStraight_thenWeExitIfIsStopped() {

    is_stopped = 1;

    Wheel_Straight(1, 100, 6);



    if ((0 == GPIO_AnalogWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(153)));};

}



void test_whenWheelsGoStraight_thenWeExitIfIsStoppedInStepLoop() {



    Wheel_Straight(1, 100, 6);



    if ((3 > GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(160)));};

}
