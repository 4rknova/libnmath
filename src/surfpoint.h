/*

	This file is part of libnmath.

	surfpoint.h
	Surface point

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

#ifndef LIBNMATH_SURFPOINT_H_INCLUDED
#define LIBNMATH_SURFPOINT_H_INCLUDED

#include "vector.h"
#include "precision.h"

namespace NMath {

#ifdef __cplusplus

class SurfacePoint {
	public:
		SurfacePoint();

		scalar_t distance;
		Vector3f position;
		Vector3f normal;
		Vector3f tangent;
		Vector2f texcoord;
};

#endif /* __cplusplus */

} /* namespace NMath */

#endif /* LIBNMATH_SURFPOINT_H_INCLUDED */
