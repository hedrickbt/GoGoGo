#ifndef mock_GPIO_conf_H
#define mock_GPIO_conf_H

#include "fff.h"
#include "fff_unity_helper.h"
#include "GPIO_conf.h"


DECLARE_FAKE_VOID_FUNC2(GPIO_conf_OutputPin, GPIO_TypeDef*, uint16_t);
DECLARE_FAKE_VOID_FUNC2(GPIO_conf_InputPin, GPIO_TypeDef*, uint16_t);
DECLARE_FAKE_VOID_FUNC3(GPIO_conf_PwmPin, GPIO_TypeDef*, uint16_t, uint8_t);
DECLARE_FAKE_VOID_FUNC2(GPIO_conf_InterruptPin, GPIO_TypeDef*, uint16_t);

void mock_GPIO_conf_Init(void);
void mock_GPIO_conf_Verify(void);
void mock_GPIO_conf_Destroy(void);

#endif // mock_GPIO_conf_H
