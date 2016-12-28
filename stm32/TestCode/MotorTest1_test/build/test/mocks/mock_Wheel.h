#ifndef mock_Wheel_H
#define mock_Wheel_H

#include "fff.h"
#include "fff_unity_helper.h"
#include "Wheel.h"


DECLARE_FAKE_VOID_FUNC0(Wheel_Initialize);
DECLARE_FAKE_VOID_FUNC0(EXTI4_15_IRQHandler);
DECLARE_FAKE_VOID_FUNC2(Wheel_Straight, _Bool, uint16_t);
DECLARE_FAKE_VOID_FUNC2(Wheel_TurnLeftWheel, _Bool, uint16_t);
DECLARE_FAKE_VOID_FUNC2(Wheel_TurnRightWheel, _Bool, uint16_t);
DECLARE_FAKE_VOID_FUNC0(Wheel_StopLeftWheel);
DECLARE_FAKE_VOID_FUNC0(Wheel_StopRightWheel);

void mock_Wheel_Init(void);
void mock_Wheel_Verify(void);
void mock_Wheel_Destroy(void);

#endif // mock_Wheel_H
