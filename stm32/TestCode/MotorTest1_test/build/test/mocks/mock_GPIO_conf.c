#include <string.h>
#include "fff.h"
#include "mock_GPIO_conf.h"

DEFINE_FAKE_VOID_FUNC2(GPIO_conf_OutputPin, GPIO_TypeDef*, uint16_t);
DEFINE_FAKE_VOID_FUNC2(GPIO_conf_InputPin, GPIO_TypeDef*, uint16_t);
DEFINE_FAKE_VOID_FUNC3(GPIO_conf_PwmPin, GPIO_TypeDef*, uint16_t, uint8_t);
DEFINE_FAKE_VOID_FUNC2(GPIO_conf_InterruptPin, GPIO_TypeDef*, uint16_t);

void mock_GPIO_conf_Init(void)
{
    FFF_RESET_HISTORY();
    RESET_FAKE(GPIO_conf_OutputPin)
    RESET_FAKE(GPIO_conf_InputPin)
    RESET_FAKE(GPIO_conf_PwmPin)
    RESET_FAKE(GPIO_conf_InterruptPin)
}
void mock_GPIO_conf_Verify(void)
{
}
void mock_GPIO_conf_Destroy(void)
{
}
