/*

    This file is part of libnmath.

    mutil.h
    Declares some math utility functions

    Copyright (C) 2008, 2010 - 2013
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

#ifndef NMATH_MUTIL_H_INCLUDED
#define NMATH_MUTIL_H_INCLUDED

#include "defs.h"
#include "precision.h"

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Inverse square root (fast approximation) */
static inline float approx_invsqrt1(float x); /* 1 Newton iteration .*/
static inline float approx_invsqrt2(float x); /* 2 Newton iterations. */

/* Angle conversion */
static inline scalar_t degree_to_radian(scalar_t r);
static inline scalar_t radian_to_degree(scalar_t d);

/* Clamping */
static inline scalar_t saturate(scalar_t v);
static inline scalar_t clamp_min(scalar_t v, scalar_t min);
static inline scalar_t clamp_max(scalar_t v, scalar_t max);
static inline scalar_t clamp(scalar_t v, scalar_t a, scalar_t b);

/* Greater Common Divisor */
static inline int gcd(int a, int b); /* Euclid's method */

/* Lowest Common Multiple */
static inline int lcm(int a, int b);

/* Check if an integer is a power of 2 */
static inline int is_power_of_2(int v);

#ifdef __cplusplus
}   /* extern "C" */
#endif /* __cplusplus */

} /* namespace NMath */

#include "mutil.inl"

#endif /* NMATH_MUTIL_H_INCLUDED */
