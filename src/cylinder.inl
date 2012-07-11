/*

	This file is part of libnmath.

	cylinder.inl
	Cylinder

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

#ifndef LIBNMATH_CYLINDER_INL_INCLUDED
#define LIBNMATH_CYLINDER_INL_INCLUDED

#ifndef LIBNMATH_CYLINDER_H_INCLUDED
    #error "cylinder.h must be included before cylinder.inl"
#endif /* LIBNMATH_CYLINDER_H_INCLUDED */

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

static inline cylinder_t cylinder_pack(const scalar_t radius, const scalar_t end_a, const scalar_t end_b)
{
	cylinder_t s;
	s.radius = radius;
	s.end_a = end_a;
	s.end_b = end_b;
	return s;
}

#ifdef __cplusplus
} /* extern C */

inline scalar_t Cylinder::radius() const
{
	return m_radius;
}

inline scalar_t Cylinder::end_a() const
{
	return m_end_a;
}

inline scalar_t Cylinder::end_b() const
{
	return m_end_b;
}

inline void Cylinder::radius(const scalar_t radius)
{
	m_radius = (radius > 0.0f ? radius : 0.0f);
}

inline void Cylinder::end_a(const scalar_t end_a)
{
	m_end_a = end_a;
}

inline void Cylinder::end_b(const scalar_t end_b)
{
	m_end_b = end_b;
}

#endif	/* __cplusplus */

} /* namespace NMath */

#endif /* LIBNMATH_CYLINDER_INL_INCLUDED */
