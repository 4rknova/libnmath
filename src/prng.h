/*

    This file is part of the Nemesis3dMath library.

    prng.h
    Pseudo Random Number Generators

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

#ifndef LIBNMATH_PRNG_H_INCLUDED
#define LIBNMATH_PRNG_H_INCLUDED

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

static inline real_t prng_c(real_t a, real_t b);                       /* returns a random number between min and max using the C built-in PRNG in uniform manner */
static inline real_t prng_multiplyWithCarry(real_t a, real_t b);       /* Multiply with carry method by George Marsaglia */

#ifdef __cplusplus
}   /* extern "C" */
#endif

#include "prng.inl"

#endif /* LIBNMATH_PRNG_H_INCLUDED */
