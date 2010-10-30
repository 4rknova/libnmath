/*

    This file is part of the Nemesis3dMath library.

    intersection.cc
    Intersection testing

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

#include "intersection.h"
#include "precision.h"

#ifdef __cplusplus
    #include <cmath>
#else
    #include <math.h>
#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

real_t intersect_ray_sphere(ray_t r, sphere_t s)
{
    vec3_t dst = vec3_sub(r.origin, s.origin);
	float B = vec3_dot(dst, r.direction);
	float C = vec3_dot(dst, dst) - (s.radius * s.radius);
	float D = B*B - C;
	return ( D > 0 ) ? -B - sqrt(D) : NM_INFINITY;
}

#ifdef __cplusplus
}   /* extern "C" */

real_t intersect_ray_sphere(const Ray &r, const Sphere &s)
{
    Vector3 dst = r.origin - s.origin;
	float B = dot(dst, r.direction);
	float C = dot(dst, dst) - (s.radius * s.radius);
	float D = B*B - C;
	return ( D > 0 ) ? -B - sqrt(D) : NM_INFINITY;
}

#endif
