/*

    This file is part of the nemesis math library.

    fresnel.inl
    Fresnel equations inline functions

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

#ifndef LIBNMATH_FRESNEL_INL_INCLUDED
#define LIBNMATH_FRESNEL_INL_INCLUDED

#ifndef LIBNMATH_FRESNEL_H_INCLUDED
    #error "fresnel.h must be included before fresnel.inl"
#endif /* LIBNMATH_FRESNEL_H_INCLUDED */

#include "precision.h"
#include "mutil.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

static inline real_t fresnel_reflection(real_t ior_src, real_t ior_dst, real_t cos_i, real_t cos_t, int compo)
{
	real_t val = 0.f;

	switch(compo)
	{
		case FRESNEL_HORIZONTAL:
			val = ((ior_dst * cos_i) - (ior_src * cos_t)) / ((ior_dst * cos_i) + (ior_src * cos_t));
		case FRESNEL_VERTICAL:
			val = ((ior_src * cos_i) - (ior_dst * cos_t)) / ((ior_src * cos_i) + (ior_dst * cos_t));
		default:
			val = ((ior_src * cos_i) - (ior_dst * cos_t)) / ((ior_src * cos_i) + (ior_dst * cos_t));
			val += ((ior_dst * cos_i) - (ior_src * cos_t)) / ((ior_dst * cos_i) + (ior_src * cos_t));
			val /= 2.f;
	}

	return val;
}

static inline real_t fresnel_refraction(real_t ior_src, real_t ior_dst, real_t cos_i, real_t cos_t)
{
	return 1.f - fresnel_reflection(ior_src, ior_dst, cos_i, cos_t);
}

#ifdef __cplusplus
}	/* extern "C" */
#endif /* __cplusplus */

#endif /* LIBNMATH_FRESNEL_INL_INCLUDED */
