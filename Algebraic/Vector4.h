#ifndef ALGEBRAIC_VECTOR4_H
#define ALGEBRAIC_VECTOR4_H

#include <Algaebraic/Common.h>
#include <math.h>

typedef union
{
  struct
  {
    f32 x, y, z, w;
  };
  struct
  {
    f32 r, g, b, a;
  };
  struct
  {
    f32 s, t, p, q;
  };
  f32 data[4];
} Vector4;

forceinline Vector4 Vector4Negative(const Vector4* a)
{
  return((Vector4){-a->x, -a->y, -a->z, -a->w});
}

forceinline Vector4* Vector4NegativeEquals(Vector4* a)
{
  a->x = -a->x;
  a->y = -a->y;
  a->z = -a->z;
  a->w = -a->w;

  return(a);
}

forceinline b8 Vector4Equals(const Vector4* a, const Vector4* b)
{
  if (a->x == b->x && a->y == b->y && a->z == a->z && a->w == b->w)
    return(1);
  return(0);
}

forceinline Vector4 Vector4Add(const Vector4* a, const Vector4* b)
{
  Vector4 returnResult;
  returnResult.x = a->x + b->x;
  returnResult.y = a->y + b->y;
  returnResult.z = a->z + b->z;
  returnResult.w = a->w + b->w;

  return(returnResult);
}

forceinline Vector4* Vector4AddEquals(Vector4* a, const Vector4* b)
{
  a->x = a->x + b->x;
  a->y = a->y + b->y;
  a->z = a->z + b->z;
  a->w = a->w + b->w;

  return(a);
}

forceinline Vector4 Vector4Minus(const Vector4* a, const Vector4* b)
{
  Vector4 returnResult;
  returnResult.x = a->x - b->x;
  returnResult.y = a->y - b->y;
  returnResult.z = a->z - b->z;
  returnResult.w = a->w - b->w;

  return(returnResult);
}

forceinline Vector4* Vector4MinusEquals(Vector4* a, const Vector4* b)
{
  a->x = a->x - b->x;
  a->y = a->y - b->y;
  a->z = a->z - b->z;
  a->w = a->w - b->w;

  return(a);
}

forceinline Vector4 Vector4Scale(const Vector4* a, f32 scalar)
{
  Vector4 returnValue;
  returnValue.x = a->x * scalar;
  returnValue.y = a->y * scalar;
  returnValue.z = a->z * scalar;
  returnValue.w = a->w * scalar;

  return(returnValue);
}

forceinline Vector4* Vector4ScaleEquals(Vector4* a, f32 scalar)
{
  a->x = a->x * scalar;
  a->y = a->y * scalar;
  a->z = a->z * scalar;
  a->w = a->w * scalar;

  return(a);
}

forceinline Vector4 Vector4Unscale(const Vector4* a, f32 scalar)
{
  Vector4 returnValue;
  returnValue.x = a->x / scalar;
  returnValue.y = a->y / scalar;
  returnValue.z = a->z / scalar;
  returnValue.w = a->w / scalar;

  return(returnValue);
}

forceinline Vector4* Vector4UnscaleEquals(Vector4* a, f32 scalar)
{
  a->x = a->x / scalar;
  a->y = a->y / scalar;
  a->z = a->z / scalar;
  a->w = a->w / scalar;

  return(a);
}

forceinline Vector4 Vector4InvUnscale(const Vector4* a, f32 scalar)
{
  Vector4 returnValue;
  returnValue.x = scalar / a->x;
  returnValue.y = scalar / a->y;
  returnValue.z = scalar / a->z;
  returnValue.w = scalar / a->w;

  return(returnValue);
}

forceinline Vector4* Vector4InvUnscaleEquals(Vector4* a, f32 scalar)
{
  a->x = scalar / a->x;
  a->y = scalar / a->y;
  a->z = scalar / a->z;
  a->w = scalar / a->w;

  return(a);
}

forceinline Vector4 Vector4Multiply(const Vector4* a, const Vector4* b)
{
  Vector4 returnValue;
  returnValue.x = a->x * b->x;
  returnValue.y = a->y * b->y;
  returnValue.z = a->z * b->z;
  returnValue.w = a->z * b->w;

  return(returnValue);
}

forceinline Vector4* Vector4MultiplyEquals(Vector4* a, const Vector4* b)
{
  a->x = a->x * b->x;
  a->y = a->y * b->y;
  a->z = a->z * b->z;
  a->w = a->w * b->w;

  return(a);
}

forceinline Vector4 Vector4Divide(const Vector4* a, const Vector4* b)
{
	Vector4 returnValue;
	returnValue.x = a->x / b->x;
	returnValue.y = a->y / b->y;
	returnValue.z = a->z / b->z;
	returnValue.w = a->z / b->w;

	return(returnValue);
}

forceinline Vector4* Vector4DivideEquals(Vector4* a, const Vector4* b)
{
	a->x = a->x / b->x;
	a->y = a->y / b->y;
	a->z = a->z / b->z;
	a->w = a->w / b->w;

	return(a);
}

forceinline f32 Vector4Dot(const Vector4* a, const Vector4* b)
{
  return(a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w);
}

forceinline f32 Vector4LengthSquared(const Vector4* a)
{
  return(Vector4Dot(a, a));
}

forceinline f32 Vector4Length(const Vector4* a)
{
  return(sqrtf(Vector4LengthSquared(a)));
}

forceinline Vector4 Vector4Normalise(const Vector4* a)
{
  return(Vector4Scale(a, 1.0f / Vector4Length(a)));
}

forceinline Vector4* Vector4NormaliseEquals(Vector4* a)
{
  return(Vector4ScaleEquals(a, 1.0f / Vector4Length(a)));
}

#endif
