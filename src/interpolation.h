/*

    This file is part of the nemesis math library.

    interpolation.h
    Interpolation

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

/*
    To do
    -----
    - TCB spline (Kochanek-Bartels)
    - Beta splines
    - Uniform nonrational splines
*/

#ifndef LIBNMATH_INTERPOLATION_H_INCLUDED
#define LIBNMATH_INTERPOLATION_H_INCLUDED

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

/* Step */
static inline real_t interp_step(real_t a, real_t b, real_t p);

/* Linear */
static inline real_t interp_linear(real_t a, real_t b, real_t p);

/* Trigonometric */
static inline real_t interp_cosine(real_t a, real_t b, real_t p);

/* Polynomial */
static inline real_t interp_acceleration(real_t a, real_t b, real_t p);
static inline real_t interp_deceleration(real_t a, real_t b, real_t p);

static inline real_t interp_cubic(real_t a, real_t b, real_t c, real_t d, real_t p);

/* Splines */
static inline real_t interp_hermite(real_t t1, real_t a, real_t b, real_t t2, real_t p);
static inline real_t interp_cardinal(real_t a, real_t b, real_t c, real_t d, real_t t, real_t p);
static inline real_t interp_catmullrom(real_t a, real_t b, real_t c, real_t d, real_t p);

/* Bezier */
static inline real_t interp_bezier_quadratic(real_t a, real_t b, real_t c, real_t p);        /* DeCasteljau */
static inline real_t interp_bezier_cubic(real_t a, real_t b, real_t c, real_t d, real_t p);  /* DeCasteljau */

#ifdef __cplusplus
}   /* extern "C" */
#endif

#include "interpolation.inl"

#endif /* LIBNMATH_INTERPOLATION_H_INCLUDED */
