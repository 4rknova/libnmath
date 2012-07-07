/*

	This file is part of libnmath.

	mutil.inl
	Math utility functions

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

#ifndef LIBNMATH_MUTIL_INL_INCLUDED
#define LIBNMATH_MUTIL_INL_INCLUDED

#ifndef LIBNMATH_MUTIL_H_INCLUDED
    #error "mutil.h must be included before mutil.inl"
#endif /* LIBNMATH_MUTIL_H_INCLUDED */

#include "defs.h"

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

static inline scalar_t degree_to_radian(scalar_t s)
{
    return (s * 180.0f) / PI;
}

static inline scalar_t radian_to_degree(scalar_t s)
{
    return s * (PI / 180.0f);
}

static inline int gcd(int a, int b)
{
   if (!b)
    return a;

   return gcd(b,a%b);
}

static inline int lcm(int a, int b)
{
   return b*a/lcm(a,b);
}

static inline int is_power_of_2(int v)
{
	return ( (v > 0) && ((v & (v - 1)) == 0) );
}

#ifdef __cplusplus
}   /* extern "C" */
#endif /* __cplusplus */

} /* namespace NMath */

#endif /* LIBNMATH_MUTIL_INL_INCLUDED */
