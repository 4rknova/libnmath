
#include "defs.h"
#include "precision.h"
#include "vector.h"
#include "triangle.h"

namespace NMath {

#ifdef __cplusplus

Triangle::Triangle()
	: Geometry(GEOMETRY_TRIANGLE)
{}

bool Triangle::intersection(const Ray &ray, SurfacePoint * sp) const
{
	// transform ray to local coordinates.
	Matrix4x4f inv_mat = m_matrix.inverse();
	Ray tray = ray.transformed(inv_mat);

	Vector3f nv1 = position[2] - position[0];
	Vector3f nv2 = position[1] - position[0];
	Vector3f norm = cross(nv1, nv2).normalized();

	scalar_t n_dot_dir = dot(norm, tray.direction());

	if (nmath_abs(n_dot_dir) < EPSILON) 
		return false; // Parallel to the plane.

	// Translation of position[0] to axis origin.
	Vector3f vo_vec = tray.origin() - position[0];

	// Calc intersection distance.
	scalar_t t = -dot(norm, vo_vec) / n_dot_dir;

	if(t < EPSILON)
		return false; // Plane in the opposite subspace.

	// intersection point ( on the plane ).
	Vector3f pos = tray.origin() + tray.direction() * t;

	// Calculate barycentric.
	Vector3f bc = barycentric(pos);
	scalar_t bc_sum = bc.x + bc.y + bc.z;

	// Check for triangle boundaries.
	if (bc_sum < 1.0 - EPSILON || bc_sum > 1.0 + EPSILON)
		return false;

	if (sp)
	{
		Matrix4x4f invtransp_mat = inv_mat.transposed();
		sp->distance = t;
		sp->position = tray.origin() + tray.direction() * sp->distance;
		sp->normal   = norm;
		sp->tangent  = cross(Vector3f(0.0f, 1.0f, 0.0f), sp->normal);

		// UV coordinates for texture mapping.
		sp->texcoord = bc.x * uv[0] + bc.y * uv[1] + bc.z * uv[2];

		// Transform everything back into world coordinates.
		sp->position.transform(m_matrix);
		sp->normal.transform(invtransp_mat);
		sp->tangent.transform(invtransp_mat);
	}

	return true;
}

void Triangle::calc_aabb()
{
	m_aabb.reset(position[0].transformed(matrix()));
	m_aabb.augment(position[1].transformed(matrix()));
	m_aabb.augment(position[2].transformed(matrix()));
}

Vector3f Triangle::barycentric(const Vector3f &p) const
{
	Vector3f bc(0.0f, 0.0f, 0.0f);
	
	Vector3f v1 = position[1] - position[0];
	Vector3f v2 = position[2] - position[0];
	
	Vector3f xv1v2 = cross(v1, v2);
	Vector3f norm = xv1v2.normalized();

	scalar_t inv_area = 2.0f / nmath_abs(dot(xv1v2, norm));

	if(inv_area > EPSILON)
		return bc;

	Vector3f pv0 = position[0] - p;
	Vector3f pv1 = position[1] - p;
	Vector3f pv2 = position[2] - p;

	// calculate the area of each sub-triangle
	Vector3f x12 = cross(pv1, pv2);
	Vector3f x20 = cross(pv2, pv0);
	Vector3f x01 = cross(pv0, pv1);

	scalar_t a0 = nmath_abs(dot(x12, norm)) * 0.5f;
	scalar_t a1 = nmath_abs(dot(x20, norm)) * 0.5f;
	scalar_t a2 = nmath_abs(dot(x01, norm)) * 0.5f;

	bc.x = a0 * inv_area;
	bc.y = a1 * inv_area;
	bc.z = a2 * inv_area;

	return bc;
}

#endif	/* __cplusplus */

} /* namespace NMath */
