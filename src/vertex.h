/*

    This file is part of the nemesis math library.

    vertex.h
    Vertex

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

#ifndef LIBNMATH_VERTEX_H_INCLUDED
#define LIBNMATH_VERTEX_H_INCLUDED

#include "precision.h"
#include "vector.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

struct vertex_t {
	vec3_t pos, norm, tang;
	vec2_t tex;
};

#ifdef __cplusplus
}	/* __cplusplus */

struct Vertex {
	Vector3 position, normal, tangent;
	Vector2 texture_uv;
};

#endif	/* __cplusplus */

#endif /* LIBNMATH_VERTEX_H_INCLUDED */
