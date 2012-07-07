/*

	This file is part of libnmath.

	bsphere.h
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

#ifndef NMATH_BSPHERE_H_INCLUDED
#define NMATH_BSPHERE_H_INCLUDED

#include "precision.h"
#include "vector.h"

namespace NMath {

#ifdef __cplusplus

class BoundingCircle
{
	public:
		BoundingCircle();
		BoundingCircle(const Vector2f &a, const scalar_t r);

		inline bool contains(const Vector2f &v) const;          // returns true if the given point is within the bounds of the box, else false.
		inline Vector2f center() const;                         // returns the center coordinates of the box.
	
		inline void augment(const Vector2f &v);                 // augments the bounding circle to include the given vector.
		inline void augment(const BoundingCircle &b);           // augments the bounding circle to include the given bounding circle.

		inline bool test(const BoundingCircle &b) const;		// Test for intersection with bounding circle.

		inline void reset();									// Reset the bounding circle.

		Vector2f origin;
		scalar_t radius;
};

#endif  /* __cplusplus */

} /* namespace NMath */

#include "bsphere.inl"

#endif /* NMATH_BSPHERE_H_INCLUDED */
