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


extern uint32_t left_wheel_counter;
extern uint32_t right_wheel_counter;
extern bool is_stopped;


void setUp(void) {
    is_stopped = false;
    RESET_FAKE(WheelEncoder_IsStepping);
    FFF_RESET_HISTORY();
}

void test_whenWheelsAreInitialized_thenWeSetTheCorrectPins() {
    Wheel_Initialize();

    TEST_ASSERT_TRUE(0 < GPIO_conf_OutputPin_fake.call_count);
}

void test_whenWheelIsGoForward_thenWeSetTheCorrectDirectionPinsForLeftWheel() {
    bool counterReturnValues[4] = {true,true,true,false};
    SET_RETURN_SEQ(WheelEncoder_IsStepping, counterReturnValues, 4);

    Wheel_Straight(true, 100, 6);

    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[2]);
    TEST_ASSERT_TRUE(GPIO_Pin_10 == GPIO_DigitalWrite_fake.arg1_history[2]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[2]);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[3]);
    TEST_ASSERT_TRUE(GPIO_Pin_3 == GPIO_DigitalWrite_fake.arg1_history[3]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[3]);
}

void test_whenWheelIsGoForward_thenWeSetTheCorrectEnablePinForLeftWheel() {
    Wheel_Straight(true, 100, 6);

    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);
    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[0]);
    TEST_ASSERT_TRUE(GPIO_Pin_5 == GPIO_DigitalWrite_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[0]);
}

void test_whenWheelIsGoForward_thenWeSetTheVelocityForLeftWheel() {
    uint16_t velocity = 100;
    Wheel_Straight(true, velocity, 6);

    TEST_ASSERT_TRUE(1 <= GPIO_AnalogWrite_fake.call_count);
    TEST_ASSERT_TRUE(GPIOB == GPIO_AnalogWrite_fake.arg0_history[0]);
    TEST_ASSERT_TRUE(GPIO_Pin_4 == GPIO_AnalogWrite_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(velocity == GPIO_AnalogWrite_fake.arg2_history[0]);
}

void test_whenWheelIsGoForward_thenWeSetTheCorrectDirectionPinsForRightWheel() {
    bool counterReturnValues[5] = {true,true,true,true,false};
    SET_RETURN_SEQ(WheelEncoder_IsStepping, counterReturnValues, 5);

    Wheel_Straight(true, 100, 6);

    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[4]);
    TEST_ASSERT_TRUE(GPIO_Pin_14 == GPIO_DigitalWrite_fake.arg1_history[4]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[4]);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[5]);
    TEST_ASSERT_TRUE(GPIO_Pin_13 == GPIO_DigitalWrite_fake.arg1_history[5]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[5]);
}

void test_whenWheelIsGoForward_thenWeSetTheCorrectEnablePinForRightWheel() {
    is_stopped = false;
    RESET_FAKE(WheelEncoder_IsStepping);
    bool counterReturnValues[2] = {true,false};
    SET_RETURN_SEQ(WheelEncoder_IsStepping, counterReturnValues, 2);

    Wheel_Straight(true, 100, 6);

    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);
    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[1]);
    TEST_ASSERT_TRUE(GPIO_Pin_15 == GPIO_DigitalWrite_fake.arg1_history[1]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[1]);
}

void test_whenWheelIsGoForward_thenWeSetTheVelocityForRightWheel() {
    uint16_t velocity = 100;
    Wheel_Straight(true, velocity, 6);

    TEST_ASSERT_TRUE(1 <= GPIO_AnalogWrite_fake.call_count);
    TEST_ASSERT_TRUE(GPIOB == GPIO_AnalogWrite_fake.arg0_history[1]);
    TEST_ASSERT_TRUE(GPIO_Pin_1 == GPIO_AnalogWrite_fake.arg1_history[1]);
    TEST_ASSERT_TRUE(velocity == GPIO_AnalogWrite_fake.arg2_history[1]);
}

void test_whenWheelIsGoBackward_thenWeSetTheCorrectDirectionPinsForLeftWheel() {
    bool counterReturnValues[4] = {true,true,true,false};
    SET_RETURN_SEQ(WheelEncoder_IsStepping, counterReturnValues, 4);

    Wheel_Straight(false, 100, 6);

    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[2]);
    TEST_ASSERT_TRUE(GPIO_Pin_10 == GPIO_DigitalWrite_fake.arg1_history[2]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[2]);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[3]);
    TEST_ASSERT_TRUE(GPIO_Pin_3 == GPIO_DigitalWrite_fake.arg1_history[3]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[3]);
}

void test_whenWheelIsGoBackward_thenWeSetTheCorrectDirectionPinsForRightWheel() {
    bool counterReturnValues[5] = {true,true,true,true,false};
    SET_RETURN_SEQ(WheelEncoder_IsStepping, counterReturnValues, 5);

    Wheel_Straight(false, 100, 6);

    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[4]);
    TEST_ASSERT_TRUE(GPIO_Pin_14 == GPIO_DigitalWrite_fake.arg1_history[4]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[4]);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[5]);
    TEST_ASSERT_TRUE(GPIO_Pin_13 == GPIO_DigitalWrite_fake.arg1_history[5]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[5]);
}

void test_whenWheelsGoStraight_thenWeInitializeTheWheelStepCounters() {
    Wheel_Straight(true, 100, 6);

    TEST_ASSERT_TRUE(0 == left_wheel_counter);
    TEST_ASSERT_TRUE(0 == right_wheel_counter);
}

void test_whenWheelsGoStraight_thenWeExitIfIsStopped() {
    is_stopped = true;
    Wheel_Straight(true, 100, 6);

    TEST_ASSERT_TRUE(0 == GPIO_AnalogWrite_fake.call_count);
}

void test_whenWheelsGoStraight_thenWeExitIfIsStoppedInStepLoop() {
//bth this test currently expected to fail
    Wheel_Straight(true, 100, 6);

    TEST_ASSERT_TRUE(3 > GPIO_DigitalWrite_fake.call_count);
}

