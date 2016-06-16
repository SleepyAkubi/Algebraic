#ifndef ALGEBRAIC_VECTOR3_H
#define ALGEBRAIC_VECTOR3_H

#include <Algaebraic/Common.h>
#include <math.h>

typedef union
{
  struct
  {
    f32 x, y, z;
  };
  struct
  {
    f32 r, g, b;
  };
  struct
  {
    f32 s, t, p;
  };
  f32 data[3];
} Vector3;

forceinline b8 Vector3Equals(const Vector3* a, const Vector3* b)
{
  if (a->x == b->x && a->y == b->y && a->z == b->z)
    return(1);
  return(0);
}

forceinline Vector3 Vector3Negative(const Vector3* a)
{
  return((Vector3){-a->x, -a->y, -a->z});
}

forceinline Vector3* Vector3NegativeEquals(Vector3* a)
{
  a->x = -a->x;
  a->y = -a->y;
  a->z = -a->z;

  return(a);
}

forceinline Vector3 Vector3Add(const Vector3* a, const Vector3* b)
{
  Vector3 returnValue;
  returnValue.x = a->x + b->x;
  returnValue.y = a->y + b->y;
  returnValue.z = a->z + b->z;

  return(returnValue);
}

forceinline Vector3* Vector3AddEquals(Vector3* a, const Vector3* b)
{
  a->x = a->x + b->x;
  a->y = a->y + b->y;
  a->z = a->z + b->z;

  return(a);
}

forceinline Vector3 Vector3Minus(const Vector3* a, const Vector3* b)
{
  Vector3 returnValue;
  returnValue.x = a->x - b->x;
  returnValue.y = a->y - b->y;
  returnValue.z = a->z - b->z;

  return(returnValue);
}

forceinline Vector3* Vector3MinusEquals(Vector3* a, const Vector3* b)
{
  a->x = a->x - b->x;
  a->y = a->y - b->y;
  a->z = a->z - b->z;

  return(a);
}

forceinline Vector3 Vector3Scale(const Vector3* a, f32 scalar)
{
  Vector3 returnValue;
  returnValue.x = a->x * scalar;
  returnValue.y = a->y * scalar;
  returnValue.z = a->z * scalar;

  return(returnValue);
}

forceinline Vector3* Vector3ScaleEquals(Vector3* a, f32 scalar)
{
  a->x = a->x * scalar;
  a->y = a->y * scalar;
  a->z = a->z * scalar;

  return(a);
}

forceinline Vector3 Vector3Unscale(const Vector3* a, f32 scalar)
{
  Vector3 returnValue;
  returnValue.x = a->x / scalar;
  returnValue.y = a->y / scalar;
  returnValue.z = a->z / scalar;

  return(returnValue);
}

forceinline Vector3* Vector3UnscaleEquals(Vector3* a, f32 scalar)
{
  a->x = a->x / scalar;
  a->y = a->y / scalar;
  a->z = a->z / scalar;

  return(a);
}

forceinline Vector3 Vector3InvUnscale(const Vector3* a, f32 scalar)
{
  Vector3 returnValue;
  returnValue.x = scalar / a->x;
  returnValue.y = scalar / a->y;
  returnValue.z = scalar / a->z;

  return(returnValue);
}

forceinline Vector3* Vector3InvUnscaleEquals(Vector3* a, f32 scalar)
{
  a->x = scalar / a->x;
  a->y = scalar / a->y;
  a->z = scalar / a->z;

  return(a);
}

forceinline Vector3 Vector3Multiply(const Vector3* a, const Vector3* b)
{
  Vector3 returnValue;
  returnValue.x = a->x * b->x;
  returnValue.y = a->y * b->y;
  returnValue.z = a->z * b->z;

  return(returnValue);
}

forceinline Vector3* Vector3MultiplyEquals(Vector3* a, const Vector3* b)
{
  a->x = a->x * b->x;
  a->y = a->y * b->y;
  a->z = a->z * b->z;

  return(a);
}

forceinline Vector3 Vector3Divide(const Vector3* a, const Vector3* b)
{
	Vector3 returnValue;
	returnValue.x = a->x / b->x;
	returnValue.y = a->y / b->y;
	returnValue.z = a->z / b->z;

	return(returnValue);
}

forceinline Vector3* Vector3DivideEquals(Vector3* a, const Vector3* b)
{
	a->x = a->x / b->x;
	a->y = a->y / b->y;
	a->z = a->z / b->z;

	return(a);
}

forceinline f32 Vector3Dot(const Vector3* a, const Vector3* b)
{
  return(a->x * b->x + a->y * b->y + a->z * b->z);
}

forceinline Vector3 Vector3Cross(const Vector3* a, const Vector3* b)
{
  Vector3 returnValue;
  returnValue.x = a->y * b->z - b->y * a->z;
  returnValue.y = a->z * b->x - b->z * a->x;
  returnValue.z = a->x * b->y - b->x * a->y;

  return(returnValue);
}

forceinline Vector3* Vector3CrossEquals(Vector3* a, const Vector3* b)
{
  a->x = a->y * b->z - b->y * a->z;
  a->y = a->z * b->x - b->z * a->x;
  a->z = a->x * b->y - b->x * a->y;

  return(a);
}

forceinline f32 Vector3LengthSquared(const Vector3* a)
{
  return(Vector3Dot(a, a));
}

forceinline f32 Vector3Length(const Vector3* a)
{
  return(sqrtf(Vector3LengthSquared(a)));
}

forceinline Vector3 Vector3Normalise(const Vector3* a)
{
  return(Vector3Scale(a, 1.0f / Vector3Length(a)));
}

forceinline Vector3* Vector3NormaliseEquals(Vector3* a)
{
  return(Vector3ScaleEquals(a, 1.0f / Vector3Length(a)));
}

#endif
