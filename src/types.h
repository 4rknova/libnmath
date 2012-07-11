/*

	This file is part of libnmath.

	types.h
	Basic data types

	Copyright (C) 2008, 2010 - 2012
	Papadopoulos Nikolaos

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 3 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General
	Public License along with this program; if not, write to the
	Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
	Boston, MA 02110-1301 USA

*/

#ifndef LIBNMATH_TYPES_H_INCLUDED
#define LIBNMATH_TYPES_H_INCLUDED

#include "precision.h"

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Vectors */
struct vec2_t { scalar_t x, y; };
struct vec3_t { scalar_t x, y, z; };
struct vec4_t { scalar_t x, y, z, w; };

typedef struct vec2_t vec2_t;
typedef struct vec3_t vec3_t;
typedef struct vec4_t vec4_t;

/* Matrices */
typedef scalar_t mat3x3_t[3][3];
typedef scalar_t mat4x4_t[4][4];

#ifdef __cplusplus
}   /* extern "C" */

/* C++ equivalents - Forward declarations */
class Vector2f;
class Vector3f;
class Vector4f;

class Matrix3x3f;
class Matrix4x4f;

#endif	/* __cplusplus */

} /* namespace NMath */

#endif /* LIBNMATH_TYPES_H_INCLUDED */
