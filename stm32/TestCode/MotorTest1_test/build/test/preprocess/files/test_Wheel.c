#include "cmsis_device.h"
#include "mock_WheelEncoder.h"
#include "mock_GPIO_conf.h"
#include "mock_GPIO.h"
#include "Wheel.h"
#include "fff.h"
#include "unity.h"














void setUp(void) {

    { WheelEncoder_IsStepping_reset(); };

    { WheelEncoder_GetIsStopped_reset(); };

    { WheelEncoder_SetIsStopped_reset(); };

    { WheelEncoder_SetLeftWheelCounter_reset(); };

    { WheelEncoder_GetLeftWheelCounter_reset(); };

    { WheelEncoder_SetRightWheelCounter_reset(); };

    { WheelEncoder_GetRightWheelCounter_reset(); };

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

    { WheelEncoder_IsStepping_reset(); };

    _Bool counterReturnValues[2] = {1,0};

    WheelEncoder_IsStepping_fake.return_val_seq = counterReturnValues; WheelEncoder_IsStepping_fake.return_val_seq_len = 2;;



    Wheel_Straight(1, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(91)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(92)));};

    if ((((uint16_t)0x8000) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(93)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(94)));};

}



void test_whenWheelIsGoForward_thenWeSetTheVelocityForRightWheel() {

    uint16_t velocity = 100;

    Wheel_Straight(1, velocity, 6);



    if ((1 <= GPIO_AnalogWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(101)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_AnalogWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(102)));};

    if ((((uint16_t)0x0002) == GPIO_AnalogWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(103)));};

    if ((velocity == GPIO_AnalogWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(104)));};

}



void test_whenWheelIsGoBackward_thenWeSetTheCorrectDirectionPinsForLeftWheel() {

    _Bool counterReturnValues[4] = {1,1,1,0};

    WheelEncoder_IsStepping_fake.return_val_seq = counterReturnValues; WheelEncoder_IsStepping_fake.return_val_seq_len = 4;;



    Wheel_Straight(0, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(113)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(115)));};

    if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(116)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(117)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(119)));};

    if ((((uint16_t)0x0008) == GPIO_DigitalWrite_fake.arg1_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(120)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(121)));};

}



void test_whenWheelIsGoBackward_thenWeSetTheCorrectDirectionPinsForRightWheel() {

    _Bool counterReturnValues[5] = {1,1,1,1,0};

    WheelEncoder_IsStepping_fake.return_val_seq = counterReturnValues; WheelEncoder_IsStepping_fake.return_val_seq_len = 5;;



    Wheel_Straight(0, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(130)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(132)));};

    if ((((uint16_t)0x4000) == GPIO_DigitalWrite_fake.arg1_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(133)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(134)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(136)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(137)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(138)));};

}



void test_whenWheelsGoStraight_thenWeInitializeTheWheelStepCounters() {

    Wheel_Straight(1, 100, 6);



    if ((0 == WheelEncoder_SetLeftWheelCounter_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(144)));};

    if ((0 == WheelEncoder_SetRightWheelCounter_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(145)));};

}



void test_whenWheelsGoStraight_thenWeExitIfIsStopped() {

    WheelEncoder_GetIsStopped_fake.return_val = 1;

    Wheel_Straight(1, 100, 6);



    if ((0 == GPIO_AnalogWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(152)));};

}



void test_whenWheelsGoStraight_thenWeExitIfIsStoppedInStepLoop() {

    _Bool queuedReturnValues[2] = {0,1};

    WheelEncoder_GetIsStopped_fake.return_val_seq = queuedReturnValues; WheelEncoder_GetIsStopped_fake.return_val_seq_len = 2;;

    WheelEncoder_IsStepping_fake.return_val = 1;



    Wheel_Straight(1, 100, 6);





    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((GPIO_DigitalWrite_fake.call_count)), (((void *)0)), (UNITY_UINT)(163), UNITY_DISPLAY_STYLE_UINT);

}
