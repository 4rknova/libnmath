/*

    This file is part of the nemesis math library.

    matrix.h
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

/*
	To do
	-----

	- Mat3x3:
		- Adjoint
		- c++ interface

	- Mat3x3:
		- Arbitrary axis rotation
		- c++ interface

	- Quaternions

*/

#ifndef LIBNMATH_MATRIX_H_INCLUDED
#define LIBNMATH_MATRIX_H_INCLUDED

#include <stdio.h>

#include "precision.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

/*
	3x3 matrices
*/
static inline void mat3x3_pack(mat3x3_t m,
		real_t m11, real_t m12, real_t m13,
		real_t m21, real_t m22, real_t m23,
		real_t m31, real_t m32, real_t m33);

static inline void mat3x3_identity(mat3x3_t m);

static inline void mat3x3_copy(mat3x3_t dest, mat3x3_t src);

static inline void mat3x3_set_column(mat3x3_t m, vec3_t v, int idx);
static inline void mat3x3_set_row(mat3x3_t m, vec3_t v, int idx);

static inline void mat3x3_add(mat3x3_t res, mat3x3_t m1, mat3x3_t m2);
static inline void mat3x3_mul(mat3x3_t res, mat3x3_t m1, mat3x3_t m2);

void mat3x3_translate(mat3x3_t m, real_t x, real_t y, real_t z);
void mat3x3_rotate(mat3x3_t m, real_t x, real_t y);
void mat3x3_scale(mat3x3_t m, real_t x, real_t y);
void mat3x3_shear(mat3x3_t m, real_t s);
void mat3x3_mirror_x(mat3x3_t m);
void mat3x3_mirror_y(mat3x3_t m);

void mat3x3_transpose(mat3x3_t res, mat3x3_t m);
real_t mat3x3_determinant(mat3x3_t m);
void mat3x3_adjoint(mat3x3_t res, mat3x3_t m);
void mat3x3_inverse(mat3x3_t res, mat3x3_t m);

void mat3x3_to_m4x4(mat4x4_t dest, mat3x3_t src);

void mat3x3_print(FILE *fp, mat3x3_t m);

/*
	4x4 matrices
*/

static inline void mat4x4_pack(mat4x4_t m,
		real_t m11, real_t m12, real_t m13, real_t m14,
		real_t m21, real_t m22, real_t m23, real_t m24,
		real_t m31, real_t m32, real_t m33, real_t m34,
		real_t m41, real_t m42, real_t m43, real_t m44);

static inline void mat4x4_identity(mat4x4_t m);

static inline void mat4x4_copy(mat4x4_t dest, mat4x4_t src);

static inline void mat4x4_set_column(mat4_t m, vec4_t v, int idx);
static inline void mat4x4_set_row(mat4_t m, vec4_t v, int idx);

static inline void mat4x4_add(mat4x4_t res, mat4x4_t m1, mat4x4_t m2);
static inline void mat4x4_mul(mat4x4_t res, mat4x4_t m1, mat4x4_t m2);

void mat4x4_translate(mat4x4_t m, real_t x, real_t y, real_t z);
void mat4x4_rotate(mat4x4_t m, real_t x, real_t y, real_t z);
void mat4x4_rotate_x(mat4x4_t m, real_t angle);
void mat4x4_rotate_y(mat4x4_t m, real_t angle);
void mat4x4_rotate_z(mat4x4_t m, real_t angle);
void mat4x4_rotate_axis(mat4x4_t m, real_t angle, real_t x, real_t y, real_t z);
void mat4x4_scale(mat4x4_t m, real_t x, real_t y, real_t z);

void mat4x4_prj_orthographic(mat4x4_t m, real_t left, real_t right, real_t top, real_t bottom, real_t far, real_t near);
void mat4x4_prj_perspective(mat4x4_t m, real_t near, real_t far, real_t fov, real_t aspect);

void mat4x4_transpose(mat4x4_t res, mat4x4_t m);
real_t mat4x4_determinant(mat4x4_t m);
void mat4x4_adjoint(mat4x4_t res, mat4x4_t m);
void mat4x4_inverse(mat4x4_t res, mat4x4_t m);

void mat4x4_to_m3x3(mat3x3_t dest, mat4x4_t src);

void mat4x4_print(FILE *fp, mat4x4_t m);

#ifdef __cplusplus
}   /* extern "C" */
#endif	/* __cplusplus */

#endif /* LIBNMATH_MATRIX_H_INCLUDED */
