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
	extern "C" {
#endif  /* __cplusplus */

/* C bounding circle functions */
static inline bcircle_t bcircle_pack(const vec2_t o, const scalar_t r)
{
	bcircle_t circle;
	circle.origin.x = o.x;
	circle.origin.y = o.y;
	circle.radius = r;

	return circle;
}

static inline bcircle_t bcircle_augment_by_vec(bcircle_t c, const vec2_t v)
{
	vec2_t dv = vec2_sub(v, c.origin);
	scalar_t dr = vec2_length(dv);

	if (c.radius < dr)
		c.radius = dr;

	return c;
}

static inline bcircle_t bcircle_augment_by_bcircle(bcircle_t c, const bcircle_t r)
{
	vec2_t dv = vec2_sub(r.origin, c.origin);
	scalar_t dr = vec2_length(dv);

	if (c.radius < dr)
		c.radius = dr;

	return c;
}

static inline short bcircle_contains(const bcircle_t c, const vec2_t v)
{
	vec2_t dv = vec2_sub(v, c.origin);
	scalar_t dr = vec2_length(dv);

	return (c.radius < dr) ? 0 : 1;
}

/* C bounding sphere functions */
static inline bsphere_t bsphere_pack(const vec3_t o, const scalar_t r)
{
	bsphere_t sphere;
	sphere.origin.x = o.x;
	sphere.origin.y = o.y;
	sphere.origin.z = o.z;
	sphere.radius = r;

	return sphere;
}

static inline bsphere_t bsphere_augment_by_vec(bsphere_t c, const vec3_t v)
{
	vec3_t dv = vec3_sub(v, c.origin);
	scalar_t dr = vec3_length(dv);

	if (c.radius < dr)
		c.radius = dr;

	return c;
}

static inline bsphere_t bsphere_augment_by_bsphere(bsphere_t c, const bsphere_t r)
{
	vec3_t dv = vec3_sub(r.origin, c.origin);
	scalar_t dr = vec3_length(dv);

	if (c.radius < dr)
		c.radius = dr;

	return c;
}

static inline short bsphere_contains(const bsphere_t c, const vec3_t v)
{
	vec3_t dv = vec3_sub(v, c.origin);
	scalar_t dr = vec3_length(dv);

	return (c.radius < dr) ? 0 : 1;
}

#ifdef __cplusplus
}

/* BoundingCircle class */
inline Vector2f BoundingCircle::center() const
{
    return origin;
}

inline bool BoundingCircle::contains(const Vector2f &v) const
{
	return (v - origin).length() <= radius;
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

inline void BoundingCircle::reset(const Vector2f &pivot)
{
	origin = pivot;
	radius = 0.0f;
}

/* BoundingSphere class */
inline Vector3f BoundingSphere::center() const
{
    return origin;
}

inline bool BoundingSphere::contains(const Vector3f &v) const
{
	return (v - origin).length() <= radius;
}

inline void BoundingSphere::augment(const Vector3f &v)
{
    scalar_t nradius = (v - origin).length();
	if (nradius > radius) radius = nradius;
}

inline void BoundingSphere::augment(const BoundingSphere &b)
{
	scalar_t nradius = (b.origin - origin).length() + b.radius;
	if (nradius > radius) radius = nradius;
}

inline bool BoundingSphere::test(const BoundingSphere &b) const
{
	return (b.origin - origin).length() < (b.radius + radius);
}

inline void BoundingSphere::reset(const Vector3f &pivot)
{
	origin = pivot;
	radius = 0.0f;
}

#endif  /* __cplusplus */

} /* namespace NMath */

#endif /* NMATH_BSPHERE_INL_INCLUDED */
