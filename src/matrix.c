/*

    This file is part of the nemesis math library.

    matrix.c
    Matrix

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

#include "matrix.h"

#ifdef __cplusplus
    #include <cmath>
#else
    #include <math.h>
#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

/*
	3x3 matrices
*/

void mat3x3_translate(mat3x3_t m, real_t x, real_t y, real_t z)
{
	mat3x3_t tm;
	mat3x3_identity(tm);
	tm[0][3] = x;
	tm[1][3] = y;
	mat3x3_mul(m, m, tm);
}

void mat3x3_rotate(mat3x3_t m, real_t x, real_t y)
{
	mat3x3_t rm;
	mat3x3_identity(rm);
	rm[0][0] = cos(angle); rm[0][1] = -sin(angle);
	rm[1][0] = sin(angle); rm[1][1] = cos(angle);
	mat3x3_mul(m, m, rm);
}

void mat3x3_scale(mat3x3_t m, real_t x, real_t y)
{
	mat3x3_t sm;
	mat3x3_identity(sm);
	sm[0][0] = x;
	sm[1][1] = y;
	mat3x3_mul(m, m, sm);
}

void mat3x3_shear(mat3x3_t m, real_t s)
{
	mat3x3_t rm;
	mat3x3_identity(rm);
	rm[0][1] = s;
	mat3x3_mul(m, m, rm);
}

void mat3x3_mirror_x(mat3x3_t m)
{
	static const mat3x3_t id = {{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	mat3x3_mul(m, m, id);
}

void mat3x3_mirror_y(mat3x3_t m)
{
	static const mat3x3_t id = {{1, 0, 0}, {0, -1, 0}, {0, 0, 1}};
	mat3x3_mul(m, m, id);
}

void mat3x3_transpose(mat3x3_t res, mat3x3_t m)
{
	int i, j;
	mat3x3_t tmp;
	mat3x3_copy(tmp, m);

	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			res[i][j] = tmp[j][i];
		}
	}
}

real_t mat4x4_determinant(mat4x4_t m)
{
	real_t det11 = m[1][1] * (m[2][2] - m[1][2] * m[2][1];
	real_t det12 = m[1][0] * (m[2][2] - m[1][2] * m[2][0];
	real_t det13 = m[1][0] * (m[2][1] - m[1][1] * m[2][0];

	return m[0][0] * det11 - m[0][1] * det12 + m[0][2] * det13;
}

void mat3x3_adjoint(mat3x3_t res, mat3x3_t m)
{
}

void mat3x3_inverse(mat3x3_t res, mat3x3_t m)
{
	int i, j;
	mat3x3_t adj;
	real_t det;

	det = mat3x3_determinant(m);

	if(!det){
		return;
	}

	mat3x3_adjoint(adj, m);

	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			res[i][j] = adj[i][j] / det;
		}
	}
}

void mat3x3_to_m4x4(mat4x4_t dest, mat3x3_t src)
{
	int i, j;

	memset(dest, 0, sizeof(mat4_t));
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			dest[i][j] = src[i][j];
		}
	}
	dest[3][3] = 1.0;
}

void mat3x3_print(FILE *fp, mat3x3_t m)
{
	int i;
	for(i=0; i<3; i++) {
		fprintf(fp, "[ %12.5f %12.5f %12.5f ]\n", (float)m[i][0], (float)m[i][1], (float)m[i][2]);
	}
}

/*
	4x4 matrices
*/

void mat4x4_translate(mat4x4_t m, real_t x, real_t y, real_t z)
{
	mat4x4_t tm;
	mat4x4_identity(tm);
	tm[0][3] = x;
	tm[1][3] = y;
	tm[2][3] = z;
	mat4x4_mul(m, m, tm);
}

void mat4x4_rotate(mat4x4_t m, real_t x, real_t y, real_t z)
{
	m4x4_rotate_x(m, x);
	m4x4_rotate_y(m, y);
	m4x4_rotate_z(m, z);
}

void mat4x4_rotate_x(mat4x4_t m, real_t angle)
{
	mat4x4_t rm;
	mat4x4_identity(rm);
	rm[1][1] = cos(angle); rm[1][2] = -sin(angle);
	rm[2][1] = sin(angle); rm[2][2] = cos(angle);
	mat4x4_mul(m, m, rm);
}

void mat4x4_rotate_y(mat4x4_t m, real_t angle)
{
	mat4x4_t rm;
	mat4x4_identity(rm);
	rm[0][0] = cos(angle); rm[0][2] = sin(angle);
	rm[2][0] = -sin(angle); rm[2][2] = cos(angle);
	mat4x4_mul(m, m, rm);
}

void mat4x4_rotate_z(mat4x4_t m, real_t angle)
{
	mat4x4_t rm;
	mat4x4_identity(rm);
	rm[0][0] = cos(angle); rm[0][1] = -sin(angle);
	rm[1][0] = sin(angle); rm[1][1] = cos(angle);
	mat4x4_mul(m, m, rm);
}

void mat4x4_rotate_axis(mat4x4_t m, real_t angle, real_t x, real_t y, real_t z)
{
	mat4x4_t xform;
	real_t sina = sin(angle);
	real_t cosa = cos(angle);
	real_t one_minus_cosa = 1.0 - cosa;
	real_t nxsq = x * x;
	real_t nysq = y * y;
	real_t nzsq = z * z;

	m4x4_identity(xform);
	xform[0][0] = nxsq + (1.0 - nxsq) * cosa;
	xform[0][1] = x * y * one_minus_cosa - z * sina;
	xform[0][2] = x * z * one_minus_cosa + y * sina;
	xform[1][0] = x * y * one_minus_cosa + z * sina;
	xform[1][1] = nysq + (1.0 - nysq) * cosa;
	xform[1][2] = y * z * one_minus_cosa - x * sina;
	xform[2][0] = x * z * one_minus_cosa - y * sina;
	xform[2][1] = y * z * one_minus_cosa + x * sina;
	xform[2][2] = nzsq + (1.0 - nzsq) * cosa;

	m4x4_mul(m, m, xform);
}

void mat4x4_scale(mat4x4_t m, real_t x, real_t y, real_t z)
{
	mat4x4_t sm;
	mat4x4_identity(sm);
	sm[0][0] = x;
	sm[1][1] = y;
	sm[2][2] = z;
	mat4x4_mul(m, m, sm);
}

void mat4x4_prj_orthographic(mat4x4_t m, real_t left, real_t right, real_t top, real_t bottom, real_t far, real_t near)
{
	mat4x4_t id = {
		{2 / (right - left), 0, 0, -(right + left) / (right - left)},
		{0, 2 / (top - bottom), 0, -(top + bottom) / (top - bottom)},
		{0, 0, 1 / (far - near), - near / (far - near)},
		{0, 0, 0, 1}
	};

	mat4x4_mul(m, m, id);
}

void mat4x4_prj_perspective(mat4x4_t m, real_t near, real_t far, real_t fov, real_t aspect)
{
	real_t w, h, Q;

	w = aspect * ( cosf(fov/2)/sinf(fov/2) );
    h = cosf(fov/2)/sinf(fov/2);
    Q = far / ( far - near );

    mat4x4_t id = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    id[1][1] = w;
    id[2][2] = h;
    id[3][3] = Q;
    id[3][4] = 1.f;
    id[4][3] = -Q * near;

    mat4x4_mul(m, m, id);
}

void mat4x4_transpose(mat4x4_t res, mat4x4_t m)
{
	int i, j;
	mat4x4_t tmp;
	mat4x4_copy(tmp, m);

	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			res[i][j] = tmp[j][i];
		}
	}
}

real_t mat4x4_determinant(mat4x4_t m)
{
	real_t det11 =	(m[1][1] * (m[2][2] * m[3][3] - m[3][2] * m[2][3])) -
						(m[1][2] * (m[2][1] * m[3][3] - m[3][1] * m[2][3])) +
						(m[1][3] * (m[2][1] * m[3][2] - m[3][1] * m[2][2]));

	real_t det12 =	(m[1][0] * (m[2][2] * m[3][3] - m[3][2] * m[2][3])) -
						(m[1][2] * (m[2][0] * m[3][3] - m[3][0] * m[2][3])) +
						(m[1][3] * (m[2][0] * m[3][2] - m[3][0] * m[2][2]));

	real_t det13 =	(m[1][0] * (m[2][1] * m[3][3] - m[3][1] * m[2][3])) -
						(m[1][1] * (m[2][0] * m[3][3] - m[3][0] * m[2][3])) +
						(m[1][3] * (m[2][0] * m[3][1] - m[3][0] * m[2][1]));

	real_t det14 =	(m[1][0] * (m[2][1] * m[3][2] - m[3][1] * m[2][2])) -
						(m[1][1] * (m[2][0] * m[3][2] - m[3][0] * m[2][2])) +
						(m[1][2] * (m[2][0] * m[3][1] - m[3][0] * m[2][1]));

	return m[0][0] * det11 - m[0][1] * det12 + m[0][2] * det13 - m[0][3] * det14;
}

void mat4x4_adjoint(mat4x4_t res, mat4x4_t m)
{
	int i, j;
	mat4x4_t coef;

	coef[0][0] =	(m[1][1] * (m[2][2] * m[3][3] - m[3][2] * m[2][3])) -
					(m[1][2] * (m[2][1] * m[3][3] - m[3][1] * m[2][3])) +
					(m[1][3] * (m[2][1] * m[3][2] - m[3][1] * m[2][2]));

	coef[0][1] =	(m[1][0] * (m[2][2] * m[3][3] - m[3][2] * m[2][3])) -
					(m[1][2] * (m[2][0] * m[3][3] - m[3][0] * m[2][3])) +
					(m[1][3] * (m[2][0] * m[3][2] - m[3][0] * m[2][2]));

	coef[0][2] =	(m[1][0] * (m[2][1] * m[3][3] - m[3][1] * m[2][3])) -
					(m[1][1] * (m[2][0] * m[3][3] - m[3][0] * m[2][3])) +
					(m[1][3] * (m[2][0] * m[3][1] - m[3][0] * m[2][1]));
	coef[0][3] =	(m[1][0] * (m[2][1] * m[3][2] - m[3][1] * m[2][2])) -
					(m[1][1] * (m[2][0] * m[3][2] - m[3][0] * m[2][2])) +
					(m[1][2] * (m[2][0] * m[3][1] - m[3][0] * m[2][1]));

	coef[1][0] =	(m[0][1] * (m[2][2] * m[3][3] - m[3][2] * m[2][3])) -
					(m[0][2] * (m[2][1] * m[3][3] - m[3][1] * m[2][3])) +
					(m[0][3] * (m[2][1] * m[3][2] - m[3][1] * m[2][2]));
	coef[1][1] =	(m[0][0] * (m[2][2] * m[3][3] - m[3][2] * m[2][3])) -
					(m[0][2] * (m[2][0] * m[3][3] - m[3][0] * m[2][3])) +
					(m[0][3] * (m[2][0] * m[3][2] - m[3][0] * m[2][2]));
	coef[1][2] =	(m[0][0] * (m[2][1] * m[3][3] - m[3][1] * m[2][3])) -
					(m[0][1] * (m[2][0] * m[3][3] - m[3][0] * m[2][3])) +
					(m[0][3] * (m[2][0] * m[3][1] - m[3][0] * m[2][1]));
	coef[1][3] =	(m[0][0] * (m[2][1] * m[3][2] - m[3][1] * m[2][2])) -
					(m[0][1] * (m[2][0] * m[3][2] - m[3][0] * m[2][2])) +
					(m[0][2] * (m[2][0] * m[3][1] - m[3][0] * m[2][1]));

	coef[2][0] =	(m[0][1] * (m[1][2] * m[3][3] - m[3][2] * m[1][3])) -
					(m[0][2] * (m[1][1] * m[3][3] - m[3][1] * m[1][3])) +
					(m[0][3] * (m[1][1] * m[3][2] - m[3][1] * m[1][2]));
	coef[2][1] =	(m[0][0] * (m[1][2] * m[3][3] - m[3][2] * m[1][3])) -
					(m[0][2] * (m[1][0] * m[3][3] - m[3][0] * m[1][3])) +
					(m[0][3] * (m[1][0] * m[3][2] - m[3][0] * m[1][2]));
	coef[2][2] =	(m[0][0] * (m[1][1] * m[3][3] - m[3][1] * m[1][3])) -
					(m[0][1] * (m[1][0] * m[3][3] - m[3][0] * m[1][3])) +
					(m[0][3] * (m[1][0] * m[3][1] - m[3][0] * m[1][1]));
	coef[2][3] =	(m[0][0] * (m[1][1] * m[3][2] - m[3][1] * m[1][2])) -
					(m[0][1] * (m[1][0] * m[3][2] - m[3][0] * m[1][2])) +
					(m[0][2] * (m[1][0] * m[3][1] - m[3][0] * m[1][1]));

	coef[3][0] =	(m[0][1] * (m[1][2] * m[2][3] - m[2][2] * m[1][3])) -
					(m[0][2] * (m[1][1] * m[2][3] - m[2][1] * m[1][3])) +
					(m[0][3] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]));
	coef[3][1] =	(m[0][0] * (m[1][2] * m[2][3] - m[2][2] * m[1][3])) -
					(m[0][2] * (m[1][0] * m[2][3] - m[2][0] * m[1][3])) +
					(m[0][3] * (m[1][0] * m[2][2] - m[2][0] * m[1][2]));
	coef[3][2] =	(m[0][0] * (m[1][1] * m[2][3] - m[2][1] * m[1][3])) -
					(m[0][1] * (m[1][0] * m[2][3] - m[2][0] * m[1][3])) +
					(m[0][3] * (m[1][0] * m[2][1] - m[2][0] * m[1][1]));
	coef[3][3] =	(m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])) -
					(m[0][1] * (m[1][0] * m[2][2] - m[2][0] * m[1][2])) +
					(m[0][2] * (m[1][0] * m[2][1] - m[2][0] * m[1][1]));

	m4x4_transpose(res, coef);

	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			res[i][j] = j % 2 ? -res[i][j] : res[i][j];
			if(i % 2) res[i][j] = -res[i][j];
		}
	}
}

void mat4x4_inverse(mat4x4_t res, mat4x4_t m)
{
	int i, j;
	mat4x4_t adj;
	real_t det;

	det = mat4x4_determinant(m);

	if(!det){
		return;
	}

	mat4x4_adjoint(adj, m);

	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			res[i][j] = adj[i][j] / det;
		}
	}
}

void mat4x4_to_m3x3(mat3x3_t dest, mat4x4_t src)
{
	int i, j;
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			dest[i][j] = src[i][j];
		}
	}
}

void mat4x4_print(FILE *fp, mat4x4_t m)
{
	int i;
	for(i=0; i<4; i++) {
		fprintf(fp, "[ %12.5f %12.5f %12.5f %12.5f ]\n", (float)m[i][0], (float)m[i][1], (float)m[i][2], (float)m[i][3]);
	}
}

#ifdef __cplusplus
}   /* extern "C" */
#endif
