/*

    This file is part of the nemesis math library.

    sphere.h
    Sphere

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

#ifndef LIBNMATH_SPHERE_H_INCLUDED
#define LIBNMATH_SPHERE_H_INCLUDED

#include "types.h"
#include "vector.h"

typedef struct
{
    vec3_t origin;
    real_t radius;
} sphere_t;

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

static inline sphere_t sphere_pack(vec3_t origin, real_t radius);

#ifdef __cplusplus
}	/* __cplusplus */

#define SPHERE_DEFAULT_RADIUS 1.0

class Sphere
{
    public:
        Sphere();                               // This relies on vector class default constructor setting all components to 0
        Sphere(const Vector3 &org, real_t rad);

        Vector3 origin;
        real_t radius;
};

#endif	/* __cplusplus */

#include "sphere.inl"

#endif /* LIBNMATH_SPHERE_H_INCLUDED */
