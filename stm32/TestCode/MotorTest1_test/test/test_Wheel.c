#include "unity.h"
#include "fff.h"
#include "Wheel.h"
#include <stdint.h>
#include <stdbool.h>

#include "mock_GPIO.h"
#include "mock_GPIO_conf.h"
#include "mock_WheelEncoder.h"
//#include "stm32f0xx_gpio.h"
#include "cmsis_device.h"


void setUp(void) {
    RESET_FAKE(WheelEncoder_IsStepping);
    RESET_FAKE(WheelEncoder_GetIsStopped);
    RESET_FAKE(WheelEncoder_SetIsStopped);
    RESET_FAKE(WheelEncoder_SetLeftWheelCounter);
    RESET_FAKE(WheelEncoder_GetLeftWheelCounter);
    RESET_FAKE(WheelEncoder_SetRightWheelCounter);
    RESET_FAKE(WheelEncoder_GetRightWheelCounter);
    //RESET_FAKE(Wheel_StopLeftWheel);
    //RESET_FAKE(Wheel_StopRightWheel);
    FFF_RESET_HISTORY();
}

void test_whenWheelsAreInitialized_thenWeSetTheCorrectPins() {
    Wheel_Initialize();

    TEST_ASSERT_TRUE(0 < GPIO_conf_OutputPin_fake.call_count);
}



void test_whenLeftWheelGoesForward_thenWeSetTheCorrectDirectionPins() {
    //bool counterReturnValues[4] = {true,true,true,false};
    //SET_RETURN_SEQ(WheelEncoder_IsStepping, counterReturnValues, 4);

    //Wheel_Straight(true, 100, 6);
    Wheel_TurnLeftWheel(true, 100);

    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[1]);
    TEST_ASSERT_TRUE(GPIO_Pin_10 == GPIO_DigitalWrite_fake.arg1_history[1]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[1]);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[2]);
    TEST_ASSERT_TRUE(GPIO_Pin_3 == GPIO_DigitalWrite_fake.arg1_history[2]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[2]);
}

void test_whenLeftWheelGoesForward_thenWeSetTheCorrectEnablePin() {
    //Wheel_Straight(true, 100, 6);
    Wheel_TurnLeftWheel(true, 100);

    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);
    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[0]);
    TEST_ASSERT_TRUE(GPIO_Pin_5 == GPIO_DigitalWrite_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[0]);
}

void test_whenLeftWheelGoesForward_thenWeSetTheVelocity() {
    uint16_t velocity = 100;
    //Wheel_Straight(true, velocity, 6);
    Wheel_TurnLeftWheel(true, velocity);

    TEST_ASSERT_TRUE(1 <= GPIO_AnalogWrite_fake.call_count);
    TEST_ASSERT_TRUE(GPIOB == GPIO_AnalogWrite_fake.arg0_history[0]);
    TEST_ASSERT_TRUE(GPIO_Pin_4 == GPIO_AnalogWrite_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(velocity == GPIO_AnalogWrite_fake.arg2_history[0]);
}

void test_whenRightWheelGoesForward_thenWeSetTheCorrectDirectionPins() {
    //bool counterReturnValues[5] = {true,true,true,true,false};
    //SET_RETURN_SEQ(WheelEncoder_IsStepping, counterReturnValues, 5);

    //Wheel_Straight(true, 100, 6);
    Wheel_TurnRightWheel(true, 100);

    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[1]);
    TEST_ASSERT_TRUE(GPIO_Pin_14 == GPIO_DigitalWrite_fake.arg1_history[1]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[1]);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[2]);
    TEST_ASSERT_TRUE(GPIO_Pin_13 == GPIO_DigitalWrite_fake.arg1_history[2]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[2]);
}

void test_whenRightWheelGoesForward_thenWeSetTheCorrectEnablePin() {
    //RESET_FAKE(WheelEncoder_IsStepping);
    //bool counterReturnValues[2] = {true,false};
    //SET_RETURN_SEQ(WheelEncoder_IsStepping, counterReturnValues, 2);

    //Wheel_Straight(true, 100, 6);
    Wheel_TurnRightWheel(true, 100);

    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);
    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[0]);
    TEST_ASSERT_TRUE(GPIO_Pin_15 == GPIO_DigitalWrite_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[0]);
}

void test_whenRigtWheelIsGoesForward_thenWeSetTheVelocity() {
    uint16_t velocity = 100;
    //Wheel_Straight(true, velocity, 6);
    Wheel_TurnRightWheel(true, velocity);

    TEST_ASSERT_TRUE(1 <= GPIO_AnalogWrite_fake.call_count);
    TEST_ASSERT_TRUE(GPIOB == GPIO_AnalogWrite_fake.arg0_history[0]);
    TEST_ASSERT_TRUE(GPIO_Pin_1 == GPIO_AnalogWrite_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(velocity == GPIO_AnalogWrite_fake.arg2_history[0]);
}




void test_whenLeftWheelGoesBackward_thenWeSetTheCorrectDirectionPins() {
    //bool counterReturnValues[4] = {true,true,true,false};
    //SET_RETURN_SEQ(WheelEncoder_IsStepping, counterReturnValues, 4);

    //Wheel_Straight(false, 100, 6);
    Wheel_TurnLeftWheel(false, 100);

    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[1]);
    TEST_ASSERT_TRUE(GPIO_Pin_10 == GPIO_DigitalWrite_fake.arg1_history[1]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[1]);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[2]);
    TEST_ASSERT_TRUE(GPIO_Pin_3 == GPIO_DigitalWrite_fake.arg1_history[2]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[2]);
}

void test_whenRightWheelGoesBackward_thenWeSetTheCorrectDirectionPins() {
    //bool counterReturnValues[5] = {true,true,true,true,false};
    //SET_RETURN_SEQ(WheelEncoder_IsStepping, counterReturnValues, 5);

    //Wheel_Straight(false, 100, 6);
    Wheel_TurnRightWheel(false, 100);

    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[1]);
    TEST_ASSERT_TRUE(GPIO_Pin_14 == GPIO_DigitalWrite_fake.arg1_history[1]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[1]);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[2]);
    TEST_ASSERT_TRUE(GPIO_Pin_13 == GPIO_DigitalWrite_fake.arg1_history[2]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[2]);
}

void test_whenWheelsGoStraight_thenWeInitializeTheWheelStepCounters() {
    Wheel_Straight(true, 100);

    TEST_ASSERT_TRUE(0 == WheelEncoder_SetLeftWheelCounter_fake.arg0_history[0]);
    TEST_ASSERT_TRUE(0 == WheelEncoder_SetRightWheelCounter_fake.arg0_history[0]);
}

void test_whenWheelsGoStraight_thenWeExitIfIsStopped() {
    WheelEncoder_GetIsStopped_fake.return_val = true;
    Wheel_Straight(true, 100);

    TEST_ASSERT_EQUAL_UINT(2, GPIO_AnalogWrite_fake.call_count);
}





void test_WhenLeftWheelStops_thenWeSetVelocityToZero() {
    Wheel_StopLeftWheel();

    TEST_ASSERT_TRUE(GPIOB == GPIO_AnalogWrite_fake.arg0_history[0]);
    TEST_ASSERT_TRUE(GPIO_Pin_4 == GPIO_AnalogWrite_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(0 == GPIO_AnalogWrite_fake.arg2_history[0]);
}

void test_WhenLeftWheelStops_thenWeSetPin1ToLow() {
    Wheel_StopLeftWheel();

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[0]);
    TEST_ASSERT_TRUE(GPIO_Pin_10 == GPIO_DigitalWrite_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[0]);
}

void test_WhenLeftWheelStops_thenWeSetPin2ToLow() {
    Wheel_StopLeftWheel();

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[1]);
    TEST_ASSERT_TRUE(GPIO_Pin_3 == GPIO_DigitalWrite_fake.arg1_history[1]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[1]);
}

void test_WhenLeftWheelStops_thenWeSetPinStandbyToLow() {
    Wheel_StopLeftWheel();

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[2]);
    TEST_ASSERT_TRUE(GPIO_Pin_5 == GPIO_DigitalWrite_fake.arg1_history[2]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[2]);
}











void test_WhenRightWheelStops_thenWeSetVelocityToZero() {
    Wheel_StopRightWheel();

    TEST_ASSERT_TRUE(GPIOB == GPIO_AnalogWrite_fake.arg0_history[0]);
    TEST_ASSERT_TRUE(GPIO_Pin_1 == GPIO_AnalogWrite_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(0 == GPIO_AnalogWrite_fake.arg2_history[0]);
}

void test_WhenRightWheelStops_thenWeSetPin1ToLow() {
    Wheel_StopRightWheel();

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[0]);
    TEST_ASSERT_TRUE(GPIO_Pin_14 == GPIO_DigitalWrite_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[0]);
}

void test_WhenRightWheelStops_thenWeSetPin2ToLow() {
    Wheel_StopRightWheel();

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[1]);
    TEST_ASSERT_TRUE(GPIO_Pin_13 == GPIO_DigitalWrite_fake.arg1_history[1]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[1]);
}

void test_WhenRightWheelStops_thenWeSetPinStandbyToLow() {
    Wheel_StopRightWheel();

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[2]);
    TEST_ASSERT_TRUE(GPIO_Pin_15 == GPIO_DigitalWrite_fake.arg1_history[2]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[2]);
}
