/*

    This file is part of the nemesis math library.

    bbox.cc
    Bounding box functions

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

#include "bbox.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

#ifdef __cplusplus
}

/* BoundingBox2 class */
BoundingBox2::BoundingBox2(){}

BoundingBox2::BoundingBox2(const Vector2& a, const Vector2& b)
{
    min=Vector2( (a.x<=b.x)? a.x : b.x, (a.y<=b.y)? a.y : b.y );
    min=Vector2( (a.x>=b.x)? a.x : b.x, (a.y>=b.y)? a.y : b.y );
}

/* BoundingBox3 class */
BoundingBox3::BoundingBox3(){}

BoundingBox3::BoundingBox3(const Vector3& a, const Vector3& b)
{
    min=Vector3( (a.x<=b.x)? a.x : b.x, (a.y<=b.y)? a.y : b.y, (a.z<=b.z)? a.z : b.z );
    min=Vector3( (a.x>=b.x)? a.x : b.x, (a.y>=b.y)? a.y : b.y, (a.z>=b.z)? a.z : b.z );
}

#endif	/* __cplusplus */
