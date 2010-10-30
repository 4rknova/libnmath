/*

    This file is part of the Nemesis3dMath library.

    bbox.h
    Bounding box

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

#ifndef LIBNMATH_BBOX_H_INCLUDED
#define LIBNMATH_BBOX_H_INCLUDED

#include "types.h"
#include "vector.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

/* C 2D bounding box functions */
static inline bbox2_t bbox2_pack(vec2_t a, vec2_t b);
static inline short bbox2_contains(bbox2_t b, vec2_t v);            // returns 0 if the given point is within the bounds of the box, else 1
static inline vec2_t bbox2_center(bbox2_t b);                       // returns the center coordinates of the box
static inline bbox2_t bbox2_augment_by_vec(bbox2_t s, vec2_t v);    // augments the bounding box to include the given vector
static inline bbox2_t bbox2_augment_by_bbox(bbox2_t s, bbox2_t b);  // augments the bounding box to include the given bounding box

/* C 3D bounding box functions */
static inline bbox3_t bbox3_pack(vec3_t a, vec3_t b);
static inline short bbox3_contains(bbox3_t b, vec3_t v);            // returns 0 if the given point is within the bounds of the box, else 1
static inline vec3_t bbox3_center(bbox3_t b);                       // returns the center coordinates of the box
static inline bbox3_t bbox3_augment_by_vec(bbox3_t s, vec3_t v);    // augments the bounding box to include the given vector
static inline bbox3_t bbox3_augment_by_bbox(bbox3_t s, bbox3_t b);  // augments the bounding box to include the given bounding box

#ifdef __cplusplus
}

/* BoundingBox2 class */
class BoundingBox2
{
    public:
        BoundingBox2();
        BoundingBox2(const Vector2& a, const Vector2& b);

        inline bool contains(const Vector2& p) const;           // returns true if the given point is within the bounds of the box, else false
        inline Vector2 center() const;                          // returns the center coordinates of the box

        inline void augment(const Vector2& v);                  // augments the bounding box to include the given vector
        inline void augment(const BoundingBox2& b);             // augments the bounding box to include the given bounding box

        Vector2 min, max;
};

/* BoundingBox3 class */
class BoundingBox3
{
    public:
        BoundingBox3();
        BoundingBox3(const Vector3& a, const Vector3& b);

        inline bool contains(const Vector3& p) const;           // returns true if the given point is within the bounds of the box, else false
        inline Vector3 center() const;                          // returns the center coordinates of the box

        inline void augment(const Vector3& v);                  // augments the bounding box to include the given vector
        inline void augment(const BoundingBox3& b);             // augments the bounding box to include the given bounding box

        Vector3 min, max;
};

#endif /* __cplusplus */

#include "bbox.inl"

#endif /* LIBNMATH_BBOX_H_INCLUDED */
