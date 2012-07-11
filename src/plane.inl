/*

	This file is part of libnmath.

	plane.inl
	Plane

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

#ifndef LIBNMATH_PLANE_INL_INCLUDED
#define LIBNMATH_PLANE_INL_INCLUDED

#ifndef LIBNMATH_PLANE_H_INCLUDED
    #error "plane.h must be included before plane.inl"
#endif /* LIBNMATH_PLANE_H_INCLUDED */

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

static inline plane_t plane_pack(vec3_t normal, scalar_t distance)
{
	plane_t s;
	s.normal = normal;
	s.distance = distance;
	return s;
}

#ifdef __cplusplus
} /* extern C */
#endif	/* __cplusplus */

inline const Vector3f &Plane::normal() const
{
	return m_normal;
}

inline scalar_t Plane::distance() const
{
	return m_distance;
}

inline void Plane::normal(const Vector3f &normal)
{
	m_normal = normal.normalized();
}

inline void Plane::distance(const scalar_t distance)
{
	m_distance = distance;
}

} /* namespace NMath */

#endif /* LIBNMATH_PLANE_INL_INCLUDED */
