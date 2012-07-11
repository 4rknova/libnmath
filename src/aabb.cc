/*

	This file is part of libnmath.

	aabb.cc
	Axis Aligned Bounding Box

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

#include "aabb.h"

namespace NMath {

#ifdef __cplusplus

/* AABoundingBox2 class */
AABoundingBox2::AABoundingBox2()
	: min(Vector2f(0.0f, 0.0f)),
	  max(Vector2f(0.0f, 0.0f))
{}

AABoundingBox2::AABoundingBox2(const Vector2f& a, const Vector2f& b)
	: min(Vector2f((a.x <= b.x) ? a.x : b.x, (a.y <= b.y) ? a.y : b.y)),
	  max(Vector2f((a.x >= b.x) ? a.x : b.x, (a.y >= b.y) ? a.y : b.y))
{}

/* AABoundingBox3 class */
AABoundingBox3::AABoundingBox3()
	: min(Vector3f(0.0f, 0.0f)),
	  max(Vector3f(0.0f, 0.0f))
{}

AABoundingBox3::AABoundingBox3(const Vector3f& a, const Vector3f& b)
	: min(Vector3f((a.x <= b.x) ? a.x : b.x, (a.y <= b.y)? a.y : b.y, (a.z <= b.z)? a.z : b.z)),
	  max(Vector3f((a.x >= b.x) ? a.x : b.x, (a.y >= b.y)? a.y : b.y, (a.z >= b.z)? a.z : b.z))
{}

/* 	
	ray - axis aligned bounding box intersection test based on:
	"An Efficient and Robust Ray-Box Intersection Algorithm",
	Amy Williams, Steve Barrus, R. Keith Morley, and Peter Shirley
	Journal of graphics tools, 10(1):49-54, 2005
*/
bool AABoundingBox3::intersection(const Ray &ray) const
{
	// Check if the origin is inside the aabb.
	if (ray.origin() > min && ray.origin() < max)
		return true;

	Vector3f aabb[2] = {min, max};

	int xsign = (int)(ray.direction().x < 0.0f);
	scalar_t invdirx = 1.0f / ray.direction().x;

	scalar_t tmin = (aabb[xsign].x - ray.origin().x) * invdirx;
	scalar_t tmax = (aabb[1 - xsign].x - ray.origin().x) * invdirx;

	int ysign = (int)(ray.direction().y < 0.0f);
	scalar_t invdiry = 1.0f / ray.direction().y;
	scalar_t tymin = (aabb[ysign].y - ray.origin().y) * invdiry;
	scalar_t tymax = (aabb[1 - ysign].y - ray.origin().y) * invdiry;
	
	if ((tmin > tymax) || (tymin > tmax))
		return false;

	if (tymin > tmin) tmin = tymin;
	if (tymax < tmax) tmax = tymax;

	int zsign = (int)(ray.direction().z < 0.0f);
	scalar_t invdirz = 1.0f / ray.direction().z;
	scalar_t tzmin = (aabb[zsign].z - ray.origin().z) * invdirz;
	scalar_t tzmax = (aabb[1 - zsign].z - ray.origin().z) * invdirz;

	if ((tmin > tzmax) || (tzmin > tmax))
		return false;

	if (tzmin > tmin) tmin = tzmin;
	if (tzmax < tmax) tmax = tzmax;

	return (tmax > 0.0f);
}

#endif	/* __cplusplus */

} /* namespace NMath */
