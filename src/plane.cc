/*

	This file is part of libnmath.

	plane.cc
	Plane

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

#include "defs.h"
#include "vector.h"
#include "surfpoint.h"
#include "plane.h"

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

#ifdef __cplusplus
}

Plane::Plane()
	: Geometry(GEOMETRY_PLANE),
	  m_normal(Vector3f(0.0f, 1.0f, 0.0f)),
	  m_distance(0.0f)
{}

Plane::Plane(const Vector3f &normal, scalar_t distance)
	: Geometry(GEOMETRY_PLANE),
	  m_normal(normal),
	  m_distance(distance)
{}

bool Plane::intersection(const Ray &ray, SurfacePoint* sp) const
{
	// Transform ray to local coordinates.
	Matrix4x4f inv_mat = m_matrix.inverse();
	Ray tray = ray.transformed(inv_mat);

	// Check if the ray is travelling parallel to the plane.
	// If the ray is in the plane then we ignore it.
	scalar_t n_dot_dir = dot(tray.direction(), normal());

	// The planes are treated as two-sided so the sign of n_dot_dir is ignored.
	if (fabs(n_dot_dir) < EPSILON) 
		return false;
	
	Vector3f v = normal() * distance();
	Vector3f vorigin = v - tray.origin();

	scalar_t n_dot_vo = dot(vorigin, normal());
	scalar_t t = n_dot_vo / n_dot_dir; 

	if (t < EPSILON) 
		return false;

	if (sp) 
	{
		Matrix4x4f invtransp_mat = inv_mat.transposed();

		sp->distance = t;
		sp->position = tray.origin() + tray.direction() * sp->distance;
		sp->normal   = dot(normal(), tray.direction()) < 0 ? normal() : -normal();
		sp->tangent  = cross(Vector3f(0.0f, 1.0f, 0.0f), sp->normal);
	/*
		// UV coords for tecture mapping.
		sp->texcoord =
	*/

		 // Transform everything back into world coordinates.
		 sp->position.transform(m_matrix);
		 sp->normal.transform(invtransp_mat);
		 sp->tangent.transform(invtransp_mat);
	}

	return true;
}

void Plane::calc_aabb()
{
	// The plane is infinite so the bounding box is infinity as well
	// This violates the cases in which the plane is parallel to an
	// axis plane but it's not practical to include those cases.
	m_aabb.min = Vector3f(-INFINITY, -INFINITY, -INFINITY);
	m_aabb.max = Vector3f( INFINITY,  INFINITY,  INFINITY);
}

#endif	/* __cplusplus */

} /* namespace NMath */
