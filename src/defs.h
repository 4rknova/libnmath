/*

    This file is part of the Nemesis3dMath library.

    defs.h
    Defines math related constants

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

#ifndef LIBNMATH_DEFS_H_INCLUDED
#define LIBNMATH_DEFS_H_INCLUDED

#if (__STDC_VERSION__ < 199999)
    #if defined(__GNUC__) || defined(_MSC_VER)
        #define inline __inline
    #else
        /* Inline functions not supported. Performance will suffer */
        #define inline
#endif /* __STDC_VERSION__ */

/*
    PI
*/
#define PI_DOUBLE		6.283185307179586
#define PI				3.141592653589793
#define PI_HALF			1.570796326794897
#define PI_QUARTER		0.785398163397448

#ifndef M_PI
    #define M_PI	    PI
#endif /* M_PI */

/*
     EULER_E
*/
#define EULER_E         2.718281828459045

#ifndef M_E
    #define M_E			EULER_E
#endif /* M_E */

#endif /* LIBNMATH_DEFS_H_INCLUDED */
