/*

	This file is part of libnmath.

	sphere.cc
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

#include "precision.h"
#include "sphere.h"

namespace NMath {

#ifdef __cplusplus

Sphere::Sphere()
    : Geometry(GEOMETRY_SPHERE), 
	  m_radius(1.0f)
{}

Sphere::Sphere(const Vector3f &org, scalar_t rad)
    : Geometry(GEOMETRY_SPHERE),
	  m_radius(rad > 0 ? rad : 0.0f)
{}

bool Sphere::intersection(const Ray &ray, SurfacePoint * sp) const
{
	// Transform ray to local coordinates.
 	Matrix4x4f inv_mat = m_matrix.inverse();
	Ray tray = ray.transformed(inv_mat);

	scalar_t a = dot(tray.direction(), tray.direction());
	scalar_t b = 2.0f * tray.direction().x * tray.origin().x + 
				 2.0f * tray.direction().y * tray.origin().y +
				 2.0f * tray.direction().z * tray.origin().z;
	scalar_t c = dot(tray.origin(), tray.origin()) - squared(radius());
	scalar_t d = squared(b) - 4.0f * a * c;

	if (d < 0.0f)
		return false;

	scalar_t sqrt_d = nmath_sqrt(d);
	scalar_t dblf_a = 2.0f * a;
	scalar_t t1 = (-b + sqrt_d) / dblf_a;
	scalar_t t2 = (-b - sqrt_d) / dblf_a;

	if (t1 < EPSILON && t2 < EPSILON)
		return false;


	if (sp) {
		Matrix4x4f invtransp_mat = inv_mat.transposed();

		if (t1 < EPSILON) t1 = t2;
		if (t2 < EPSILON) t2 = t1;

		sp->distance = t1 < t2 ? t1 : t2;
		sp->position = tray.origin() + tray.direction() * sp->distance;
		sp->normal   = sp->position / radius();
		sp->tangent  = cross(Vector3f(0.0f, 1.0f, 0.0f), sp->normal);
/*
		SphVector sphv(pt->pos);
		sphv.theta += M_PI;
		sp->texcoord = Vector2(sphv.theta / TWO_PI, sphv.phi / M_PI);
*/
		// Transform everything back into world coordinates
		sp->position.transform(m_matrix);
		sp->normal.transform(invtransp_mat);
		sp->tangent.transform(invtransp_mat);
	}

	return true;
}

void Sphere::calc_aabb()
{
	Vector3f pos = Vector3f(0.0f, 0.0f, 0.0f).transformed(matrix());
	Vector3f rv(radius(), radius(), radius());

	m_aabb.min = pos - rv;
	m_aabb.max = pos + rv;
}

#endif	/* __cplusplus */

} /* namespace NMath */
