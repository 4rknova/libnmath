/*

    This file is part of the nemesis math library.

    shade.inl
    Shading models, inline functions

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

#ifndef LIBNMATH_SHADE_INL_INCLUDED
#define LIBNMATH_SHADE_INL_INCLUDED

#ifndef LIBNMATH_SHADE_H_INCLUDED
    #error "shade.h must be included before shade.inl"
#endif /* LIBNMATH_SHADE_H_INCLUDED */

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

static inline rgba_t shade_lambert(rgba_t surface_color, vec3_t normal, vec3_t light_dir)
{
	real_t intensity = vec3_dot(vec3_normalize(normal), vec3_normalize(light_dir));
	return rgba_scale(surface_color, intensity);
}

#ifdef __cplusplus
}   /* extern "C" */

inline Rgba shade_lambert(const Rgba &surface_color, const Vector3 &normal, const Vector3 &light_dir)
{
	real_t intensity = dot(normal.normalized(), light_dir.normalized());
	return intensity * surface_color;
}

#endif

#endif /* LIBNMATH_SHADE_INL_INCLUDED */
