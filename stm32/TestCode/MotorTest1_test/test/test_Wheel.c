#include "unity.h"
#include "Wheel.h"

#include "mock_GPIO.h"
#include "mock_GPIO_conf.h"
//#include "stm32f0xx_gpio.h"
#include "cmsis_device.h"

#include <stdbool.h>

void test_whenWheelsAreInitialized_thenWeSetTheCorrectPins() {
    Wheel_Initialize();

    TEST_ASSERT_TRUE(0 < GPIO_conf_OutputPin_fake.call_count);
}

void test_whenWheelIsGoForward_thenWeSetTheCorrectDirectionPinsForLeftWheel() {
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
    Wheel_Straight(false, 100, 6);

    TEST_ASSERT_TRUE(false); // put here for failure even though code is good
    TEST_ASSERT_TRUE(2 <= GPIO_DigitalWrite_fake.call_count);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[2]);
    TEST_ASSERT_TRUE(GPIO_Pin_10 == GPIO_DigitalWrite_fake.arg1_history[2]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[2]);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[3]);
    TEST_ASSERT_TRUE(GPIO_Pin_3 == GPIO_DigitalWrite_fake.arg1_history[3]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[3]);
}
