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
	extern "C" {
#endif  /* __cplusplus */

struct bcircle_t { vec2_t origin; scalar_t radius; };
struct bsphere_t { vec3_t origin; scalar_t radius; };

typedef struct bcircle_t bcircle_t;
typedef struct bsphere_t bsphere_t;

/* C bounding circle functions */
static inline bcircle_t bcircle_pack(const vec2_t o, const scalar_t r);
static inline bcircle_t bcircle_augment_by_vec(bcircle_t c, const vec2_t v);		// augments the bounding circle to include the given vector.
static inline bcircle_t bcircle_augment_by_bcircle(bcircle_t c, const bcircle_t r);	// augments the bounding circle to include the given circle.
static inline short 	bcircle_contains(const bcircle_t c, const vec2_t v);		// returns 0 if the given point is within the bounds of the circle, else 1.

/* C bounding sphere functions */
static inline bsphere_t bsphere_pack(const vec3_t o, const scalar_t r);
static inline bsphere_t bsphere_augment_by_vec(bsphere_t s, const vec3_t v);		// augments the bounding sphere to include the given vector.
static inline bsphere_t bsphere_augment_by_bsphere(bsphere_t s, const bsphere_t r);	// augments the bounding sphere to include the given sphere.
static inline short 	bsphere_contains(const bsphere_t s, const vec3_t v);		// returns 0 if the given point is within the bounds of the sphere, else 1.

#ifdef __cplusplus
}

class BoundingCircle
{
	public:
		BoundingCircle();
		BoundingCircle(const Vector2f &a, const scalar_t r);

		inline Vector2f center() const;							// returns the center coordinates of the circle.
		inline bool contains(const Vector2f &v) const;			// returns true if the given point is within the bounds of the circle, else false.
		inline void augment(const Vector2f &v);					// augments the bounding circle to include the given vector.
		inline void augment(const BoundingCircle &b);			// augments the bounding circle to include the given bounding circle.
		inline bool test(const BoundingCircle &b) const;		// Test for intersection with bounding circle.
		inline void reset(const Vector2f &pivot);				// Reset the bounding circle.

		Vector2f origin;
		scalar_t radius;
};

class BoundingSphere
{
	public:
		BoundingSphere();
		BoundingSphere(const Vector3f &a, const scalar_t r);

		inline Vector3f center() const;							// returns the center coordinates of the sphere.
		inline bool contains(const Vector3f &v) const;			// returns true if the given point is within the bounds of the sphere, else false.
		inline void augment(const Vector3f &v);					// augments the bounding sphere to include the given vector.
		inline void augment(const BoundingSphere &b);			// augments the bounding sphere to include the given bounding sphere.
		inline bool test(const BoundingSphere &b) const;		// Test for intersection with bounding sphere.
		inline void reset(const Vector3f &pivot);				// Reset the bounding sphere.

		Vector3f origin;
		scalar_t radius;
};

#endif  /* __cplusplus */

} /* namespace NMath */

#include "bsphere.inl"

#endif /* NMATH_BSPHERE_H_INCLUDED */
