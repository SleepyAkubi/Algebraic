#ifndef ALGEBRAIC_VECTOR2_H
#define ALGEBRAIC_VECTOR2_H

#include <Algaebraic/Common.h>
#include <math.h>

typedef union
{
  struct
  {
    f32 x, y;
  };
  struct
  {
    f32 r, g;
  };
  struct
  {
    f32 s, t;
  };
  f32 data[2];
} Vector2;

forceinline b8 Vector2Equal(const Vector2* a, const Vector2* b)
{
  if (a->x == b->x && a->y == b->y)
    return(1);
  return(0);
}

forceinline Vector2 Vector2Negative(const Vector2* a)
{
  return((Vector2){-a->x, -a->y});
}

forceinline Vector2* Vector2NegativeEquals(Vector2* a)
{
  a->x = -a->x;
  a->y = -a->y;
  return(a);
}

forceinline Vector2 Vector2Minus(const Vector2* a, const Vector2* b)
{
  Vector2 returnValue;
  returnValue.x = a->x - b->x;
  returnValue.y = a->y - b->y;
  return(returnValue);
}

forceinline Vector2* Vector2MinusEquals(Vector2* a, const Vector2* b)
{
  a->x = a->x - b->x;
  a->y = a->y - b->y;
  return(a);
}


forceinline Vector2 Vector2Add(const Vector2* a, const Vector2* b)
{
  Vector2 returnValue;
  returnValue.x = a->x + b->x;
  returnValue.y = a->y + b->y;
  return(returnValue);
}

forceinline Vector2* Vector2AddEquals(Vector2* a, const Vector2* b)
{
  a->x = a->x + b->x;
  a->y = a->y + b->y;
  return(a);
}

forceinline Vector2 Vector2Scale(const Vector2* a, const f32 scalar)
{
  Vector2 returnValue;
  returnValue.x = a->x * scalar;
  returnValue.y = a->y * scalar;
  return(returnValue);
}

forceinline Vector2* Vector2ScaleEquals(Vector2* a, const f32 scalar)
{
  a->x = a->x * scalar;
  a->y = a->y * scalar;
  return(a);
}


forceinline Vector2 Vector2Unscale(const Vector2* a, const f32 scalar)
{
  Vector2 returnValue;
  returnValue.x = a->x / scalar;
  returnValue.y = a->y / scalar;
  return(returnValue);
}

forceinline Vector2* Vector2UnscaleEquals(Vector2* a, const f32 scalar)
{
  a->x = a->x / scalar;
  a->y = a->y / scalar;
  return(a);
}

forceinline Vector2 Vector2InvUnscale(const f32 scalar, const Vector2* a)
{
  Vector2 returnValue;
  returnValue.x = scalar / a->x;
  returnValue.y = scalar / a->y;
  return(returnValue);
}

forceinline Vector2* Vector2InvUnscaleEquals(const f32 scalar, Vector2* a)
{
  a->x = scalar / a->x;
  a->y = scalar / a->y;
  return(a);
}

forceinline Vector2 Vector2Multiply(const Vector2* a, const Vector2* b)
{
  Vector2 returnValue;
  returnValue.x = a->x * b->x;
  returnValue.y = a->y * b->y;

  return(returnValue);
}

forceinline Vector2* Vector2MultiplyEquals(Vector2* a, const Vector2* b)
{
  a->x = a->x * b->x;
  a->y = a->y * b->y;

  return(a);
}

forceinline Vector2 Vector2Divide(const Vector2* a, const Vector2* b)
{
	Vector2 returnValue;
	returnValue.x = a->x / b->x;
	returnValue.y = a->y / b->y;

	return(returnValue);
}

forceinline Vector2* Vector2DivideEquals(Vector2* a, const Vector2* b)
{
	a->x = a->x / b->x;
	a->y = a->y / b->y;

	return(a);
}

forceinline f32 Vector2Dot(const Vector2* a, const Vector2* b)
{
  return a->x * b->x + a->y * b->y;
}

forceinline f32 Vector2Cross(const Vector2* a, const Vector2* b)
{
  return a->x * b->y - b->x * a->y;
}

forceinline f32 Vector2LengthSquared(const Vector2* a)
{
  return Vector2Dot(a, a);
}

forceinline f32 Vector2Length(const Vector2* a)
{
  return sqrtf(Vector2LengthSquared(a));
}

forceinline Vector2 Vector2Normalise(const Vector2* a)
{
  return Vector2Scale(a, 1.0f / Vector2Length(a));
}

forceinline Vector2* Vector2NormaliseEquals(Vector2* a)
{
  return Vector2ScaleEquals(a, 1.0f / Vector2Length(a));
}

#endif
