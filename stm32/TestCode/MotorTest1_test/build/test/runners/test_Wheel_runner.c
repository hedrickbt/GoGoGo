/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  CMock_Init(); \
  UNITY_CLR_DETAILS(); \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
    CMock_Verify(); \
  } \
  CMock_Destroy(); \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "cmock.h"
#include <setjmp.h>
#include <stdio.h>
#include "mock_GPIO.h"
#include "mock_GPIO_conf.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_whenWheelsAreInitialized_thenWeSetTheCorrectPins();


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_GPIO_Init();
  mock_GPIO_conf_Init();
}
static void CMock_Verify(void)
{
  mock_GPIO_Verify();
  mock_GPIO_conf_Verify();
}
static void CMock_Destroy(void)
{
  mock_GPIO_Destroy();
  mock_GPIO_conf_Destroy();
}

/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_Wheel.c");
  RUN_TEST(test_whenWheelsAreInitialized_thenWeSetTheCorrectPins, 9);

  CMock_Guts_MemFreeFinal();
  return (UnityEnd());
}

//=======Defintions of FFF variables=====
#include "fff.h"
DEFINE_FFF_GLOBALS;