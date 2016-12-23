#include <string.h>
#include "fff.h"
#include "mock_WheelEncoder.h"

DEFINE_FAKE_VALUE_FUNC2(_Bool, WheelEncoder_IsStepping, uint32_t, uint32_t);

void mock_WheelEncoder_Init(void)
{
    FFF_RESET_HISTORY();
    RESET_FAKE(WheelEncoder_IsStepping)
}
void mock_WheelEncoder_Verify(void)
{
}
void mock_WheelEncoder_Destroy(void)
{
}
