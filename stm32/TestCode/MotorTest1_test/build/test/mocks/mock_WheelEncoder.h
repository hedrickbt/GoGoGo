#ifndef mock_WheelEncoder_H
#define mock_WheelEncoder_H

#include "fff.h"
#include "fff_unity_helper.h"
#include "WheelEncoder.h"


DECLARE_FAKE_VALUE_FUNC2(_Bool, WheelEncoder_IsStepping, uint32_t, uint32_t);
DECLARE_FAKE_VALUE_FUNC0(_Bool, WheelEncoder_GetIsStopped);
DECLARE_FAKE_VOID_FUNC1(WheelEncoder_SetIsStopped, _Bool);
DECLARE_FAKE_VALUE_FUNC0(uint32_t, WheelEncoder_GetLeftWheelCounter);
DECLARE_FAKE_VOID_FUNC1(WheelEncoder_SetLeftWheelCounter, uint32_t);
DECLARE_FAKE_VALUE_FUNC0(uint32_t, WheelEncoder_GetRightWheelCounter);
DECLARE_FAKE_VOID_FUNC1(WheelEncoder_SetRightWheelCounter, uint32_t);

void mock_WheelEncoder_Init(void);
void mock_WheelEncoder_Verify(void);
void mock_WheelEncoder_Destroy(void);

#endif // mock_WheelEncoder_H
