#include "cmsis_device.h"
#include "mock_GPIO_conf.h"
#include "mock_GPIO.h"
#include "Wheel.h"
#include "unity.h"








void test_whenWheelsAreInitialized_thenWeSetTheCorrectPins() {

 Wheel_Initialize();



 if ((0 < GPIO_conf_OutputPin_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(12)));};

}
