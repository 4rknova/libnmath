/*

	This file is part of libnmath.

	interpolation.h
	Interpolation methods

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

/*
    TO DO:
    - TCB spline (Kochanek-Bartels)
    - Beta splines
    - Uniform nonrational splines
*/

#ifndef LIBNMATH_INTERPOLATION_H_INCLUDED
#define LIBNMATH_INTERPOLATION_H_INCLUDED

#include "types.h"

namespace NMath {
	namespace Interpolation {

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

/* Simple */
static inline scalar_t step(scalar_t a, scalar_t b, scalar_t p);
static inline scalar_t linear(scalar_t a, scalar_t b, scalar_t p);
static inline scalar_t cosine(scalar_t a, scalar_t b, scalar_t p);

/* Polynomial */
static inline scalar_t acceleration(scalar_t a, scalar_t b, scalar_t p);
static inline scalar_t deceleration(scalar_t a, scalar_t b, scalar_t p);
static inline scalar_t cubic(scalar_t a, scalar_t b, scalar_t c, scalar_t d, scalar_t p);

/* Splines */
static inline scalar_t hermite(scalar_t t1, scalar_t a, scalar_t b, scalar_t t2, scalar_t p);
static inline scalar_t cardinal(scalar_t a, scalar_t b, scalar_t c, scalar_t d, scalar_t t, scalar_t p);
static inline scalar_t catmullrom(scalar_t a, scalar_t b, scalar_t c, scalar_t d, scalar_t p);

/* Bezier */
static inline scalar_t bezier_quadratic(scalar_t a, scalar_t b, scalar_t c, scalar_t p);		 /* DeCasteljau */
static inline scalar_t bezier_cubic(scalar_t a, scalar_t b, scalar_t c, scalar_t d, scalar_t p); /* DeCasteljau */

#ifdef __cplusplus
}   /* extern "C" */
#endif

	} /* namespace Interpolation */
} /* namespace NMath */

#include "interpolation.inl"

#endif /* LIBNMATH_INTERPOLATION_H_INCLUDED */
