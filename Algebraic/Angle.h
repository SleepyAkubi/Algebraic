#ifndef ALGEBRAIC_ANGLE_H
#define ALGEBRAIC_ANGLE_H

#include <Algaebraic/Constants.h>

typedef f32 Radian;
typedef f32 Degree;

forceinline Degree RadianToDegree(Radian radians)
{
  return(360.0f * radians / Tau_32);
}

forceinline Radian DegreeToRadian(Degree degrees)
{
  return(degrees * Tau_32 / 360.0f);
}

#endif
