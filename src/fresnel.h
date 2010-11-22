/*

    This file is part of the nemesis math library.

    fresnel.h
    Fresnel equations

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

#ifndef LIBNMATH_FRESNEL_H_INCLUDED
#define LIBNMATH_FRESNEL_H_INCLUDED

#include "precision.h"
#include "mutil.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

/*

	NOTES
	-----

	All angles are expected to be greater than zero and less than 90 degrees.

	[ 0 > angle > pi/2 ]

*/

enum
{
	FRESNEL_HORIZONTAL,
	FRESNEL_VERTICAL,
	FRESNEL_MEDIAN
};

static inline real_t fresnel_reflection(real_t ior_src, real_t ior_dst, real_t cos_i, real_t cos_t, int compo = FRESNEL_MEDIAN);
static inline real_t fresnel_refraction(real_t ior_src, real_t ior_dst, real_t cos_i, real_t cos_t);

#ifdef __cplusplus
}   /* extern "C" */
#endif	/* __cplusplus */

#include "fresnel.inl"

#endif /* LIBNMATH_FRESNEL_H_INCLUDED */
