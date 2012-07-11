/*

	This file is part of libnmath.

	geometry.h
	Geometry

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

#ifndef LIBNMATH_GEOMETRY_H_INCLUDED
#define LIBNMATH_GEOMETRY_H_INCLUDED

#include "declspec.h"
#include "aabb.h"
#include "matrix.h"
#include "ray.h"
#include "surfpoint.h"

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

enum NMATH_GEOMETRY_TYPE
{
	GEOMETRY_PLANE,
	GEOMETRY_TRIANGLE,
	GEOMETRY_SPHERE,
	GEOMETRY_CYLINDER,	
	GEOMETRY_MESH
};

#ifdef __cplusplus
}	/* extern C */

// forward declaration
class IntInfo;

class DECLSPEC Geometry
{
    public:
		Geometry(NMATH_GEOMETRY_TYPE t);
		virtual ~Geometry();

		NMATH_GEOMETRY_TYPE type();
		Matrix4x4f &matrix();
		const AABoundingBox3 &aabb();

		virtual bool intersection(const Ray &ray, SurfacePoint * sp) const = 0;

	protected:
		virtual void calc_aabb() = 0;

		Matrix4x4f m_matrix;
		AABoundingBox3 m_aabb;
		const NMATH_GEOMETRY_TYPE m_type;
};

#endif	/* __cplusplus */

} /* namespace NMath */

#endif /* LIBNMATH_GEOMETRY_H_INCLUDED */
