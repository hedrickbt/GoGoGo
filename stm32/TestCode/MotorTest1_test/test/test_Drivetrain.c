#include "unity.h"
#include "fff.h"
#include "Drivetrain.h"
#include <stdint.h>

#include "mock_Wheel.h"
//#include "stm32f0xx_gpio.h"
#include "cmsis_device.h"


void setUp(void) {
    //RESET_FAKE(Wheel_StopLeftWheel);
    //RESET_FAKE(Wheel_StopRightWheel);
    FFF_RESET_HISTORY();
}

void tearDown(void) {
}

void test_whenInitializing_thenWheelsAreStopped() {
    Drivetrain_Initialize();

    TEST_ASSERT_EQUAL_UINT(1, Wheel_StopLeftWheel_fake.call_count);
    TEST_ASSERT_EQUAL_UINT(1, Wheel_StopRightWheel_fake.call_count);
    TEST_ASSERT_EQUAL_UINT(0, Drivetrain_GetDirection());
    TEST_ASSERT_EQUAL_UINT(0, Drivetrain_GetVelocity());
}

void test_whenFullStop_thenWheelsAreStoppedImmediately() {
    Drivetrain_FullStop();

    TEST_ASSERT_EQUAL_UINT(1, Wheel_StopLeftWheel_fake.call_count);
    TEST_ASSERT_EQUAL_UINT(1, Wheel_StopRightWheel_fake.call_count);
    TEST_ASSERT_EQUAL_UINT(0, Drivetrain_GetDirection());
    TEST_ASSERT_EQUAL_UINT(0, Drivetrain_GetVelocity());
}

void test_whenMovingLeft_thenMaximumTurnNoMoreThanNegative90() {
    Drivetrain_Move(-100, 100);  // note int8_t range from -127 to 128

    TEST_ASSERT_EQUAL_INT8(-90, Drivetrain_GetDirection());
}

void test_whenMovingRight_thenMaximumTurnNoMoreThan90() {
    Drivetrain_Move(100, 100);  // note int8_t range from -127 to 128

    TEST_ASSERT_EQUAL_INT8(90, Drivetrain_GetDirection());
}
