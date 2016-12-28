#include "cmsis_device.h"
#include "mock_Wheel.h"
#include "Drivetrain.h"
#include "fff.h"
#include "unity.h"












void setUp(void) {





    fff.call_history_idx = 0;;

}



void tearDown(void) {

}



void test_whenInitializing_thenWheelsAreStopped() {

    Drivetrain_Initialize();



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((Wheel_StopLeftWheel_fake.call_count)), (((void *)0)), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_UINT);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((Wheel_StopRightWheel_fake.call_count)), (((void *)0)), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_UINT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((Drivetrain_GetDirection())), (((void *)0)), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_UINT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((Drivetrain_GetVelocity())), (((void *)0)), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_UINT);

}



void test_whenFullStop_thenWheelsAreStoppedImmediately() {

    Drivetrain_FullStop();



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((Wheel_StopLeftWheel_fake.call_count)), (((void *)0)), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_UINT);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((Wheel_StopRightWheel_fake.call_count)), (((void *)0)), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_UINT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((Drivetrain_GetDirection())), (((void *)0)), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_UINT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((Drivetrain_GetVelocity())), (((void *)0)), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_UINT);

}



void test_whenMovingLeft_thenMaximumTurnNoMoreThanNegative90() {

    Drivetrain_Move(-100, 100);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-90)), (UNITY_INT)(UNITY_INT8 )((Drivetrain_GetDirection())), (((void *)0)), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT8);

}



void test_whenMovingRight_thenMaximumTurnNoMoreThan90() {

    Drivetrain_Move(100, 100);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((90)), (UNITY_INT)(UNITY_INT8 )((Drivetrain_GetDirection())), (((void *)0)), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT8);

}
