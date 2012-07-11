/*

	This file is part of libnmath.

	aabb.inl
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

#ifndef LIBNMATH_AABB_INL_INCLUDED
#define LIBNMATH_AABB_INL_INCLUDED

#ifndef LIBNMATH_AABB_H_INCLUDED
    #error "aabb.h must be included before aabb.inl"
#endif /* LIBNMATH_AABB_H_INCLUDED */

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

/* C 2D bounding box functions */
static inline aabb2_t aabb2_pack(const vec2_t a, const vec2_t b)
{
    aabb2_t box;
	box.min.x = (a.x <= b.x) ? a.x : b.x;
	box.min.y = (a.y <= b.y) ? a.y : b.y;
	box.max.x = (a.x >= b.x) ? a.x : b.x;
	box.max.y = (a.y >= b.y) ? a.y : b.y;

	return box;
}

static inline vec2_t aabb2_center(const aabb2_t b)
{
    return vec2_pack((b.min.x + b.max.x) / 2, (b.min.y + b.max.y) / 2);
}

static inline aabb2_t aabb2_augment_by_vec(aabb2_t b, const vec2_t v)
{
    if (v.x > b.max.x) b.max.x = v.x;
    if (v.x < b.min.x) b.min.x = v.x;
    if (v.y > b.max.y) b.max.y = v.y;
    if (v.y < b.min.y) b.min.y = v.y;

    return b;
}

static inline aabb2_t aabb2_augment_by_aabb(aabb2_t b, const aabb2_t r)
{
    if (r.max.x > b.max.x) b.max.x = r.max.x;
    if (r.min.x < b.min.x) b.min.x = r.min.x;
    if (r.max.y > b.max.y) b.max.y = r.max.y;
    if (r.min.y < b.min.y) b.min.y = r.min.y;

	return b;
}

static inline short aabb2_contains(const aabb2_t b, const vec2_t v)
{
    return ((v.x >= b.min.x) &&
			(v.y >= b.min.y) && 
			(v.x <= b.max.x) && 
			(v.y <= b.max.y)) ? 0 : 1;
}

/* C 3D bounding box functions */
static inline aabb3_t aabb3_pack(const vec3_t a, const vec3_t b)
{
    aabb3_t box;
	box.min.x = (a.x <= b.x) ? a.x : b.x;
	box.min.y = (a.y <= b.y) ? a.y : b.y;
	box.min.z = (a.z <= b.z) ? a.z : b.z;
	box.max.x = (a.x >= b.x) ? a.x : b.x;
	box.max.y = (a.y >= b.y) ? a.y : b.y;
	box.min.z = (a.z >= b.z) ? a.z : b.z;

	return box;
}

static inline vec3_t aabb3_center(const aabb3_t b)
{
    return vec3_pack((b.min.x + b.max.x) / 2, (b.min.y + b.max.y) / 2, (b.min.z + b.max.z) / 2);
}

static inline aabb3_t aabb3_augment_by_vec(aabb3_t b, const vec3_t v)
{
    if (v.x > b.max.x) b.max.x = v.x;
    if (v.x < b.min.x) b.min.x = v.x;
    if (v.y > b.max.y) b.max.y = v.y;
    if (v.y < b.min.y) b.min.y = v.y;
    if (v.z > b.max.z) b.max.z = v.z;
    if (v.z < b.min.z) b.min.z = v.z;

    return b;
}

static inline aabb3_t aabb3_augment_by_aabb(aabb3_t b, const aabb3_t r)
{
    if (r.max.x > b.max.x) b.max.x = r.max.x;
    if (r.min.x < b.min.x) b.min.x = r.min.x;
    if (r.max.y > b.max.y) b.max.y = r.max.y;
    if (r.min.y < b.min.y) b.min.y = r.min.y;
    if (r.max.z > b.max.z) b.max.z = r.max.z;
    if (r.min.z < b.min.z) b.min.z = r.min.z;

	return b;
}

static inline short aabb3_contains(const aabb3_t b, const vec3_t v)
{
    return ((v.x >= b.min.x) &&
			(v.y >= b.min.y) && 
			(v.z >= b.min.z) && 
			(v.x <= b.max.x) && 
			(v.y <= b.max.y) && 
			(v.z <= b.min.z)) ? 0 : 1;
}

#ifdef __cplusplus
}

/* AABoundingBox2 class */
inline Vector2f AABoundingBox2::center() const
{
    return (min + max) / 2.0f;
}

inline bool AABoundingBox2::contains(const Vector2f& p) const
{
    return	(p.x >= min.x) && 
			(p.y >= min.y) &&
			(p.x <= max.x) &&
			(p.y <= max.y);
}

inline void AABoundingBox2::augment(const Vector2f& v)
{
    if (v.x > max.x) max.x = v.x;
    if (v.x < min.x) min.x = v.x;
    if (v.y > max.y) max.y = v.y;
    if (v.y < min.y) min.y = v.y;
}

inline void AABoundingBox2::augment(const AABoundingBox2& b)
{
    if (b.max.x > max.x) max.x = b.max.x;
    if (b.min.x < min.x) min.x = b.min.x;
    if (b.max.y > max.y) max.y = b.max.y;
    if (b.min.y < min.y) min.y = b.min.y;
}
		
inline bool AABoundingBox2::test(const AABoundingBox2 &b) const
{
	return	(min.x <= b.max.x) &&
			(min.y <= b.max.y) &&
			(max.x >= b.min.x) &&
			(max.y >= b.min.y);
}

inline void AABoundingBox2::reset(const Vector2f &pivot)
{
	min = pivot;
	max = pivot;
}

/* AABoundingBox3 class */
inline Vector3f AABoundingBox3::center() const
{
    return (min + max) / 2.0f;
}

inline bool AABoundingBox3::contains(const Vector3f& p) const
{
    return	(p.x >= min.x) &&
			(p.y >= min.y) &&
			(p.z >= min.z) && 
			(p.x <= max.x) && 
			(p.y <= max.y) && 
			(p.z <= max.z);
}

inline void AABoundingBox3::augment(const Vector3f& v)
{
    if (v.x > max.x) max.x = v.x;
    if (v.x < min.x) min.x = v.x;
    if (v.y > max.y) max.y = v.y;
    if (v.y < min.y) min.y = v.y;
    if (v.z > max.z) max.z = v.z;
    if (v.z < min.z) min.z = v.z;
}

inline void AABoundingBox3::augment(const AABoundingBox3& b)
{
    if (b.max.x > max.x) max.x = b.max.x;
    if (b.min.x < min.x) min.x = b.min.x;
    if (b.max.y > max.y) max.y = b.max.y;
    if (b.min.y < min.y) min.y = b.min.y;
    if (b.max.z > max.z) max.z = b.max.z;
    if (b.min.z < min.z) min.z = b.min.z;
}

inline bool AABoundingBox3::test(const AABoundingBox3 &b) const
{
	return	(min.x <= b.max.x) &&
			(min.y <= b.max.y) &&
			(min.z <= b.max.z) &&
			(max.x >= b.min.x) &&
			(max.y >= b.min.y) &&
			(max.z >= b.min.z);
}

inline void AABoundingBox3::reset(const Vector3f &pivot)
{
	min = pivot;
	max = pivot;
}

#endif /* __cplusplus */

} /* namespace NMath */

#endif /* LIBNMATH_AABB_INL_INCLUDED */
