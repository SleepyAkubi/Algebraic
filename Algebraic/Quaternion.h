#ifndef ALGEBRAIC_QUATERNION_H
#define ALGEBRAIC_QUATERNION_H

#include <math.h>
#include <Algaebraic/Vector4.h>
#include <Algaebraic/Vector3.h>
#include <Algaebraic/Matrix4.h>
#include <Algaebraic/Angle.h>

typedef struct
{
  Radian pitch;
  Radian yaw;
  Radian roll;
} EulerAngles;

typedef union
{
    struct
    {
      f32 x, y, z, w;
    };
    f32 data[4];
} Quaternion;

#define QuaternionIdentity \
(Quaternion) \
{ \
	{ 0.0f, 0.0f, 0.0f, 1.0f } \
}

forceinline b8 QuaternionEqual(const Quaternion* a, const Quaternion* b)
{
  if (a->x == b->x && a->y == b->y && a->z == b->z && a->w == b->w)
    return(1);
  return(0);
}

forceinline Quaternion QuaternionNegative(const Quaternion* a)
{
  Quaternion returnValue;
  returnValue.w = -a->w;
  returnValue.x = -a->x;
  returnValue.y = -a->y;
  returnValue.z = -a->z;

  return(returnValue);
}
forceinline Quaternion* QuaternionNegativeEquals(Quaternion* a)
{
  a->w = -a->w;
  a->x = -a->x;
  a->y = -a->y;
  a->z = -a->z;

  return(a);
}

forceinline Quaternion QuaternionAdd(const Quaternion* a, const Quaternion* b)
{
  Quaternion returnValue;
  returnValue.w = a->w + b->w;
  returnValue.x = a->x + b->x;
  returnValue.y = a->y + b->y;
  returnValue.z = a->z + b->z;

  return(returnValue);
}
forceinline Quaternion* QuaternionAddEquals(Quaternion* a, const Quaternion* b)
{
  a->w = a->w + b->w;
  a->x = a->x + b->x;
  a->y = a->y + b->y;
  a->z = a->z + b->z;

  return(a);
}

forceinline Quaternion QuaternionMinus(const Quaternion* a, const Quaternion* b)
{
  Quaternion returnValue;
  returnValue.w = a->w - b->w;
  returnValue.x = a->x - b->x;
  returnValue.y = a->y - b->y;
  returnValue.z = a->z - b->z;

  return(returnValue);
}
forceinline Quaternion* QuaternionMinusEquals(Quaternion* a, const Quaternion* b)
{
  a->w = a->w - b->w;
  a->x = a->x - b->x;
  a->y = a->y - b->y;
  a->z = a->z - b->z;

  return(a);
}

forceinline Quaternion QuaternionMultiply(const Quaternion* a, const Quaternion* b)
{
  Quaternion returnValue;
  returnValue.x = a->w * b->x + a->x * b->w + a->y * b->z - a->z * b->y;
  returnValue.y = a->w * b->y - a->x * b->z + a->y * b->w + a->z * b->x;
  returnValue.z = a->w * b->z + a->x * b->y - a->y * b->x + a->z * b->w;
  returnValue.w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;

  return(returnValue);
}
forceinline Quaternion* QuaternionMultiplyEquals(Quaternion* a, const Quaternion* b)
{
  a->x = a->w * b->x + a->x * b->w + a->y * b->z - a->z * b->y;
  a->y = a->w * b->y - a->x * b->z + a->y * b->w + a->z * b->x;
  a->z = a->w * b->z + a->x * b->y - a->y * b->x + a->z * b->w;
  a->w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;

  return(a);
}

forceinline Quaternion QuaternionScale(const Quaternion* a, f32 scalar)
{
  Quaternion returnValue;
  returnValue.x = a->x * scalar;
  returnValue.y = a->y * scalar;
  returnValue.z = a->z * scalar;
  returnValue.w = a->w * scalar;

  return(returnValue);
}
forceinline Quaternion* QuaternionScaleEquals(Quaternion* a, f32 scalar)
{
  a->x = a->x * scalar;
  a->y = a->y * scalar;
  a->z = a->z * scalar;
  a->w = a->w * scalar;

  return(a);
}

forceinline Quaternion QuaternionInvUnscale(const Quaternion* a, f32 scalar)
{
  Quaternion returnValue;
  returnValue.x = scalar / a->x;
  returnValue.y = scalar / a->y;
  returnValue.z = scalar / a->z;
  returnValue.w = scalar / a->w;

  return(returnValue);
}
forceinline Quaternion* QuaternionInvUnscaleEquals(Quaternion* a, f32 scalar)
{
  a->x = scalar / a->x;
  a->y = scalar / a->y;
  a->z = scalar / a->z;
  a->w = scalar / a->w;

  return(a);
}

forceinline Quaternion QuaternionUnscale(const Quaternion* a, f32 scalar)
{
  Quaternion returnValue;
  returnValue.x = a->x / scalar;
  returnValue.y = a->y / scalar;
  returnValue.z = a->z / scalar;
  returnValue.w = a->w / scalar;

  return(returnValue);
}
forceinline Quaternion* QuaternionUnscaleEquals(Quaternion* a, f32 scalar)
{
  a->x = a->x / scalar;
  a->y = a->y / scalar;
  a->z = a->z / scalar;
  a->w = a->w / scalar;

  return(a);
}
forceinline f32 QuaternionScalar(Quaternion* a)
{
  return(a->w);
}
forceinline Vector3 QuaternionToVector3(const Quaternion* a)
{
  Vector3 returnValue;
  returnValue.x = a->x * a->w;
  returnValue.y = a->y * a->w;
  returnValue.z = a->z * a->w;
  return(returnValue);
}
forceinline Vector3* QuaternionToVector3Equals(Quaternion* a)
{
  a->x = a->x * a->w;
  a->y = a->y * a->w;
  a->z = a->z * a->w;
  return((Vector3*)a);
}
forceinline f32 QuaternionLengthSquared(const Quaternion* a)
{
  return(a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w);
}
forceinline f32 QuaternionLength(const Quaternion* a)
{
  return(sqrtf(QuaternionLengthSquared(a)));
}
forceinline f32 QuaternionDot(const Quaternion* a, const Quaternion* b)
{
  Vector3 aConv = QuaternionToVector3(a);
  Vector3 bConv = QuaternionToVector3(b);
  return(Vector3Dot(&aConv, &bConv) + a->w * b->w);
}
forceinline Quaternion QuaternionCross(const Quaternion* a, const Quaternion* b)
{
  Quaternion returnValue;
  returnValue.x = a->w * b->x + a->x * b->w + a->y * b->z - a->z * b->y;
  returnValue.y = a->w * b->y + a->y * b->w + a->z * b->x - a->x * b->z;
  returnValue.z = a->w * b->z + a->z * b->w + a->x * b->y - a->y * b->x;
  returnValue.w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;
  return(returnValue);
}
forceinline Quaternion* QuaternionCrossEquals(Quaternion* a, const Quaternion* b)
{
  a->x = a->w * b->x + a->x * b->w + a->y * b->z - a->z * b->y;
  a->y = a->w * b->y + a->y * b->w + a->z * b->x - a->x * b->z;
  a->z = a->w * b->z + a->z * b->w + a->x * b->y - a->y * b->x;
  a->w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;
  return(a);
}
forceinline Quaternion QuaternionNormalise(const Quaternion* a)
{
  return(QuaternionScale(a, 1.0f / QuaternionLength(a)));
}
forceinline Quaternion* QuaternionNormaliseEquals(Quaternion* a)
{
  return(QuaternionScaleEquals(a, 1.0f / QuaternionLength(a)));
}
forceinline Quaternion QuaternionConjugate(const Quaternion* a)
{
  Quaternion negative = QuaternionNegative(a);
  Vector3 vector = QuaternionToVector3(&negative);
  Quaternion returnValue;
  returnValue.x = vector.x;
  returnValue.y = vector.y;
  returnValue.z = vector.z;
  returnValue.w = a->w;
  return(returnValue);
}
forceinline Quaternion* QuaternionConjugateEquals(Quaternion* a)
{
  QuaternionToVector3Equals(QuaternionNegativeEquals(a));
  return(a);
}
forceinline Quaternion QuaternionInverse(const Quaternion* a)
{
  Quaternion conjugate = QuaternionConjugate(a);
  return(QuaternionUnscale(&conjugate, QuaternionDot(a, a)));
}
forceinline Quaternion* QuaternionInverseEquals(Quaternion* a)
{
  return(QuaternionUnscaleEquals(QuaternionConjugateEquals(a), QuaternionDot(a, a)));
}

forceinline Vector3 QuaternionMultiplyByVector3(const Quaternion* a, const Vector3* b)
{
  Vector3 conversion = QuaternionToVector3(a);
  Vector3 crossed = Vector3Cross(&conversion, b);
  Vector3 t = Vector3Scale(&crossed, 2.0f);

  Vector3 scaled = Vector3Scale(&t, a->w);
  Vector3 added = Vector3Add(b, &scaled);
  Vector3 crossedT = Vector3Cross(&conversion, &t);
  return(Vector3Add(&added, &crossedT));
}

forceinline Radian QuaternionAngle(const Quaternion* q)
{
	return(2.0f * acosf(q->w));
}

forceinline Vector3 QuaternionAxis(const Quaternion* q)
{
  f32 tmp1 = 1.0f - q->w * q->w;
  if (tmp1 <= 0.0f)
    return((Vector3){0, 0, 1});

  f32 tmp2 = 1.0f / sqrtf(tmp1);

  Vector3 converted = QuaternionToVector3(q);
  Vector3Scale(&converted, tmp2);

  return(converted);
}

forceinline Quaternion QuaternionAngleAxis(const Radian angle, const Vector3* axis)
{
  Quaternion q;

  *((Vector3*)(&q)) = Vector3Normalise(axis);
  f32 s = sinf(0.5f * angle);
  Vector3ScaleEquals(((Vector3*)(&q)), s);
  q.w = cosf(0.5f * angle);

  return(q);
}

forceinline Radian QuaternionPitch(const Quaternion* q)
{
  return(atan2f(2.0f * q->data[1] * q->data[2] + q->data[3] * q->data[0],
    q->data[3] * q->data[3] - q->data[0] * q->data[0] - q->data[1] * q->data[1] + q->data[2] * q->data[2]));
}

forceinline Radian QuaternionYaw(const Quaternion* q)
{
  return(asinf(-2.0f * (q->data[0] * q->data[2] - q->data[3] * q->data[1])));
}

forceinline Radian QuaternionRoll(const Quaternion* q)
{
  return(atan2f(2.0f * q->data[0] * q->data[1] + q->data[2] * q->data[3],
    q->data[0] * q->data[0] + q->data[3] * q->data[3] - q->data[1] * q->data[1] - q->data[2] * q->data[2]));
}

forceinline EulerAngles QuaternionToEulerAngles(const Quaternion* q)
{
  return((EulerAngles){ QuaternionPitch(q), QuaternionYaw(q), QuaternionRoll(q) });
}

forceinline Quaternion Matrix4ToQuaternion(const Matrix4* m)
{
  f32 fourXSquaredMinus1 = m->data[0].data[0] - m->data[1].data[1] - m->data[2].data[2];
  f32 fourYSquaredMinus1 = m->data[1].data[1] - m->data[0].data[0] - m->data[2].data[2];
  f32 fourZSquaredMinus1 = m->data[2].data[2] - m->data[0].data[0] - m->data[1].data[1];
  f32 fourWSquaredMinus1 = m->data[0].data[0] + m->data[1].data[1] + m->data[2].data[2];

  int biggestIndex = 0;
  f32 fourBiggestSquaredMinus1 = fourWSquaredMinus1;

  if (fourXSquaredMinus1 > fourBiggestSquaredMinus1)
  {
    fourBiggestSquaredMinus1 = fourXSquaredMinus1;
    biggestIndex = 1;
  }

  if (fourYSquaredMinus1 > fourBiggestSquaredMinus1)
  {
    fourBiggestSquaredMinus1 = fourYSquaredMinus1;
    biggestIndex = 2;
  }

  if (fourZSquaredMinus1 > fourBiggestSquaredMinus1)
  {
    fourBiggestSquaredMinus1 = fourZSquaredMinus1;
    biggestIndex = 3;
  }

  f32 biggestVal = sqrtf(fourBiggestSquaredMinus1 + 1.0f) * 0.5f;
  f32 mult = 0.25f / biggestVal;


  Quaternion q;
  switch (biggestIndex)
  {
  case 0:
  {
    q.w = biggestVal;
    q.x = (m->data[1].data[2] - m->data[2].data[1]) * mult;
    q.y = (m->data[2].data[0] - m->data[0].data[2]) * mult;
    q.z = (m->data[0].data[1] - m->data[1].data[0]) * mult;
  } break;
  case 1:
  {
    q.w = (m->data[1].data[2] - m->data[2].data[1]) * mult;
    q.x = biggestVal;
    q.y = (m->data[0].data[1] + m->data[1].data[0]) * mult;
    q.z = (m->data[2].data[0] + m->data[0].data[2]) * mult;
  } break;
  case 2:
  {
    q.w = (m->data[2].data[0] - m->data[0].data[2]) * mult;
    q.x = (m->data[0].data[1] + m->data[1].data[0]) * mult;
    q.y = biggestVal;
    q.z = (m->data[1].data[2] + m->data[2].data[1]) * mult;
  } break;
  case 3:
  {
    q.w = (m->data[0].data[1] - m->data[1].data[0]) * mult;
    q.x = (m->data[2].data[0] + m->data[0].data[2]) * mult;
    q.y = (m->data[1].data[2] + m->data[2].data[1]) * mult;
    q.z = biggestVal;
  } break;
  }

  return(q);
}

forceinline Matrix4 QuaternionToMatrix4(const Quaternion* q)
{
  Matrix4 mat = Matrix4Identity;
  Quaternion a = QuaternionNormalise(q);

  const f32 xx = a.x * a.x;
  const f32 yy = a.y * a.y;
  const f32 zz = a.z * a.z;

  const f32 xy = a.x * a.y;
  const f32 xz = a.x * a.z;

  const f32 yz = a.y * a.z;

  const f32 wx = a.w * a.x;
  const f32 wy = a.w * a.y;
  const f32 wz = a.w * a.z;

  mat.data[0].data[0] = 1.0f - 2.0f * (yy + zz);
  mat.data[0].data[1] = 2.0f * (xy + wz);
  mat.data[0].data[2] = 2.0f * (xz - wy);

  mat.data[1].data[0] = 2.0f * (xy - wz);
  mat.data[1].data[1] = 1.0f - 2.0f * (xx + zz);
  mat.data[1].data[2] = 2.0f * (yz + wx);

  mat.data[2].data[0] = 2.0f * (xz + wy);
  mat.data[2].data[1] = 2.0f * (yz - wx);
  mat.data[2].data[2] = 1.0f - 2.0f * (xx + yy);

  return(mat);
}

forceinline Quaternion QuaternionLookAt(const Vector3* eye, const Vector3* centre, const Vector3* up)
{
  const f32 similar = 0.001f;

  Vector3 distance = Vector3Minus(centre, eye);
  if (Vector3Length(&distance) < similar)
    return(QuaternionIdentity);

  Matrix4 lookAt = Matrix4LookAt(eye, centre, up);
  return(Matrix4ToQuaternion(&lookAt));
}

#endif
