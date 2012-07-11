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

#include "mutil.h"
#include "vector.h"
#include "cylinder.h"

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

#ifdef __cplusplus
}

Cylinder::Cylinder()
	: Geometry(GEOMETRY_CYLINDER),
	  m_radius(1.0f),
	  m_end_a(-0.5f),
	  m_end_b( 0.5f)
{}

Cylinder::Cylinder(const scalar_t radius, const scalar_t end_a, const scalar_t end_b)
	: Geometry(GEOMETRY_CYLINDER),
	  m_radius(radius > 0.0f ? radius : 0.0f),
	  m_end_a(end_a),
	  m_end_b(end_b)
{}

bool Cylinder::intersection(const Ray &ray, SurfacePoint* sp) const
{
	// Transform ray to local coordinates.
	Matrix4x4f inv_mat = m_matrix.inverse();
	Ray tray = ray.transformed(inv_mat);

	scalar_t a = squared(tray.direction().x) + squared(tray.direction().z);
	scalar_t b = 2.0f * tray.direction().x * tray.origin().x + 2.0f * tray.direction().z * tray.origin().z;
	scalar_t c = squared(tray.origin().x) + squared(tray.origin().z) - squared(radius());
	scalar_t d = squared(b) - 4.0f * a * c;

	if (d < 0.0)
		return false;

	scalar_t sqrt_d = nmath_sqrt(d);
	scalar_t dblf_a = 2.0f * a;
	scalar_t t1 = (-b + sqrt_d) / dblf_a;
	scalar_t t2 = (-b - sqrt_d) / dblf_a;
	
	if (t1 < EPSILON && t2 < EPSILON)
		return false;

	Vector3f pos1 = tray.origin() + tray.direction() * t1;
	Vector3f pos2 = tray.origin() + tray.direction() * t2;

	bool valid[2] = {true, true};

	if (t1 < EPSILON || pos1.y < end_a() || pos1.y >= end_b()) {
		valid[0] = false;
		t1 = t2;
	}

	if (t2 < EPSILON || pos2.y < end_a() || pos2.y >= end_b()) {
		valid[1] = false;
		t2 = t1;
	}

	if (!valid[0] && !valid[1])
		return false;

	if (sp) {
		Matrix4x4f invtransp_mat = inv_mat.transposed();

		sp->distance = t1 < t2 ? t1 : t2;
		sp->position = tray.origin() + tray.direction() * sp->distance;
		sp->normal   = Vector3f(1.0f, 0.0f, 1.0f) * sp->position / radius();
		sp->tangent  = cross(Vector3f(0.0f, 1.0f, 0.0f), sp->normal);

/* 
		// Spherical coords for uv mapping
		SphVector sphv(sp->pos);
		sphv.theta += M_PI;
		sp->texcoord = Vector2(sphv.theta / TWO_PI, sp->pos.y);
*/

		// Transform everything back into world coordinates.
		sp->position.transform(m_matrix);
		sp->normal.transform(invtransp_mat);
		sp->tangent.transform(invtransp_mat);
	}

	return true;
}

void Cylinder::calc_aabb()
{
	/*
		The bounding box is calculated to include 2 spheres
		placed at each end point and with radius equal to 
		the cylinder's radius.
	*/
	Vector3f sph1(0, m_end_a, 0), sph2(0, m_end_b, 0);
	Vector3f rv(radius(), radius(), radius());
	
	// Transform the spheres.
	sph1.transform(matrix());
	sph2.transform(matrix());

	// Find the bounding points for the spheres.
	Vector3f sph1_min = sph1 - rv;
	Vector3f sph1_max = sph1 + rv;
	Vector3f sph2_min = sph2 - rv;
	Vector3f sph2_max = sph2 + rv;

	// Calculate the bounding box.
	Vector3f minv, maxv;
	minv.x = min(sph1_min.x, sph2_min.x);
	minv.y = min(sph1_min.y, sph2_min.y);
	minv.z = min(sph1_min.z, sph2_min.z);
	maxv.x = max(sph1_max.x, sph2_max.x);
	maxv.y = max(sph1_max.y, sph2_max.y);
	maxv.z = max(sph1_max.z, sph2_max.z);

	m_aabb.min = minv;
	m_aabb.max = maxv;
}

#endif	/* __cplusplus */

} /* namespace NMath */
