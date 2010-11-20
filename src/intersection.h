/*

    This file is part of the nemesis math library.

    intersection.h
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

/*
    NOTES
    -----

    - For ray-object intersection tests, the result is expressed as a scalar t.
      To calculate the corresponding vertex, multiply the ray's direction vector by t.
*/

#ifndef LIBNMATH_INTERSECTION_H_INCLUDED
#define LIBNMATH_INTERSECTION_H_INCLUDED

#include "sphere.h"
#include "ray.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

real_t intersect_ray_sphere(ray_t r, sphere_t s);

#ifdef __cplusplus
}   /* extern "C" */

real_t intersect_ray_sphere(const Ray &r, const Sphere &s);

#endif

#endif /* LIBNMATH_INTERSECTION_H_INCLUDED */
