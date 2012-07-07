/*

	This file is part of libnmath.

	ray.h
	Ray

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

#ifndef LIBNMATH_RAY_H_INCLUDED
#define LIBNMATH_RAY_H_INCLUDED

#include "types.h"
#include "vector.h"

#include "declspec.h"

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

struct ray_t
{
    vec3_t origin, direction;
};

typedef struct ray_t ray_t;

static inline ray_t ray_pack(vec3_t origin, vec3_t direction);

#ifdef __cplusplus
}	/* __cplusplus */

class DECLSPEC Ray
{
    public:
        Ray();                                          /* This relies on vector class default constructor setting all components to 0 */
        Ray(const Vector3f &org, const Vector3f &dir);

        Vector3f origin, direction;
};

#endif	/* __cplusplus */

} /* namespace NMath */

#include "ray.inl"

#endif /* LIBNMATH_RAY_H_INCLUDED */
