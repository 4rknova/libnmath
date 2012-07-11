/*

	This file is part of libnmath.

	geometry.cc
	Geometry

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

#include "geometry.h"

namespace NMath {

#ifdef __cplusplus

Geometry::Geometry(NMATH_GEOMETRY_TYPE t)
	: m_type(t)
{}

Geometry::~Geometry()
{}

NMATH_GEOMETRY_TYPE Geometry::type()
{
	return m_type;
}

Matrix4x4f &Geometry::matrix()
{
	return m_matrix;
}

const AABoundingBox3 &Geometry::aabb()
{
	calc_aabb();
	return m_aabb;
}

#endif	/* __cplusplus */

} /* namespace NMath */
