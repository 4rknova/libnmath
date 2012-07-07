/*

	This file is part of libnmath.

	precision.h
	Configures compile times precision

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

#ifndef LIBNMATH_PRECISION_H_INCLUDED
#define LIBNMATH_PRECISION_H_INCLUDED

/*
    Define MATH_SINGLE_PRECISION to use single precision math
*/

namespace NMath {

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

#include <float.h>

#ifdef MATH_SINGLE_PRECISION
	#define SCALAR_T_MAX FLT_MAX
	typedef float scalar_t;

#else
    #define SCALAR_T_MAX DBL_MAX
    typedef double scalar_t;

#endif /* MATH_SINGLE_PRECISION */

/* Infinity */
#define NM_INFINITY SCALAR_T_MAX

#ifndef INFINITY
	#define INFINITY NM_INFINITY
#endif /* INFINITY */

/* Useful float values used in comparisons */
#define SCALAR_T_MEDIUM   1.e-2   /* 0.01 */
#define SCALAR_T_SMALL    1.e-4   /* 0.0001 */
#define SCALAR_T_XSMALL   1.e-6   /* 0.000001 */
#define SCALAR_T_XXSMALL  1.e-8   /* 0.00000001 */

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */

} /* namespace NMath */

#endif /* LIBNMATH_PRECISION_H_INCLUDED */
