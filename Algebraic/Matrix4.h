#ifndef ALGEBRAIC_MATRIX4_H
#define ALGEBRAIC_MATRIX4_H

#include <Algaebraic/Angle.h>
#include <Algaebraic/Vector3.h>
#include <Algaebraic/Vector4.h>

typedef union
{
  struct
  {
    Vector4 x, y, z, w;
  };
  Vector4 data[4];
} Matrix4;

#define Matrix4Identity \
(Matrix4) \
{ \
  { \
    { 1.0f, 0.0f, 0.0f, 0.0f }, \
    { 0.0f, 1.0f, 0.0f, 0.0f }, \
    { 0.0f, 0.0f, 1.0f, 0.0f }, \
    { 0.0f, 0.0f, 0.0f, 1.0f } \
  } \
} \

forceinline b8 Matrix4Equal(const Matrix4* a, const Matrix4* b)
{
  for (u8 i = 0; i < 4; i++)
  {
    if (Vector4Equals(&a->data[i], &b->data[i]))
      return(0);
  }
  return(1);
}

forceinline Matrix4 Matrix4Add(const Matrix4* a, const Matrix4* b)
{
  Matrix4 returnValue;
  returnValue.x = Vector4Add(&a->x, &b->x);
  returnValue.y = Vector4Add(&a->y, &b->y);
  returnValue.z = Vector4Add(&a->z, &b->z);
  returnValue.w = Vector4Add(&a->w, &b->w);

  return(returnValue);
}

forceinline Matrix4* Matrix4AddEquals(Matrix4* a, const Matrix4* b)
{
  Vector4AddEquals(&a->x, &b->x);
  Vector4AddEquals(&a->y, &b->y);
  Vector4AddEquals(&a->z, &b->z);
  Vector4AddEquals(&a->w, &b->w);

  return(a);
}

forceinline Matrix4 Matrix4Minus(const Matrix4* a, const Matrix4* b)
{
  Matrix4 returnValue;
  returnValue.x = Vector4Minus(&a->x, &b->x);
  returnValue.y = Vector4Minus(&a->y, &b->y);
  returnValue.z = Vector4Minus(&a->z, &b->z);
  returnValue.w = Vector4Minus(&a->w, &b->w);

  return(returnValue);
}

forceinline Matrix4* Matrix4MinusEquals(Matrix4* a, const Matrix4* b)
{
  Vector4MinusEquals(&a->x, &b->x);
  Vector4MinusEquals(&a->y, &b->y);
  Vector4MinusEquals(&a->z, &b->z);
  Vector4MinusEquals(&a->w, &b->w);

  return(a);
}

forceinline Matrix4 Matrix4Translate(const Vector3* v)
{
  Matrix4 result = Matrix4Identity;
  result.data[3] = (Vector4){v->x, v->y, v->z, 1};
  return(result);
}

forceinline Matrix4 Matrix4Hadamard(const Matrix4* a, const Matrix4* b)
{
  Matrix4 result;

  for (usize i = 0; i < 4; i++)
    result.data[i] = Vector4Multiply(&a->data[i], &b->data[i]);

  return(result);
}

forceinline Matrix4* Matrix4HadamardEquals(Matrix4* a, const Matrix4* b)
{
	for (usize i = 0; i < 4; i++)
		Vector4MultiplyEquals(&a->data[i], &b->data[i]);

	return(a);
}

forceinline Matrix4 Matrix4Rotate(const Radian angle, const Vector3* v)
{
  const f32 c = cosf(angle);
  const f32 s = sinf(angle);

  const Vector3 axis = Vector3Normalise(v);
  const Vector3 t = Vector3Scale(&axis, 1.0f - c);

  Matrix4 rot = Matrix4Identity;
  rot.data[0].data[0] = c + t.x * axis.x;
  rot.data[0].data[1] = 0 + t.x * axis.y + s * axis.z;
  rot.data[0].data[2] = 0 + t.x * axis.z - s * axis.y;
  rot.data[0].data[3] = 0;

  rot.data[1].data[0] = 0 + t.y * axis.x - s * axis.z;
  rot.data[1].data[1] = c + t.y * axis.y;
  rot.data[1].data[2] = 0 + t.y * axis.z + s * axis.x;
  rot.data[1].data[3] = 0;

  rot.data[2].data[0] = 0 + t.z * axis.x + s * axis.y;
  rot.data[2].data[1] = 0 + t.z * axis.y - s * axis.x;
  rot.data[2].data[2] = c + t.z * axis.z;
  rot.data[2].data[3] = 0;

  return(rot);
}

forceinline Matrix4 Matrix4Scale(const Vector3* v)
{
  return((Matrix4){
    (Vector4){v->x, 0, 0, 0}, (Vector4){0, v->y, 0, 0}, (Vector4){0, 0, v->z, 0}, (Vector4){0, 0, 0, 1} });
}

forceinline Matrix4 Matrix4Ortho(f32 left, f32 right, f32 bottom, f32 top)
{
  Matrix4 result = Matrix4Identity;

  result.data[0].data[0] = 2.0f / (right - left);
  result.data[1].data[1] = 2.0f / (top - bottom);
  result.data[2].data[2] = -1.0f;
  result.data[3].data[0] = -(right + left) / (right - left);
  result.data[3].data[1] = -(top + bottom) / (top - bottom);

  return(result);
}

forceinline Matrix4 Matrix4OrthoClipped(f32 left, f32 right, f32 bottom, f32 top, f32 zNear, f32 zFar)
{
  Matrix4 result = Matrix4Identity;

  result.data[0].data[0] = 2.0f * zNear / (right - left);
  result.data[1].data[1] = 2.0f * zNear / (top - bottom);
  result.data[2].data[2] = -2.0f / (zFar - zNear);
  result.data[3].data[0] = -(right + left) / (right - left);
  result.data[3].data[1] = -(top + bottom) / (top - bottom);
  result.data[3].data[2] = -(zFar + zNear) / (zFar - zNear);

  return(result);
}

forceinline Matrix4 Matrix4Perspective(const Radian fovy, f32 aspect, f32 zNear, f32 zFar)
{
  const f32 tanHalfFovy = tanf(fovy / 2.0f);

  Matrix4 result;

  result.data[0].data[0] = 1.0f / (aspect * tanHalfFovy);
  result.data[1].data[1] = 1.0f / tanHalfFovy;
  result.data[2].data[2] = -(zFar + zNear) / (zFar - zNear);
  result.data[2].data[3] = -1.0f;
  result.data[3].data[2] = -2.0f * zFar * zNear / (zFar - zNear);

  return(result);
}

forceinline Matrix4 Matrix4InfinitePerspective(const Radian fovy, f32 aspect, f32 zNear)
{
  const f32 range = tanf(fovy / 2.0f) * zNear;
  const f32 left = -range * aspect;
  const f32 right = range * aspect;
  const f32 bottom = -range;

  Matrix4 result;

  result.data[0].data[0] = (2.0f * zNear) / (right - left);
  result.data[1].data[1] = (2.0f * zNear) / (range - bottom);
  result.data[2].data[2] = -1.0f;
  result.data[2].data[3] = -1.0f;
  result.data[3].data[2] = -2.0f * zNear;

  return(result);
}

Matrix4 Matrix4LookAt(const Vector3* eye, const Vector3* centre, const Vector3* up)
{
  const Vector3 sub = Vector3Minus(centre, eye);
  const Vector3 f = Vector3Normalise(&sub);
  const Vector3 cross = Vector3Cross(&f, up);
  const Vector3 s = Vector3Normalise(&cross);
  const Vector3 u = Vector3Cross(&s, &f);

  Matrix4 result;
  result.data[0].data[0] = +s.x;
  result.data[1].data[0] = +s.y;
  result.data[2].data[0] = +s.z;

  result.data[0].data[1] = +u.x;
  result.data[1].data[1] = +u.y;
  result.data[2].data[1] = +u.z;

  result.data[0].data[2] = -f.x;
  result.data[1].data[2] = -f.y;
  result.data[2].data[2] = -f.z;

  result.data[3].data[0] = -Vector3Dot(&s, eye);
  result.data[3].data[1] = -Vector3Dot(&u, eye);
  result.data[3].data[2] = +Vector3Dot(&f, eye);

  return(result);
}


#endif
