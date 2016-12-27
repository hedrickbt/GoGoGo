#include <string.h>
#include "fff.h"
#include "mock_WheelEncoder.h"

DEFINE_FAKE_VALUE_FUNC2(_Bool, WheelEncoder_IsStepping, uint32_t, uint32_t);
DEFINE_FAKE_VALUE_FUNC0(_Bool, WheelEncoder_GetIsStopped);
DEFINE_FAKE_VOID_FUNC1(WheelEncoder_SetIsStopped, _Bool);
DEFINE_FAKE_VALUE_FUNC0(uint32_t, WheelEncoder_GetLeftWheelCounter);
DEFINE_FAKE_VOID_FUNC1(WheelEncoder_SetLeftWheelCounter, uint32_t);
DEFINE_FAKE_VALUE_FUNC0(uint32_t, WheelEncoder_GetRightWheelCounter);
DEFINE_FAKE_VOID_FUNC1(WheelEncoder_SetRightWheelCounter, uint32_t);

void mock_WheelEncoder_Init(void)
{
    FFF_RESET_HISTORY();
    RESET_FAKE(WheelEncoder_IsStepping)
    RESET_FAKE(WheelEncoder_GetIsStopped)
    RESET_FAKE(WheelEncoder_SetIsStopped)
    RESET_FAKE(WheelEncoder_GetLeftWheelCounter)
    RESET_FAKE(WheelEncoder_SetLeftWheelCounter)
    RESET_FAKE(WheelEncoder_GetRightWheelCounter)
    RESET_FAKE(WheelEncoder_SetRightWheelCounter)
}
void mock_WheelEncoder_Verify(void)
{
}
void mock_WheelEncoder_Destroy(void)
{
}
