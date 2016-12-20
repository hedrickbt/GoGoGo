#include "cmsis_device.h"
#include "mock_GPIO_conf.h"
#include "mock_GPIO.h"
#include "Wheel.h"
#include "unity.h"












void test_whenWheelsAreInitialized_thenWeSetTheCorrectPins() {

    Wheel_Initialize();



    if ((0 < GPIO_conf_OutputPin_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(14)));};

}



void test_whenWheelIsGoForward_thenWeSetTheCorrectDirectionPinsForLeftWheel() {

    Wheel_Straight(1, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(20)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(22)));};

    if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(23)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(24)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(26)));};

    if ((((uint16_t)0x0008) == GPIO_DigitalWrite_fake.arg1_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(27)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(28)));};

}



void test_whenWheelIsGoForward_thenWeSetTheCorrectEnablePinForLeftWheel() {

    Wheel_Straight(1, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(34)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(35)));};

    if ((((uint16_t)0x0020) == GPIO_DigitalWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(36)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(37)));};

}



void test_whenWheelIsGoForward_thenWeSetTheVelocityForLeftWheel() {

    uint16_t velocity = 100;

    Wheel_Straight(1, velocity, 6);



    if ((1 <= GPIO_AnalogWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(44)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_AnalogWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(45)));};

    if ((((uint16_t)0x0010) == GPIO_AnalogWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(46)));};

    if ((velocity == GPIO_AnalogWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(47)));};

}



void test_whenWheelIsGoForward_thenWeSetTheCorrectDirectionPinsForRightWheel() {

    Wheel_Straight(1, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(53)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(55)));};

    if ((((uint16_t)0x4000) == GPIO_DigitalWrite_fake.arg1_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(56)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(57)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(59)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(60)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(61)));};

}



void test_whenWheelIsGoForward_thenWeSetTheCorrectEnablePinForRightWheel() {

    Wheel_Straight(1, 100, 6);



    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(67)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(68)));};

    if ((((uint16_t)0x8000) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(69)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(70)));};

}



void test_whenWheelIsGoForward_thenWeSetTheVelocityForRightWheel() {

    uint16_t velocity = 100;

    Wheel_Straight(1, velocity, 6);



    if ((1 <= GPIO_AnalogWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(77)));};

    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_AnalogWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(78)));};

    if ((((uint16_t)0x0002) == GPIO_AnalogWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(79)));};

    if ((velocity == GPIO_AnalogWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(80)));};

}



void test_whenWheelIsGoBackward_thenWeSetTheCorrectDirectionPinsForLeftWheel() {

    Wheel_Straight(0, 100, 6);



    if ((0)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(86)));};

    if ((2 <= GPIO_DigitalWrite_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(87)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(89)));};

    if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(90)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(91)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(93)));};

    if ((((uint16_t)0x0008) == GPIO_DigitalWrite_fake.arg1_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(94)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(95)));};

}
