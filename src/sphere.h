/*

	This file is part of libnmath.

	sphere.h
	Sphere

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

#ifndef LIBNMATH_SPHERE_H_INCLUDED
#define LIBNMATH_SPHERE_H_INCLUDED

#include "declspec.h"
#include "precision.h"
#include "vector.h"
#include "geometry.h"
#include "surfpoint.h"
#include "ray.h"

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

struct sphere_t
{
    vec3_t origin;
    scalar_t radius;
};

typedef struct sphere_t sphere_t;

static inline sphere_t sphere_pack(vec3_t origin, scalar_t radius);

#ifdef __cplusplus
}	/* __cplusplus */

class DECLSPEC Sphere: public Geometry
{
    public:
        Sphere();
        Sphere(const Vector3f &org, scalar_t rad);

		inline scalar_t radius() const;
		inline void radius(const scalar_t radius);

		// NOTE:
		// If sp == NULL, the intersection point is not calculated.
		bool intersection(const Ray &ray, SurfacePoint * sp) const;

	private:
		void calc_aabb();
        
		scalar_t m_radius;
};

#endif	/* __cplusplus */

} /* namespace NMath */

#include "sphere.inl"

#endif /* LIBNMATH_SPHERE_H_INCLUDED */
