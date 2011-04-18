/*

    This file is part of the nemesis math library.

    geometry.h
    Geometry

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

#ifndef LIBNMATH_GEOMETRY_H_INCLUDED
#define LIBNMATH_GEOMETRY_H_INCLUDED

#include "bbox.h"
#include "ray.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

#ifdef __cplusplus
}	/* __cplusplus */

// forward declaration
struct IntInfo;

class Geometry
{
    public:
		virtual bool intersection(const Ray &ray, IntInfo* i_info) const = 0;
		virtual void calc_bbox() = 0;

	protected:
		BoundingBox3 bbox;

};

#endif	/* __cplusplus */

#endif /* LIBNMATH_GEOMETRY_H_INCLUDED */
