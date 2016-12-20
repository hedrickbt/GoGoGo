#include "unity.h"
#include "Wheel.h"

#include "mock_GPIO.h"
#include "mock_GPIO_conf.h"
//#include "stm32f0xx_gpio.h"
#include "cmsis_device.h"

void test_whenWheelsAreInitialized_thenWeSetTheCorrectPins() {
	Wheel_Initialize();

	TEST_ASSERT_TRUE(0 < GPIO_conf_OutputPin_fake.call_count);
}
