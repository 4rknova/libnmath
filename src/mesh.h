/*

    This file is part of the nemesis math library.

    mesh.h
    Mesh

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

#ifndef LIBNMATH_MESH_H_INCLUDED
#define LIBNMATH_MESH_H_INCLUDED

#include <vector>
#include "precision.h"
#include "vector.h"
#include "vertex.h"
#include "geometry.h"
#include "ray.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

#ifdef __cplusplus
}	/* __cplusplus */


// Face
class Face
{
	public:
		void calc_normal();
		unsigned int count();

		Vector3 normal;		// face normal
		Vertex v[3];
};

// Mesh
class Mesh: public Geometry
{
    public:
        Mesh();
		~Mesh();

		void add_face(Face *face);
		unsigned int get_face_count() const;
		Face *get_face(unsigned int idx);
		const Face *get_face(unsigned int idx) const;

		bool intersection(const Ray &ray, IntInfo* i_info) const;
		void calc_aabb();

	protected:
		std::vector<Face *> m_faces;
};

#endif	/* __cplusplus */

#endif /* LIBNMATH_MESH_H_INCLUDED */
