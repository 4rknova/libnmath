/*

	This file is part of libnmath.

	bsphere.inl
	Bounding Sphere

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

#ifndef NMATH_BSPHERE_INL_INCLUDED
#define NMATH_BSPHERE_INL_INCLUDED

#ifndef NMATH_BSPHERE_H_INCLUDED
    #error "bsphere.hpp must be included before bsphere.inl"
#endif /* NMATH_BSPHERE_H_INCLUDED */

namespace NMath {

#ifdef __cplusplus

inline bool BoundingCircle::contains(const Vector2f &v) const
{
	return (v - origin).length() <= radius;
}

inline Vector2f BoundingCircle::center() const
{
    return origin;
}

inline void BoundingCircle::augment(const Vector2f &v)
{
    scalar_t nradius = (v - origin).length();
	if (nradius > radius) radius = nradius;
}

inline void BoundingCircle::augment(const BoundingCircle &b)
{
	scalar_t nradius = (b.origin - origin).length() + b.radius;
	if (nradius > radius) radius = nradius;
}

inline bool BoundingCircle::test(const BoundingCircle &b) const
{
	return (b.origin - origin).length() < (b.radius + radius);
}

inline void BoundingCircle::reset()
{
	origin = Vector2f(0.f, 0.f);
	radius = 0.f;
}

#endif  /* __cplusplus */

} /* namespace NMath */

#endif /* NMATH_BSPHERE_INL_INCLUDED */
