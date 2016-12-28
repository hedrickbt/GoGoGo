#include <string.h>
#include "fff.h"
#include "mock_Wheel.h"

DEFINE_FAKE_VOID_FUNC0(Wheel_Initialize);
DEFINE_FAKE_VOID_FUNC0(EXTI4_15_IRQHandler);
DEFINE_FAKE_VOID_FUNC2(Wheel_Straight, _Bool, uint16_t);
DEFINE_FAKE_VOID_FUNC2(Wheel_TurnLeftWheel, _Bool, uint16_t);
DEFINE_FAKE_VOID_FUNC2(Wheel_TurnRightWheel, _Bool, uint16_t);
DEFINE_FAKE_VOID_FUNC0(Wheel_StopLeftWheel);
DEFINE_FAKE_VOID_FUNC0(Wheel_StopRightWheel);

void mock_Wheel_Init(void)
{
    FFF_RESET_HISTORY();
    RESET_FAKE(Wheel_Initialize)
    RESET_FAKE(EXTI4_15_IRQHandler)
    RESET_FAKE(Wheel_Straight)
    RESET_FAKE(Wheel_TurnLeftWheel)
    RESET_FAKE(Wheel_TurnRightWheel)
    RESET_FAKE(Wheel_StopLeftWheel)
    RESET_FAKE(Wheel_StopRightWheel)
}
void mock_Wheel_Verify(void)
{
}
void mock_Wheel_Destroy(void)
{
}
