/*

	This file is part of libnmath.

	interpolation.h
	Interpolation methods

	Copyright (C) 2008, 2010 - 2013
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

#ifndef NMATH_INTERPOLATION_H_INCLUDED
#define NMATH_INTERPOLATION_H_INCLUDED

#include "defs.h"
#include "types.h"
#include "vector.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

namespace NMath {
	namespace Interpolation {

static inline scalar_t smoothstep(scalar_t a, scalar_t b, scalar_t t);
static inline scalar_t smoothstep_perlin(scalar_t a, scalar_t b, scalar_t t);

static inline scalar_t step(scalar_t a, scalar_t b, scalar_t t);
static inline scalar_t linear(scalar_t a, scalar_t b, scalar_t t);
static inline scalar_t cosine(scalar_t a, scalar_t b, scalar_t t);
static inline scalar_t acceleration(scalar_t a, scalar_t b, scalar_t t);
static inline scalar_t deceleration(scalar_t a, scalar_t b, scalar_t t);

static inline scalar_t cubic(scalar_t a, scalar_t b, scalar_t c, scalar_t d, scalar_t t);
static inline scalar_t hermite(scalar_t tang1, scalar_t a, scalar_t b, scalar_t tang2, scalar_t t);
static inline scalar_t cardinal(scalar_t a, scalar_t b, scalar_t c, scalar_t d, scalar_t p, scalar_t t);
static inline scalar_t catmullrom(scalar_t a, scalar_t b, scalar_t c, scalar_t d, scalar_t t);

static inline scalar_t bezier_quadratic(scalar_t a, scalar_t b, scalar_t c, scalar_t t);
static inline scalar_t bezier_cubic(scalar_t a, scalar_t b, scalar_t c, scalar_t d, scalar_t t);


	} /* namespace Interpolation */
} /* namespace NMath */

#ifdef __cplusplus
}   /* extern "C" */

namespace NMath {
	namespace Interpolation {

inline Vector2f smoothstep(Vector2f a, Vector2f b, scalar_t t);
inline Vector3f smoothstep(Vector3f a, Vector3f b, scalar_t t);
inline Vector4f smoothstep(Vector4f a, Vector4f b, scalar_t t);

inline Vector2f smoothstep_perlin(Vector2f a, Vector2f b, scalar_t t);
inline Vector3f smoothstep_perlin(Vector3f a, Vector3f b, scalar_t t);
inline Vector4f smoothstep_perlin(Vector4f a, Vector4f b, scalar_t t);

inline Vector2f step(Vector2f a, Vector2f b, scalar_t p);
inline Vector3f step(Vector3f a, Vector3f b, scalar_t p);
inline Vector4f step(Vector4f a, Vector4f b, scalar_t p);

inline Vector2f linear(Vector2f a, Vector2f b, scalar_t p);
inline Vector3f linear(Vector3f a, Vector3f b, scalar_t p);
inline Vector4f linear(Vector4f a, Vector4f b, scalar_t p);

inline Vector2f cosine(Vector2f a, Vector2f b, scalar_t p);
inline Vector3f cosine(Vector3f a, Vector3f b, scalar_t p);
inline Vector4f cosine(Vector4f a, Vector4f b, scalar_t p);

inline Vector2f acceleration(Vector2f a, Vector2f b, scalar_t p);
inline Vector3f acceleration(Vector3f a, Vector3f b, scalar_t p);
inline Vector4f acceleration(Vector4f a, Vector4f b, scalar_t p);

inline Vector2f deceleration(Vector2f a, Vector2f b, scalar_t p);
inline Vector3f deceleration(Vector3f a, Vector3f b, scalar_t p);
inline Vector4f deceleration(Vector4f a, Vector4f b, scalar_t p);

inline Vector2f cubic(Vector2f a, Vector2f b, Vector2f c, Vector2f d, scalar_t p);
inline Vector3f cubic(Vector3f a, Vector3f b, Vector3f c, Vector3f d, scalar_t p);
inline Vector4f cubic(Vector4f a, Vector4f b, Vector4f c, Vector4f d, scalar_t p);

inline Vector2f hermite(Vector2f t1, Vector2f a, Vector2f b, Vector2f t2, scalar_t p);
inline Vector3f hermite(Vector3f t1, Vector3f a, Vector3f b, Vector3f t2, scalar_t p);
inline Vector4f hermite(Vector4f t1, Vector4f a, Vector4f b, Vector4f t2, scalar_t p);

inline Vector2f cardinal(Vector2f a, Vector2f b, Vector2f c, Vector2f d, scalar_t t, scalar_t p);
inline Vector3f cardinal(Vector3f a, Vector3f b, Vector3f c, Vector3f d, scalar_t t, scalar_t p);
inline Vector4f cardinal(Vector4f a, Vector4f b, Vector4f c, Vector4f d, scalar_t t, scalar_t p);

inline Vector2f catmullrom(Vector2f a, Vector2f b, Vector2f c, Vector2f d, scalar_t p);
inline Vector3f catmullrom(Vector3f a, Vector3f b, Vector3f c, Vector3f d, scalar_t p);
inline Vector4f catmullrom(Vector4f a, Vector4f b, Vector4f c, Vector4f d, scalar_t p);

inline Vector2f bezier_quadratic(Vector2f a, Vector2f b, Vector2f c, scalar_t p);
inline Vector3f bezier_quadratic(Vector3f a, Vector3f b, Vector3f c, scalar_t p);
inline Vector4f bezier_quadratic(Vector4f a, Vector4f b, Vector4f c, scalar_t p);

inline Vector2f bezier_cubic(Vector2f a, Vector2f b, Vector2f c, Vector2f d, scalar_t p);
inline Vector3f bezier_cubic(Vector3f a, Vector3f b, Vector3f c, Vector3f d, scalar_t p);
inline Vector4f bezier_cubic(Vector4f a, Vector4f b, Vector4f c, Vector4f d, scalar_t p);

	} /* namespace Interpolation */
} /* namespace NMath */

#endif /* __cplusplus */

#include "interpolation.inl"

#endif /* NMATH_INTERPOLATION_H_INCLUDED */
