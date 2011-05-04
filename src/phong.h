/*

    This file is part of the nemesis math library.

    phong.h
    Phong

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

#ifndef LIBNMATH_PHONG_H_INCLUDED
#define LIBNMATH_PHONG_H_INCLUDED


#include "vector.h"
#include "intinfo.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

#ifdef __cplusplus
}

inline Vector3 phong(const Vector3 &campos, const Vector3 &lightpos, const IntInfo *info, const Vector3 &light, real_t ks, real_t kd, real_t specexp, Vector3 &diffuse, Vector3 &specular);
inline Vector3 blinn_phong(const Vector3 &campos, const Vector3 &lightpos, const IntInfo *info, const Vector3 &light, real_t ks, real_t kd, real_t specexp, Vector3 &diffuse, Vector3 &specular);

#endif /* __cplusplus */

#include "phong.inl"

#endif /* LIBNMATH_PHONG_H_INCLUDED */
