/*

	This file is part of libnmath.

	ray.cc
	Ray

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

#include "ray.h"

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

#ifdef __cplusplus
}

Ray::Ray()
	: m_origin(Vector3f(0.0f, 0.0f, 0.0f)), 
	  m_direction(Vector3f(0.0f, 0.0f, 1.0f))
{}

Ray::Ray(const Vector3f &org, const Vector3f &dir)
    : m_origin(org),
	  m_direction(dir.normalized())
{}

void Ray::transform(const Matrix4x4f &mat)
{
	Matrix4x4f upper = mat;
	upper[0][3] = upper[1][3] = upper[2][3] = upper[3][0] = upper[3][1] = upper[3][2] = 0.0f;
	upper[3][3] = 1.0f;

	direction(m_direction.transformed(upper));
	origin(m_origin.transformed(mat));
}

Ray Ray::transformed(const Matrix4x4f &mat) const
{
	Ray res = *this;
	res.transform(mat);
	return res;
}

const Vector3f &Ray::origin() const
{
	return m_origin;
}

const Vector3f &Ray::direction() const
{
	return m_direction;
}

void Ray::origin(const Vector3f &origin)
{
	m_origin = origin;
}

void Ray::direction(const Vector3f &direction)
{
	m_direction = direction.normalized();
}

#endif	/* __cplusplus */

} /* namespace NMath */
