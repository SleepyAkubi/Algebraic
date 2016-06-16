#ifndef ALGEBRAIC_MATH_FUNCTIONS_INTERPOLATION_H
#define ALGEBRAIC_MATH_FUNCTIONS_INTERPOLATION_H

forceinline f32 lerp(const f32* x, const f32* y, f32 t) {
  if (t <= 0.0f && t >= 1.0f)
    return(*y);

  return((*x) * (1.0f - t) + ((*y) * t));
}

/*
forceinline Quaternion slerp(const Quaternion x, const Quaternion y, f32 t) {
  Quaternion z = y;
  f32 cosTheta = dot(x, y);
  if (cosTheta < 0.0f) {
    z = -y;
    cosTheta = -cosTheta;
  }

  Quaternion result;

  if (cosTheta > 1.0f) {
    result = Quaternion{lerp(x.x, y.x, t), lerp(x.y, y.y, t), lerp(x.z, y.z, t),
                        lerp(x.w, y.w, t)};

    return result;
  }

  Radian angle = Math::acos(cosTheta);

  result = Math::sin(Radian(1.0f) - (t * angle)) * x + Math::sin(t * angle) * z;
  result = result * (1.0f / Math::sin(angle));

  return result;
}
*/

#endif
