#ifndef INCLUDE_DRIVETRAIN_H_
#define INCLUDE_DRIVETRAIN_H_

#include <stdint.h>


/*
 * Direction: -90 to 90 where
 * 	0 is dead ahead
 * 	-90 is full left
 * 	90 is full right
 *
 * Velocity: -255 to 255 where
 *  0 is stopped
 *  -255 is full speed reverse
 *  255 is full speed forward
 */
void Drivetrain_Initialize(void);
void Drivetrain_FullStop(void);
void Drivetrain_Move(int8_t direction, int16_t velocity);
int8_t Drivetrain_GetDirection(void);
int8_t Drivetrain_GetVelocity(void);




#endif /* INCLUDE_DRIVETRAIN_H_ */
