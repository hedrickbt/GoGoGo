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



void test_whenMoving90DegreesRightForward_thenInnerWheelDoesNotTurn() {

    Drivetrain_Move(90, 100);



    if ((Wheel_TurnRightWheel_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(53)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((Wheel_TurnRightWheel_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_UINT16);

    if ((Wheel_TurnLeftWheel_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(55)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((100)), (UNITY_INT)(UNITY_UINT16)((Wheel_TurnLeftWheel_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_UINT16);

}



void test_whenMoving45DegreesRightForward_thenWheelTurnsAtHalfSpeed() {

    Drivetrain_Move(45, 100);



    if ((Wheel_TurnRightWheel_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(62)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((50)), (UNITY_INT)(UNITY_UINT16)((Wheel_TurnRightWheel_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_UINT16);

    if ((Wheel_TurnLeftWheel_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(64)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((100)), (UNITY_INT)(UNITY_UINT16)((Wheel_TurnLeftWheel_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_UINT16);

}



void test_whenMoving45DegreesLeftForward_thenWheelTurnsAtHalfSpeed() {

    Drivetrain_Move(-45, 100);



    if ((Wheel_TurnRightWheel_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(71)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((100)), (UNITY_INT)(UNITY_UINT16)((Wheel_TurnRightWheel_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_UINT16);

    if ((Wheel_TurnLeftWheel_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(73)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((50)), (UNITY_INT)(UNITY_UINT16)((Wheel_TurnLeftWheel_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_UINT16);

}



void test_whenMovingStraightForward_thenBothWheelsTurnWithSameVelocity() {

    Drivetrain_Move(0, 100);



    if ((Wheel_Straight_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(80)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((100)), (UNITY_INT)(UNITY_UINT16)((Wheel_Straight_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_UINT16);

}

void test_whenMoving90DegreesRightReverse_thenInnerWheelDoesNotTurn() {

    Drivetrain_Move(90, -100);



    if (!(Wheel_TurnRightWheel_fake.arg0_history[0])) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(95)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((100)), (UNITY_INT)(UNITY_UINT16)((Wheel_TurnRightWheel_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_UINT16);

    if (!(Wheel_TurnLeftWheel_fake.arg0_history[0])) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(97)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((Wheel_TurnLeftWheel_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_UINT16);

}



void test_whenMoving45DegreesRightReverse_thenWheelTurnsAtHalfSpeed() {

    Drivetrain_Move(45, -100);



    if (!(Wheel_TurnRightWheel_fake.arg0_history[0])) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(104)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((100)), (UNITY_INT)(UNITY_UINT16)((Wheel_TurnRightWheel_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(105), UNITY_DISPLAY_STYLE_UINT16);

    if (!(Wheel_TurnLeftWheel_fake.arg0_history[0])) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(106)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((50)), (UNITY_INT)(UNITY_UINT16)((Wheel_TurnLeftWheel_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_UINT16);

}



void test_whenMoving45DegreesLeftReverse_thenWheelTurnsAtHalfSpeed() {

    Drivetrain_Move(-45, -100);



    if (!(Wheel_TurnRightWheel_fake.arg0_history[0])) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(113)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((50)), (UNITY_INT)(UNITY_UINT16)((Wheel_TurnRightWheel_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(114), UNITY_DISPLAY_STYLE_UINT16);

    if (!(Wheel_TurnLeftWheel_fake.arg0_history[0])) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(115)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((100)), (UNITY_INT)(UNITY_UINT16)((Wheel_TurnLeftWheel_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_UINT16);

}



void test_whenMovingStraightReverse_thenBothWheelsTurnWithSameVelocity() {

    Drivetrain_Move(0, -100);



    if (!(Wheel_Straight_fake.arg0_history[0])) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(122)));};

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((100)), (UNITY_INT)(UNITY_UINT16)((Wheel_Straight_fake.arg1_history[0])), (((void *)0)), (UNITY_UINT)(123), UNITY_DISPLAY_STYLE_UINT16);

}



void test_whenMovingWithNoVelocity_thenWheelsAreStopped() {

    Drivetrain_Move(90, 0);



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((Wheel_StopLeftWheel_fake.call_count)), (((void *)0)), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((Wheel_StopRightWheel_fake.call_count)), (((void *)0)), (UNITY_UINT)(130), UNITY_DISPLAY_STYLE_INT);

}
