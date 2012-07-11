/*

	This file is part of libnmath.

	cylinder.h
	Cylinder

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

#ifndef LIBNMATH_CYLINDER_H_INCLUDED
#define LIBNMATH_CYLINDER_H_INCLUDED

#include "declspec.h"
#include "precision.h"
#include "geometry.h"
#include "surfpoint.h"
#include "ray.h"

namespace NMath {

struct cylinder_t
{
    scalar_t radius;
    scalar_t end_a, end_b;
};

typedef struct cylinder_t cylinder_t;

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

static inline cylinder_t cylinder_pack(const scalar_t radius, const scalar_t end_a, const scalar_t end_b);

#ifdef __cplusplus
}	/* __cplusplus */

class DECLSPEC Cylinder: public Geometry
{
	public:
		Cylinder();
		Cylinder(const scalar_t radius, const scalar_t end_a, const scalar_t end_b);

		inline scalar_t radius() const;
		inline scalar_t end_a() const;
		inline scalar_t end_b() const;

		inline void radius(const scalar_t radius);
		inline void end_a(const scalar_t end_a);
		inline void end_b(const scalar_t end_b);
	
		// NOTE:
		// If sp == NULL, the intersection point is not calculated.
		bool intersection(const Ray &ray, SurfacePoint* sp) const; 

	private:
		void calc_aabb();

		scalar_t m_radius;
		scalar_t m_end_a, m_end_b; 
};

#endif	/* __cplusplus */

} /* namespace NMath */

#include "cylinder.inl"

#endif /* LIBNMATH_PLANE_H_INCLUDED */
