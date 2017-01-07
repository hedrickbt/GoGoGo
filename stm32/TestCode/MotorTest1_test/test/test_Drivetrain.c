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

void test_whenMoving90DegreesRightForward_thenInnerWheelDoesNotTurn() {
    Drivetrain_Move(90, 100);

    TEST_ASSERT_TRUE(Wheel_TurnRightWheel_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(0, Wheel_TurnRightWheel_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(Wheel_TurnLeftWheel_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(100, Wheel_TurnLeftWheel_fake.arg1_history[0]);
}

void test_whenMoving45DegreesRightForward_thenWheelTurnsAtHalfSpeed() {
    Drivetrain_Move(45, 100);

    TEST_ASSERT_TRUE(Wheel_TurnRightWheel_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(50, Wheel_TurnRightWheel_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(Wheel_TurnLeftWheel_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(100, Wheel_TurnLeftWheel_fake.arg1_history[0]);
}

void test_whenMoving45DegreesLeftForward_thenWheelTurnsAtHalfSpeed() {
    Drivetrain_Move(-45, 100);

    TEST_ASSERT_TRUE(Wheel_TurnRightWheel_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(100, Wheel_TurnRightWheel_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(Wheel_TurnLeftWheel_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(50, Wheel_TurnLeftWheel_fake.arg1_history[0]);
}

void test_whenMovingStraightForward_thenBothWheelsTurnWithSameVelocity() {
    Drivetrain_Move(0, 100);

    TEST_ASSERT_TRUE(Wheel_Straight_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(100, Wheel_Straight_fake.arg1_history[0]);
}









void test_whenMoving90DegreesRightReverse_thenInnerWheelDoesNotTurn() {
    Drivetrain_Move(90, -100);

    TEST_ASSERT_FALSE(Wheel_TurnRightWheel_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(100, Wheel_TurnRightWheel_fake.arg1_history[0]);
    TEST_ASSERT_FALSE(Wheel_TurnLeftWheel_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(0, Wheel_TurnLeftWheel_fake.arg1_history[0]);
}

void test_whenMoving45DegreesRightReverse_thenWheelTurnsAtHalfSpeed() {
    Drivetrain_Move(45, -100);

    TEST_ASSERT_FALSE(Wheel_TurnRightWheel_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(100, Wheel_TurnRightWheel_fake.arg1_history[0]);
    TEST_ASSERT_FALSE(Wheel_TurnLeftWheel_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(50, Wheel_TurnLeftWheel_fake.arg1_history[0]);
}

void test_whenMoving45DegreesLeftReverse_thenWheelTurnsAtHalfSpeed() {
    Drivetrain_Move(-45, -100);

    TEST_ASSERT_FALSE(Wheel_TurnRightWheel_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(50, Wheel_TurnRightWheel_fake.arg1_history[0]);
    TEST_ASSERT_FALSE(Wheel_TurnLeftWheel_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(100, Wheel_TurnLeftWheel_fake.arg1_history[0]);
}

void test_whenMovingStraightReverse_thenBothWheelsTurnWithSameVelocity() {
    Drivetrain_Move(0, -100);

    TEST_ASSERT_FALSE(Wheel_Straight_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL_UINT16(100, Wheel_Straight_fake.arg1_history[0]);
}

void test_whenMovingWithNoVelocity_thenWheelsAreStopped() {
    Drivetrain_Move(90, 0);

    TEST_ASSERT_EQUAL(1, Wheel_StopLeftWheel_fake.call_count);
    TEST_ASSERT_EQUAL(1, Wheel_StopRightWheel_fake.call_count);
}
