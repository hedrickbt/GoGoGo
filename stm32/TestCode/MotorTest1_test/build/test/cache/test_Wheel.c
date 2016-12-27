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



    if ((0 < GPIO_conf_OutputPin_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(30)));};

}







void test_whenLeftWheelGoesForward_thenWeSetTheCorrectDirectionPins() {









    Wheel_TurnLeftWheel(1, 100);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(42)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(44)));};

    if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(45)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(46)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(48)));};

    if ((((uint16_t)0x0008) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(49)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(50)));};

}



void test_whenLeftWheelGoesForward_thenWeSetTheCorrectEnablePin() {



    Wheel_TurnLeftWheel(1, 100);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(57)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(58)));};

    if ((((uint16_t)0x0020) == GPIO_DigitalWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(59)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(60)));};

}



void test_whenLeftWheelGoesForward_thenWeSetTheVelocity() {

    uint16_t velocity = 100;



    Wheel_TurnLeftWheel(1, velocity);



    if ((1 <= GPIO_AnalogWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(68)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_AnalogWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(69)));};

    if ((((uint16_t)0x0010) == GPIO_AnalogWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(70)));};

    if ((velocity == GPIO_AnalogWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(71)));};

}



void test_whenRightWheelGoesForward_thenWeSetTheCorrectDirectionPins() {









    Wheel_TurnRightWheel(1, 100);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(81)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(83)));};

    if ((((uint16_t)0x4000) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(84)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(85)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(87)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(88)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(89)));};

}



void test_whenRightWheelGoesForward_thenWeSetTheCorrectEnablePin() {











    Wheel_TurnRightWheel(1, 100);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(100)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(101)));};

    if ((((uint16_t)0x8000) == GPIO_DigitalWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(102)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(103)));};

}



void test_whenRigtWheelIsGoesForward_thenWeSetTheVelocity() {

    uint16_t velocity = 100;



    Wheel_TurnRightWheel(1, velocity);



    if ((1 <= GPIO_AnalogWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(111)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_AnalogWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(112)));};

    if ((((uint16_t)0x0002) == GPIO_AnalogWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(113)));};

    if ((velocity == GPIO_AnalogWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(114)));};

}









void test_whenLeftWheelGoesBackward_thenWeSetTheCorrectDirectionPins() {









    Wheel_TurnLeftWheel(0, 100);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(127)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(129)));};

    if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(130)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(131)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(133)));};

    if ((((uint16_t)0x0008) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(134)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(135)));};

}



void test_whenRightWheelGoesBackward_thenWeSetTheCorrectDirectionPins() {









    Wheel_TurnRightWheel(0, 100);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(145)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(147)));};

    if ((((uint16_t)0x4000) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(148)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(149)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(151)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(152)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(153)));};

}



void test_whenWheelsGoStraight_thenWeInitializeTheWheelStepCounters() {

    Wheel_Straight(1, 100);



    if ((0 == WheelEncoder_SetLeftWheelCounter_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(159)));};

    if ((0 == WheelEncoder_SetRightWheelCounter_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(160)));};

}



void test_whenWheelsGoStraight_thenWeExitIfIsStopped() {

    WheelEncoder_GetIsStopped_fake.return_val = 1;

    Wheel_Straight(1, 100);



    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((GPIO_AnalogWrite_fake.call_count)), (((void *)0)), (UNITY_UINT)(167), UNITY_DISPLAY_STYLE_UINT);

}











void test_WhenLeftWheelStops_thenWeSetVelocityToZero() {

    Wheel_StopLeftWheel();



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_AnalogWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(177)));};

    if ((((uint16_t)0x0010) == GPIO_AnalogWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(178)));};

    if ((0 == GPIO_AnalogWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(179)));};

}



void test_WhenLeftWheelStops_thenWeSetPin1ToLow() {

    Wheel_StopLeftWheel();



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(185)));};

    if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(186)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(187)));};

}



void test_WhenLeftWheelStops_thenWeSetPin2ToLow() {

    Wheel_StopLeftWheel();



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(193)));};

    if ((((uint16_t)0x0008) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(194)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(195)));};

}



void test_WhenLeftWheelStops_thenWeSetPinStandbyToLow() {

    Wheel_StopLeftWheel();



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(201)));};

    if ((((uint16_t)0x0020) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(202)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(203)));};

}

void test_WhenRightWheelStops_thenWeSetVelocityToZero() {

    Wheel_StopRightWheel();



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_AnalogWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(219)));};

    if ((((uint16_t)0x0002) == GPIO_AnalogWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(220)));};

    if ((0 == GPIO_AnalogWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(221)));};

}



void test_WhenRightWheelStops_thenWeSetPin1ToLow() {

    Wheel_StopRightWheel();



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(227)));};

    if ((((uint16_t)0x4000) == GPIO_DigitalWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(228)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(229)));};

}



void test_WhenRightWheelStops_thenWeSetPin2ToLow() {

    Wheel_StopRightWheel();



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(235)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(236)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(237)));};

}



void test_WhenRightWheelStops_thenWeSetPinStandbyToLow() {

    Wheel_StopRightWheel();



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(243)));};

    if ((((uint16_t)0x8000) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(244)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(245)));};

}
