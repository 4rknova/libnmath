/*

    This file is part of the nemesis math library.

    triangle.cc
    Triangle

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

#include "triangle.h"

#include "defs.h"
#include "precision.h"
#include "vector.h"
#include "intinfo.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

#ifdef __cplusplus
}

Triangle::Triangle()
	:	Geometry(GEOMETRY_TRIANGLE)
{}

bool Triangle::intersection(const Ray &ray, IntInfo* i_info) const
{

#ifdef NMATH_USE_BBOX_INTERSECTION
	if(!aabb.intersection(ray))
	{
		return false;
	}
#endif

	// find vectors for two edges shading v0
	Vector3 v1 = v[2].position - v[0].position;
	Vector3 v2 = v[1].position - v[0].position;

	Vector3 normal = cross(v1, v2);

	double n_dot_dir = dot(normal, ray.direction);
	if(fabs(n_dot_dir) < EPSILON) 
	{
		return false; // parallel to the plane
	}

	// translation of v[0] to axis origin
	Vector3 vo_vec = ray.origin - v[0].position;

	// calc intersection distance
	real_t t = -dot(normal, vo_vec) / n_dot_dir;
	if(t < EPSILON)
	{
		return false; // plane in the opposite subspace
	}

	// intersection point ( on the plane ).
	Vector3 pos = ray.origin + ray.direction * t;

	// Check for triangle boundaries
	for(int i=0; i<3; i++) 
	{
		Vector3 test = cross(v[(i + 1) % 3].position - v[i].position, pos - v[i].position);
		bool bounds = (-dot(test, normal) >= 0.0);
		if(!bounds)
		{
			return false;   // outside of the triangle
		}
	}
	
	if (i_info)
	{
		i_info->t = t;
		i_info->point = pos;

		Vertex v;

		if(v.normal.length_squared() < REAL_T_XSMALL)
		{
			i_info->normal = -normal.normalized();
		} 
		else 
		{
			i_info->normal = -v.normal.normalized();
		}

		i_info->geometry = this;
	}

	return true;
}

void Triangle::calc_aabb()
{
	aabb.max = Vector3(-NM_INFINITY, -NM_INFINITY, -NM_INFINITY);
	aabb.min = Vector3(NM_INFINITY, NM_INFINITY, NM_INFINITY);

	for(unsigned int i=0; i<3; i++)
	{
		Vector3 pos = v[i].position;
		if(pos.x < aabb.min.x) aabb.min.x = pos.x;
		if(pos.y < aabb.min.y) aabb.min.y = pos.y;
		if(pos.z < aabb.min.z) aabb.min.z = pos.z;

		if(pos.x > aabb.max.x) aabb.max.x = pos.x;
		if(pos.y > aabb.max.y) aabb.max.y = pos.y;
		if(pos.z > aabb.max.z) aabb.max.z = pos.z;
	}
}

Vector3 Triangle::calc_normal()
{
	Vector3 v1 = v[2].position - v[0].position;
	Vector3 v2 = v[1].position - v[0].position;

	return cross(v1, v2).normalized();
}

#endif	/* __cplusplus */
