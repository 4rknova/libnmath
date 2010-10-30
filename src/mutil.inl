/*

    This file is part of the Nemesis3dMath library.

    mutil.inl
    Declares some math utility functions

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

#ifndef LIBNMATH_MUTIL_INL_INCLUDED
#define LIBNMATH_MUTIL_INL_INCLUDED

#ifndef LIBNMATH_MUTIL_H_INCLUDED
    #error "mutil.h must be included before mutil.inl"
#endif /* LIBNMATH_MUTIL_H_INCLUDED */

#include "types.h"
#include "defs.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* conversion between radians and degrees */
static inline real_t degree_to_radian(real_t r)
{
    return (r * 180.0f) / PI;
}

static inline real_t radian_to_degree(real_t d)
{
    return d * (PI / 180.0f);
}

/* min - max */
static inline real_t min(real_t x, real_t y)
{
    return (x > y) ? (y) : (x);
}

static inline real_t max(real_t x, real_t y)
{
    return (x > y) ? (x) : (y);
}

/* absolute */
static inline real_t absolute(real_t x)
{
    return (x >= 0) ? (x) : (x * (-1.0f));
}

static inline real_t absolute_difference(real_t x, real_t y)
{
    return (x >= y) ? (absolute(x - y)) : (absolute(y - x));
}

/* powers */
static inline real_t squared(real_t x)
{
    return x*x;
}

static inline real_t qubed(real_t x)
{
    return x*x*x;
}

static inline real_t power(real_t a, int b)
{
    if (b<0)
    {
        return x;
    }

    if (b==0)
    {
        return 1;
    }

    if (a==0)
    {
        return 0;
    }

    if (b%2 == 0)
    {
        return power(a * a, b / 2);
    }
    else if (b%2 == 1)
    {
        /* Integer division will discard the remainder */
        return a * power(a * a, b / 2);
    }

    return 0;
}


/* Greater Common Divisor */
static inline int gcd(int a, int b)
{
   if (!b)
    return a;

   return gcd(b,a%b);
}

/* Lowest Common Multiple */
static inline int lcm(int a, int b)
{
   return b*a/lcm(a,b);
}

#ifdef __cplusplus
}   /* extern "C" */
#endif /* __cplusplus */

#endif /* LIBNMATH_MUTIL_INL_INCLUDED */
