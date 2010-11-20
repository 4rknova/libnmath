/*

    This file is part of the nemesis math library.

    interpolation.inl
    Interpolation inline functions

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

#ifndef LIBNMATH_INTERPOLATION_INL_INCLUDED
#define LIBNMATH_INTERPOLATION_INL_INCLUDED

#ifndef LIBNMATH_INTERPOLATION_H_INCLUDED
    #error "interpolation.h must be included before interpolation.inl"
#endif /* LIBNMATH_INTERPOLATION_H_INCLUDED */

#include "precision.h"
#include "defs.h"

#ifdef __cplusplus
    #include <cmath>
#else
    #include <math.h>
#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

static inline real_t interp_step(real_t a, real_t b, real_t p)
{
    return (p < .5f) ? a : b;
}

static inline real_t interp_linear(real_t a, real_t b, real_t p)
{
    return  (a * (1.f - p)) + (b * p);
}

static inline real_t interp_cosine(real_t a, real_t b, real_t p)
{
    /*
        First we turn the p value into an angle to sample from the
        cosine wave and sample from the wave but converting the
        scale run between 0 and 1 instead of the wave's usual -1 to 1.
        Lastly we perform a normal linear interpolation, but using the
        value from the cosine wave instead of the value of the given p
    */

    real_t p2 = (1.f - cos(p * PI)) / 2;
    return(a * (1 - p2) + b * p2);
}

static inline real_t interp_acceleration(real_t a, real_t b, real_t p)
{
    real_t np = p * p;
    return  (a * (1.f - np)) + (b * np);
}

static inline real_t interp_deceleration(real_t a, real_t b, real_t p)
{
    real_t op = 1 - p;
    real_t np = 1 - (op * op);
    return  (a * (1.f - np)) + (b * np);
}

static inline real_t interp_cubic(real_t a, real_t b, real_t c, real_t d, real_t p)
{
    real_t P = (d - c) - (a - b);
	real_t Q = (a - b) - P;
	real_t R = c - a;
	real_t S = b;

	float p2 = p * p;
    float p3 = p2 * p;

	return (P * p3) + (Q * p2) + (R * p) + S;
}

static inline real_t interp_hermite(real_t t1, real_t a, real_t b, real_t t2, real_t p)
{
    float p2 = p * p;
    float p3 = p2 * p;

    float h1 = (2 * p3) - (3 * p2) + 1;          /* calculate basis function 1 */
    float h2 = 1 - h1;                           /* calculate basis function 2 */
    float h3 = p3 - (2 * p2) + p;                /* calculate basis function 3 */
    float h4 = p3 - p2;                          /* calculate basis function 4 */

    return (h1 * a) + (h2 * b) + (h3 * t1) + (h4 * t2); /* multiply and sum all functions together */
}

static inline real_t interp_cardinal(real_t a, real_t b, real_t c, real_t d, real_t t, real_t p)
{
    real_t t2 = t * t;
    real_t p3 = p * p * p;

    return t * ( (2 * b) + 	((c - a) * t) + (((2 * a) - (5 * b) + (4 * c) - d) * t2) +(((3 * b) - (3 * c) + d - a) * p3));
}

static inline real_t interp_catmullrom(real_t a, real_t b, real_t c, real_t d, real_t p)
{
    /*
        Note
        ----
        CatmullRoms are cardinals with a tension of 0.5
    */
    real_t P = - (.5f * a) + (1.5f * b) - (1.5f * c) + (0.5f * d);
    real_t Q = a - (2.5 * b) + (2 * c) - (0.5 * d);
    real_t R = ( c - a ) * .5f;
    real_t S = b;

   	float p2 = p * p;
    float p3 = p2 * p;

    return (P * p3) + (Q * p2) + (R * p) + S;
}

static inline real_t interp_bezier_quadratic(real_t a, real_t b, real_t c, real_t p)
{
    real_t ab, bc;
    ab = interp_linear(a, b, p);
    bc = interp_linear(b, c, p);
    return interp_linear( ab, bc, p);
}

static inline real_t interp_bezier_cubic(real_t a, real_t b, real_t c, real_t d, real_t p)
{
    real_t ab, bc, cd, abc, bcd;
    ab = interp_linear(a, b, p);
    bc = interp_linear(b, c, p);
    cd = interp_linear(c, d, p);
    abc = interp_linear(ab, bc, p);
    bcd = interp_linear(bc, cd, p);
    return interp_linear( abc, bcd, p);
}

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* LIBNMATH_INTERPOLATION_INL_INCLUDED */
