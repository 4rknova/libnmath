/*

    This file is part of the nemesis math library.

    vector.cc
    Vector

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

#include "vector.h"

#ifdef __cplusplus

#include <iostream>
#include <iomanip>

/*
    Vector2
*/
Vector2::Vector2(real_t aX, real_t aY): x(aX), y(aY){}
Vector2::Vector2(const Vector2& v): x(v.x), y(v.y){}
Vector2::Vector2(const Vector3& v): x(v.x), y(v.y){}
Vector2::Vector2(const Vector4& v): x(v.x), y(v.y){}

std::ostream& operator <<(std::ostream& out, const Vector2& vec)
{
	out.setf(std::ios::fixed, std::ios::floatfield);
    out.setf(std::ios::showpoint);

	out << std::setprecision(3) ;
	out << "[ " << vec.x << ", " << vec.y << " ]";
	return out;
}

/*
    Vector3
*/
Vector3::Vector3(real_t aX, real_t aY, real_t aZ): x(aX), y(aY), z(aZ){}
Vector3::Vector3(const Vector3& v): x(v.x), y(v.y), z(v.z){}
Vector3::Vector3(const Vector2& v): x(v.x), y(v.y), z(0.0f){}
Vector3::Vector3(const Vector4& v): x(v.x), y(v.y), z(v.z){}

std::ostream& operator <<(std::ostream& out, const Vector3 &vec)
{
	out.setf(std::ios::fixed, std::ios::floatfield);
    out.setf(std::ios::showpoint);

	out << std::setprecision(3) ;
	out << "[ " << vec.x << ", " << vec.y << ", " << vec.z << " ]";
	return out;
}

/*
    Vector4
*/
Vector4::Vector4(real_t aX, real_t aY, real_t aZ, real_t aW): x(aX), y(aY), z(aZ), w(aW){}
Vector4::Vector4(const Vector4& v): x(v.x), y(v.y), z(v.z), w(v.w){}
Vector4::Vector4(const Vector2& v): x(v.x), y(v.y), z(0.0f), w(0.0f){}
Vector4::Vector4(const Vector3& v): x(v.x), y(v.y), z(v.z), w(0.0f){}

std::ostream& operator <<(std::ostream& out, const Vector4 &vec)
{
	out.setf(std::ios::fixed, std::ios::floatfield);
    out.setf(std::ios::showpoint);

	out << std::setprecision(3) ;
	out << "[ " << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << " ]";
	return out;
}

#endif  /* __cplusplus */
