/*

	This file is part of libnmath.

	aabb.h
	Axis Aligned Bounding Box

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

#ifndef LIBNMATH_AABB_H_INCLUDED
#define LIBNMATH_AABB_H_INCLUDED

#include "declspec.h"
#include "vector.h"
#include "ray.h"

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

struct aabb2_t { vec2_t min, max; };
struct aabb3_t { vec3_t min, max; };

typedef struct aabb2_t aabb2_t;
typedef struct aabb3_t aabb3_t;

/* C 2D bounding box functions */
static inline aabb2_t aabb2_pack(const vec2_t a, const vec2_t b);
static inline vec2_t  aabb2_center(const aabb2_t b);						// returns the center coordinates of the box
static inline aabb2_t aabb2_augment_by_vec(aabb2_t b, const vec2_t v);		// augments the bounding box to include the given vector
static inline aabb2_t aabb2_augment_by_aabb(aabb2_t b, const aabb2_t r);	// augments the bounding box to include the given bounding box
static inline short   aabb2_contains(const aabb2_t b, const vec2_t v);		// returns 0 if the given point is within the bounds of the box, else 1

/* C 3D bounding box functions */
static inline aabb3_t aabb3_pack(const vec3_t a, const vec3_t b);
static inline vec3_t  aabb3_center(const aabb3_t b);						// returns the center coordinates of the box
static inline aabb3_t aabb3_augment_by_vec(aabb3_t b, const vec3_t v);		// augments the bounding box to include the given vector
static inline aabb3_t aabb3_augment_by_aabb(aabb3_t b, const aabb3_t r);	// augments the bounding box to include the given bounding box
static inline short   aabb3_contains(const aabb3_t b, const vec3_t v);		// returns 0 if the given point is within the bounds of the box, else 1

#ifdef __cplusplus
}

/* AABoundingBox2 class */
class DECLSPEC AABoundingBox2
{
    public:
		AABoundingBox2();
		AABoundingBox2(const Vector2f& a, const Vector2f& b);

		inline Vector2f center() const;                         // returns the center coordinates of the box.
		inline bool contains(const Vector2f& p) const;          // returns true if the given point is within the bounds of the box, else false.
		inline void augment(const Vector2f& v);                 // augments the bounding box to include the given vector.
		inline void augment(const AABoundingBox2& b);			// augments the bounding box to include the given bounding box.
		inline bool test(const AABoundingBox2 &b) const;        // Test for intersection with bounding box.
		inline void reset(const Vector2f &pivot);               // Reset the bounding box.

		Vector2f min, max;
};

#include "ray.h"

/* AABoundingBox3 class */
class DECLSPEC AABoundingBox3
{
    public:
		AABoundingBox3();
		AABoundingBox3(const Vector3f& a, const Vector3f& b);

		inline Vector3f center() const;							// returns the center coordinates of the box
		inline bool contains(const Vector3f& p) const;			// returns true if the given point is within the bounds of the box, else false
		inline void augment(const Vector3f& v);					// augments the bounding box to include the given vector
		inline void augment(const AABoundingBox3& b);			// augments the bounding box to include the given bounding box
		inline bool test(const AABoundingBox3 &b) const;		// Test for intersection with bounding box.
		inline void reset(const Vector3f &pivot);				// Reset the bounding box.

		bool intersection(const Ray &ray) const;

		Vector3f min, max;
};

#endif /* __cplusplus */

} /* namespace NMath */

#include "aabb.inl"

#endif /* LIBNMATH_AABB_H_INCLUDED */
