#ifndef INCLUDE_WHEELENCODER_H_
#define INCLUDE_WHEELENCODER_H_

#include <stdbool.h>
#include <stdint.h>

bool WheelEncoder_IsStepping(uint32_t current_step, uint32_t steps);
bool WheelEncoder_GetIsStopped(void);
void WheelEncoder_SetIsStopped(bool value);
uint32_t WheelEncoder_GetLeftWheelCounter(void);
void WheelEncoder_SetLeftWheelCounter(uint32_t value);
uint32_t WheelEncoder_GetRightWheelCounter(void);
void WheelEncoder_SetRightWheelCounter(uint32_t value);


#endif /* INCLUDE_WHEELENCODER_H_ */
