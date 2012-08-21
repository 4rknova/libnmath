/*

	This file is part of libnmath.

	interpolation.inl
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

#ifndef NMATH_INTERPOLATION_INL_INCLUDED
#define NMATH_INTERPOLATION_INL_INCLUDED

#ifndef NMATH_INTERPOLATION_H_INCLUDED
    #error "interpolation.h must be included before interpolation.inl"
#endif /* NMATH_INTERPOLATION_H_INCLUDED */

#include "precision.h"
#include "defs.h"

namespace NMath {
	namespace Interpolation {

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

static inline scalar_t step(const scalar_t a, const scalar_t b, const scalar_t p)
{
    return (p < 0.5) ? a : b;
}

static inline scalar_t linear(const scalar_t a, const scalar_t b, const scalar_t p)
{
    return  (a * (1 - p)) + (b * p);
}

static inline scalar_t sine(const scalar_t a, const scalar_t b, const scalar_t p)
{
	/*
        First we turn the p value into an angle to sample from the
        sine wave and sample from the wave but converting the
        scale run between 0 and 1 instead of the wave's usual -1 to 1.
        Lastly we perform a normal linear interpolation, but using the
        value from the sine wave instead of the value of the given p
    */

    scalar_t p2 = (1 - nmath_sin(p * PI)) / 2;
	return (a * (1 - p2) + b * p2);
}

static inline scalar_t cosine(const scalar_t a, const scalar_t b, const scalar_t p)
{
	/*
        First we turn the p value into an angle to sample from the
        cosine wave and sample from the wave but converting the
        scale run between 0 and 1 instead of the wave's usual -1 to 1.
        Lastly we perform a normal linear interpolation, but using the
        value from the cosine wave instead of the value of the given p
    */

    scalar_t p2 = (1 - nmath_cos(p * PI)) / 2;
    return (a * (1 - p2) + b * p2);
}

static inline scalar_t acceleration(const scalar_t a, const scalar_t b, const scalar_t p)
{
    scalar_t np = p * p;
    return  (a * (1 - np)) + (b * np);
}

static inline scalar_t deceleration(const scalar_t a, const scalar_t b, const scalar_t p)
{
    scalar_t op = 1 - p;
    scalar_t np = 1 - (op * op);
    return  (a * (1 - np)) + (b * np);
}

static inline scalar_t cubic(const scalar_t a, const scalar_t b, const scalar_t c, const scalar_t d, const scalar_t p)
{
    scalar_t P = (d - c) - (a - b);
	scalar_t Q = (a - b) - P;
	scalar_t R = c - a;
	scalar_t S = b;

	float p2 = p * p;
    float p3 = p2 * p;

	return (P * p3) + (Q * p2) + (R * p) + S;
}

static inline scalar_t hermite(const scalar_t t1, const scalar_t a, const scalar_t b, const scalar_t t2, const scalar_t p)
{
    float p2 = p * p;
    float p3 = p2 * p;

    float h1 = (2 * p3) - (3 * p2) + 1;          /* calculate basis function 1 */
    float h2 = 1 - h1;                           /* calculate basis function 2 */
    float h3 = p3 - (2 * p2) + p;                /* calculate basis function 3 */
    float h4 = p3 - p2;                          /* calculate basis function 4 */

    return (h1 * a) + (h2 * b) + (h3 * t1) + (h4 * t2); /* multiply and sum all functions together */
}

static inline scalar_t cardinal(const scalar_t a, const scalar_t b, const scalar_t c, const scalar_t d, const scalar_t t, const scalar_t p)
{
    scalar_t t2 = t * t;
    scalar_t p3 = p * p * p;

    return t * ( (2 * b) + 	((c - a) * t) + (((2 * a) - (5 * b) + (4 * c) - d) * t2) +(((3 * b) - (3 * c) + d - a) * p3));
}

static inline scalar_t catmullrom(const scalar_t a, const scalar_t b, const scalar_t c, const scalar_t d, const scalar_t p)
{
    /*
        Note
        ----
        CatmullRoms are cardinals with a tension of 0.5
    */
    scalar_t P = - (0.5 * a) + (1.5 * b) - (1.5 * c) + (0.5 * d);
    scalar_t Q = a - (2.5 * b) + (2 * c) - (0.5 * d);
    scalar_t R = ( c - a ) * 0.5;
    scalar_t S = b;

   	float p2 = p * p;
    float p3 = p2 * p;

    return (P * p3) + (Q * p2) + (R * p) + S;
}

static inline scalar_t bezier_quadratic(const scalar_t a, const scalar_t b, const scalar_t c, const scalar_t p)
{
	scalar_t ab, bc;
	ab = linear(a, b, p);
	bc = linear(b, c, p);
	return linear( ab, bc, p);
}

static inline scalar_t bezier_cubic(const scalar_t a, const scalar_t b, const scalar_t c, const scalar_t d, const scalar_t p)
{
	scalar_t ab, bc, cd, abc, bcd;
	ab  = linear(a, b, p);
	bc  = linear(b, c, p);
	cd  = linear(c, d, p);
	abc = linear(ab, bc, p);
	bcd = linear(bc, cd, p);
	return linear( abc, bcd, p);
}

#ifdef __cplusplus
}   /* extern "C" */
#endif

	} /* namespace Interpolation */
} /* namespace NMath */

#endif /* NMATH_INTERPOLATION_INL_INCLUDED */
