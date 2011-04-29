/*

    This file is part of the nemesis math library.

    gamma.h
    Gamma correction

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

#ifndef LIBNMATH_GAMMA_INL_INCLUDED
#define LIBNMATH_GAMMA_INL_INCLUDED

#include <math.h>

#ifndef LIBNMATH_GAMMA_H_INCLUDED
    #error "gamma.h must be included before gamma.inl"
#endif /* LIBNMATH_GAMMA_H_INCLUDED */

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

#ifdef __cplusplus
}

inline Vector3 gamma(const Vector3 &color,  double gamma)
{
	Vector3 res = color;

	res.x = pow(color.x, 1 / gamma);
	res.y = pow(color.y, 1 / gamma);
	res.z = pow(color.z, 1 / gamma);
	
	return res;
}

#endif /* __cplusplus */

#endif /* LIBNMATH_GAMMA_INL_INCLUDED */
