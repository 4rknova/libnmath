/*

    This file is part of the nemesis math library.

    lambert.h
    Lambert

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

#ifndef LIBNMATH_LAMBERT_INL_INCLUDED
#define LIBNMATH_LAMBERT_INL_INCLUDED

#ifndef LIBNMATH_LAMBERT_H_INCLUDED
    #error "lambert.h must be included before lambert.inl"
#endif /* LIBNMATH_LAMBERT_H_INCLUDED */

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

#ifdef __cplusplus
}

inline Vector3 lambert(const Vector3 lightpos, const IntInfo *info, const Vector3 light, const Vector3 diffuse)
{
	// calculate the light vector
	Vector3 lightdir = lightpos - info->point;
	lightdir.normalize();

	// calculate the normal - light dot product
	real_t d = dot(lightdir, info->normal);

	return d > 0 ? d * diffuse * light : Vector3(0, 0 ,0);
}

#endif /* __cplusplus */

#endif /* LIBNMATH_LAMBERT_INL_INCLUDED */
