/*

    This file is part of the Nemesis3dMath library.

    vector.inl
    Vector inline functions

    Copyright (C) 2008, 2010
    Papadopoulos Nikolaos

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General
    Public License along with this library; if not, write to the
    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301 USA

*/

#ifndef LIBNMATH_VECTOR_INL_INCLUDED
#define LIBNMATH_VECTOR_INL_INCLUDED

#ifndef LIBNMATH_VECTOR_H_INCLUDED
    #error "vector.h must be included before vector.inl"
#endif /* LIBNMATH_VECTOR_H_INCLUDED */

#include "types.h"

#ifdef __cplusplus
    #include <cmath>
#else
    #include <math.h>
#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

/* C 2D vector functions */
inline vec2_t vec2_pack(real_t x, real_t y)
{
	vec2_t v;
	v.x = x;
	v.y = y;
	return v;
}

inline vec2_t vec2_add(vec2_t v1, vec2_t v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	return v1;
}

inline vec2_t vec2_sub(vec2_t v1, vec2_t v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	return v1;
}

inline vec2_t vec2_neg(vec2_t v)
{
	v.x = -v.x;
	v.y = -v.y;
	return v;
}

inline vec2_t vec2_mul(vec2_t v1, vec2_t v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	return v1;
}

inline vec2_t vec2_scale(vec2_t v, real_t s)
{
	v.x *= s;
	v.y *= s;
	return v;
}

inline real_t vec2_length(vec2_t v)
{
	return (real_t)sqrt(v.x * v.x + v.y * v.y);
}

inline real_t vec2_length_sq(vec2_t v)
{
	return v.x * v.x + v.y * v.y;
}

inline vec2_t vec2_normalize(vec2_t v)
{
	real_t len = (real_t)sqrt(v.x * v.x + v.y * v.y);
	v.x /= len;
	v.y /= len;
	return v;
}

inline real_t vec2_dot(vec2_t v1, vec2_t v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

inline vec2_t vec2_lerp(vec2_t v1, vec2_t v2, real_t t)
{
	v1.x = v1.x + (v2.x - v1.x) * t;
	v1.y = v1.y + (v2.y - v1.y) * t;
	return v1;
}

inline void vec2_print(FILE *fp, vec2_t v)
{
	fprintf(fp, "[ %.4f %.4f ]", v.x, v.y);
}

/* C 3D vector functions */
inline vec3_t vec3_pack(real_t x, real_t y, real_t z)
{
	vec3_t v;
	v.x = x;
	v.y = y;
	v.z = z;
	return v;
}

inline vec3_t vec3_add(vec3_t v1, vec3_t v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return v1;
}

inline vec3_t vec3_sub(vec3_t v1, vec3_t v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return v1;
}

inline vec3_t vec3_neg(vec3_t v)
{
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	return v;
}

inline vec3_t vec3_mul(vec3_t v1, vec3_t v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return v1;
}

inline vec3_t vec3_scale(vec3_t v1, real_t s)
{
	v1.x *= s;
	v1.y *= s;
	v1.z *= s;
	return v1;
}

inline real_t vec3_length(vec3_t v)
{
	return (real_t)sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline real_t vec3_length_sq(vec3_t v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

inline vec3_t vec3_normalize(vec3_t v)
{
	real_t len = (real_t)sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return v;
}

inline real_t vec3_dot(vec3_t v1, vec3_t v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline vec3_t vec3_cross(vec3_t v1, vec3_t v2)
{
	vec3_t v;
	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return v;
}

inline vec3_t vec3_lerp(vec3_t v1, vec3_t v2, real_t t)
{
	v1.x += (v2.x - v1.x) * t;
	v1.y += (v2.y - v1.y) * t;
	v1.z += (v2.z - v1.z) * t;
	return v1;
}

inline void vec3_print(FILE *fp, vec3_t v)
{
	fprintf(fp, "[ %.4f %.4f %.4f ]", v.x, v.y, v.z);
}

/* C 4D vector functions */
inline vec4_t vec4_pack(real_t x, real_t y, real_t z, real_t w)
{
	vec4_t v;
	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return v;
}

inline vec4_t vec4_add(vec4_t v1, vec4_t v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	v1.w += v2.w;
	return v1;
}

inline vec4_t vec4_sub(vec4_t v1, vec4_t v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	v1.w -= v2.w;
	return v1;
}

inline vec4_t vec4_neg(vec4_t v)
{
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	v.w = -v.w;
	return v;
}

inline vec4_t vec4_mul(vec4_t v1, vec4_t v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	v1.w *= v2.w;
	return v1;
}

inline vec4_t vec4_scale(vec4_t v, real_t s)
{
	v.x *= s;
	v.y *= s;
	v.z *= s;
	v.w *= s;
	return v;
}

inline real_t vec4_length(vec4_t v)
{
	return (real_t)sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

inline real_t vec4_length_sq(vec4_t v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

inline vec4_t vec4_normalize(vec4_t v)
{
	real_t len = (real_t)sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	v.x /= len;
	v.y /= len;
	v.z /= len;
	v.w /= len;
	return v;
}

inline real_t vec4_dot(vec4_t v1, vec4_t v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

inline void vec4_print(FILE *fp, vec4_t v)
{
	fprintf(fp, "[ %.4f %.4f %.4f %.4f ]", v.x, v.y, v.z, v.w);
}

#ifdef __cplusplus
    #include "precision.h"
}	/* extern "C" */

/* Vector2 functions */
inline real_t &Vector2::operator [](unsigned int index)
{
	return index ? y : x;
}

inline const real_t &Vector2::operator [](unsigned int index) const
{
	return index ? y : x;
}

inline const Vector2& Vector2::operator =(const Vector2& v)
{
    x = v.x;
    y = v.y;
    return v;
}

inline const Vector2 operator -(const Vector2& v)
{
	return Vector2(-v.x, -v.y);
}

inline const Vector2 operator +(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x + v2.x, v1.y + v2.y);
}

inline const Vector2 operator -(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x - v2.x, v1.y - v2.y);
}

inline const Vector2 operator *(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x * v2.x, v1.y * v2.y);
}

inline const Vector2 operator /(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x / v2.x, v1.y / v2.y);
}

inline const Vector2 operator +(const Vector2& v, real_t r)
{
	return Vector2(v.x + r, v.y + r);
}

inline const Vector2 operator +(real_t r, const Vector2& v)
{
	return Vector2(v.x + r, v.y + r);
}

inline const Vector2 operator -(const Vector2& v, real_t r)
{
	return Vector2(v.x - r, v.y - r);
}

inline const Vector2 operator *(const Vector2& v, real_t r)
{
	return Vector2(v.x * r, v.y * r);
}

inline const Vector2 operator *(real_t r, const Vector2& v)
{
	return Vector2(v.x * r, v.y * r);
}

inline const Vector2 operator /(const Vector2& v, real_t r)
{
	return Vector2(v.x / r, v.y / r);
}

inline Vector2& operator +=(Vector2& v1, const Vector2& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	return v1;
}

inline Vector2& operator -=(Vector2& v1, const Vector2& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	return v1;
}

inline Vector2& operator *=(Vector2& v1, const Vector2& v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	return v1;
}

inline Vector2& operator /=(Vector2& v1, const Vector2& v2)
{
	v1.x /= v2.x;
	v1.y /= v2.y;
	return v1;
}

inline Vector2& operator +=(Vector2& v, real_t r)
{
	v.x += r;
	v.y += r;
	return v;
}

inline Vector2& operator -=(Vector2& v, real_t r)
{
	v.x -= r;
	v.y -= r;
	return v;
}

inline Vector2& operator *=(Vector2& v, real_t r)
{
	v.x *= r;
	v.y *= r;
	return v;
}

inline Vector2& operator /=(Vector2& v, real_t r)
{
	v.x /= r;
	v.y /= r;
	return v;
}

inline bool operator ==(const Vector2& v1, const Vector2& v2)
{
	return (fabs(v1.x - v2.x) < REAL_T_XXSMALL) && (fabs(v1.y - v2.x) < REAL_T_XXSMALL);
}

inline bool operator !=(const Vector2& v1, const Vector2& v2)
{
	return (fabs(v1.x - v2.x) >= REAL_T_XXSMALL) && (fabs(v1.y - v2.x) >= REAL_T_XXSMALL);
}

inline real_t Vector2::length() const
{
	return (real_t)sqrt(x*x + y*y);
}

inline real_t Vector2::length_squared() const
{
	return x*x + y*y;
}

inline void Vector2::normalize()
{
	real_t len = length();
	x /= len;
	y /= len;
}

inline Vector2 Vector2::normalized() const
{
	real_t len = length();
	return Vector2(x / len, y / len);
}

inline real_t dot(const Vector2& v1, const Vector2& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

/* Vector3 functions */
inline real_t& Vector3::operator [](unsigned int index)
{
	return index ? (index == 1 ? y : z) : x;
}

inline const real_t& Vector3::operator [](unsigned int index) const
{
	return index ? (index == 1 ? y : z) : x;
}

inline const Vector3& Vector3::operator =(const Vector3& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return v;
}

inline const Vector3 operator -(const Vector3& v)
{
	return Vector3(-v.x, -v.y, -v.z);
}

inline const Vector3 operator +(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline const Vector3 operator -(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline const Vector3 operator *(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

inline const Vector3 operator /(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

inline const Vector3 operator +(const Vector3& v, real_t r)
{
	return Vector3(v.x + r, v.y + r, v.z + r);
}

inline const Vector3 operator +(real_t r, const Vector3& v)
{
	return Vector3(v.x + r, v.y + r, v.z + r);
}

inline const Vector3 operator -(const Vector3& v, real_t r)
{
	return Vector3(v.x - r, v.y - r, v.z - r);
}

inline const Vector3 operator *(const Vector3& v, real_t r)
{
	return Vector3(v.x * r, v.y * r, v.z * r);
}

inline const Vector3 operator *(real_t r, const Vector3& v)
{
	return Vector3(v.x * r, v.y * r, v.z * r);
}

inline const Vector3 operator /(const Vector3& v, real_t r)
{
	return Vector3(v.x / r, v.y / r, v.z / r);
}

inline Vector3& operator +=(Vector3& v1, const Vector3& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return v1;
}

inline Vector3& operator -=(Vector3& v1, const Vector3& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return v1;
}

inline Vector3& operator *=(Vector3& v1, const Vector3& v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return v1;
}

inline Vector3& operator /=(Vector3& v1, const Vector3& v2)
{
	v1.x /= v2.x;
	v1.y /= v2.y;
	v1.z /= v2.z;
	return v1;
}

inline Vector3& operator +=(Vector3& v, real_t r)
{
	v.x += r;
	v.y += r;
	v.z += r;
	return v;
}

inline Vector3& operator -=(Vector3& v, real_t r)
{
	v.x -= r;
	v.y -= r;
	v.z -= r;
	return v;
}

inline Vector3& operator *=(Vector3& v, real_t r)
{
	v.x *= r;
	v.y *= r;
	v.z *= r;
	return v;
}

inline Vector3& operator /=(Vector3& v, real_t r)
{
	v.x /= r;
	v.y /= r;
	v.z /= r;
	return v;
}

inline bool operator ==(const Vector3& v1, const Vector3& v2)
{
	return (fabs(v1.x - v2.x) < REAL_T_XXSMALL) && (fabs(v1.y - v2.y) < REAL_T_XXSMALL) && (fabs(v1.z - v2.z) < REAL_T_XXSMALL);
}

inline bool operator !=(const Vector3& v1, const Vector3& v2)
{
	return (fabs(v1.x - v2.x) >= REAL_T_XXSMALL) && (fabs(v1.y - v2.y) >= REAL_T_XXSMALL) && (fabs(v1.z - v2.z) >= REAL_T_XXSMALL);
}

inline real_t Vector3::length() const
{
	return sqrt(x*x + y*y + z*z);
}

inline real_t Vector3::length_squared() const
{
	return x*x + y*y + z*z;
}

inline void Vector3::normalize()
{
	real_t len = length();
	x /= len;
	y /= len;
	z /= len;
}

inline Vector3 Vector3::normalized() const
{
	real_t len = length();
	return Vector3(x / len, y / len, z / len);
}

inline real_t dot(const Vector3& v1, const Vector3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Vector3 cross(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.y * v2.z - v1.z * v2.y,  v1.z * v2.x - v1.x * v2.z,  v1.x * v2.y - v1.y * v2.x);
}

/* Vector4 functions */
inline real_t& Vector4::operator [](unsigned int index)
{
	return index ? (index == 1 ? y : (index == 2 ? z : w)) : x;
}

inline const real_t& Vector4::operator [](unsigned int index) const
{
	return index ? (index == 1 ? y : (index == 2 ? z : w)) : x;
}

inline const Vector4& Vector4::operator =(const Vector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
    return v;
}

inline const Vector4 operator -(const Vector4& v)
{
	return Vector4(-v.x, -v.y, -v.z, -v.w);
}

inline const Vector4 operator +(const Vector4& v1, const Vector4& v2)
{
	return Vector4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

inline const Vector4 operator -(const Vector4& v1, const Vector4& v2)
{
	return Vector4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

inline const Vector4 operator *(const Vector4& v1, const Vector4& v2)
{
	return Vector4(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
}

inline const Vector4 operator /(const Vector4& v1, const Vector4& v2)
{
	return Vector4(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w);
}

inline const Vector4 operator +(const Vector4& v, real_t r)
{
	return Vector4(v.x + r, v.y + r, v.z + r, v.w + r);
}

inline const Vector4 operator +(real_t r, const Vector4& v)
{
	return Vector4(v.x + r, v.y + r, v.z + r, v.w + r);
}

inline const Vector4 operator -(const Vector4& v, real_t r)
{
	return Vector4(v.x - r, v.y - r, v.z - r, v.w - r);
}

inline const Vector4 operator *(const Vector4& v, real_t r)
{
	return Vector4(v.x * r, v.y * r, v.z * r, v.w * r);
}

inline const Vector4 operator *(real_t r, const Vector4& v)
{
	return Vector4(v.x * r, v.y * r, v.z * r, v.w * r);
}

inline const Vector4 operator /(const Vector4& v, real_t r)
{
	return Vector4(v.x / r, v.y / r, v.z / r, v.w / r);
}

inline Vector4& operator +=(Vector4& v1, const Vector4& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	v1.w += v2.w;
	return v1;
}

inline Vector4& operator -=(Vector4& v1, const Vector4& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	v1.w -= v2.w;
	return v1;
}

inline Vector4& operator *=(Vector4& v1, const Vector4& v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	v1.w *= v2.w;
	return v1;
}

inline Vector4& operator /=(Vector4& v1, const Vector4& v2)
{
	v1.x /= v2.x;
	v1.y /= v2.y;
	v1.z /= v2.z;
	v1.w /= v2.w;
	return v1;
}

inline Vector4& operator +=(Vector4& v, real_t r)
{
	v.x += r;
	v.y += r;
	v.z += r;
	v.w += r;
	return v;
}

inline Vector4& operator -=(Vector4& v, real_t r)
{
	v.x -= r;
	v.y -= r;
	v.z -= r;
	v.w -= r;
	return v;
}

inline Vector4& operator *=(Vector4& v, real_t r)
{
	v.x *= r;
	v.y *= r;
	v.z *= r;
	v.w *= r;
	return v;
}

inline Vector4& operator /=(Vector4& v, real_t r)
{
	v.x /= r;
	v.y /= r;
	v.z /= r;
	v.w /= r;
	return v;
}

inline bool operator ==(const Vector4& v1, const Vector4& v2)
{
	return (fabs(v1.x - v2.x) < REAL_T_XXSMALL) && (fabs(v1.y - v2.y) < REAL_T_XXSMALL) && (fabs(v1.z - v2.z) < REAL_T_XXSMALL) && (fabs(v1.w - v2.w) < REAL_T_XXSMALL);;
}

inline bool operator !=(const Vector4& v1, const Vector4& v2)
{
	return (fabs(v1.x - v2.x) >= REAL_T_XXSMALL) && (fabs(v1.y - v2.y) >= REAL_T_XXSMALL) && (fabs(v1.z - v2.z) >= REAL_T_XXSMALL) && (fabs(v1.w - v2.w) >= REAL_T_XXSMALL);
}

inline real_t Vector4::length() const
{
	return sqrt(x*x + y*y + z*z + w*w);
}

inline real_t Vector4::length_squared() const
{
	return x*x + y*y + z*z + w*w;
}

inline void Vector4::normalize()
{
	real_t len = length();
	x /= len;
	y /= len;
	z /= len;
	w /= len;
}

inline Vector4 Vector4::normalized() const
{
	real_t len = length();
	return Vector4(x / len, y / len, z / len, w / len);
}

inline real_t dot(const Vector4& v1, const Vector4& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

#endif /* __cplusplus */

#endif /* LIBNMATH_VECTOR_INL_INCLUDED */
