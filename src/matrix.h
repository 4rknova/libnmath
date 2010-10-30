/*

    This file is part of the Nemesis3dMath library.

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

#ifndef LIBNMATH_MATRIX_H_INCLUDED
#define LIBNMATH_MATRIX_H_INCLUDED

#include <stdio.h>

#include "precision.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

/* C matrix 3x3 functions */
static inline void mat3x3_identity(mat3x3_t m);
static inline void mat3x3_pack(mat3x3_t m,
    real_t m11, real_t m12, real_t m13,
    real_t m21, real_t m22, real_t m23,
    real_t m31, real_t m32, real_t m33);
static inline void mat3x3_copy(mat3x3_t dest, mat3x3_t src);
static inline void mat3x3_to_mat4x4(mat4x4_t dest, mat3x3_t src);

void mat3x3_print(FILE *fp, mat3x3_t m);

/* C matrix 4x4 functions */
static inline void mat4x4_identity(mat4x4_t m);
static inline void mat4x4_pack(mat4x4_t m,
    real_t m11, real_t m12, real_t m13, real_t m14,
    real_t m21, real_t m22, real_t m23, real_t m24,
    real_t m31, real_t m32, real_t m33, real_t m34,
    real_t m41, real_t m42, real_t m43, real_t m44);
static inline void m4_copy(mat4_t dest, mat4_t src);
static inline void mat4x4_to_mat3x3(mat3x3_t dest, mat4x4_t src);








static inline void m4_mult(mat4_t res, mat4_t m1, mat4_t m2);

void m4_translate(mat4_t m, real_t x, real_t y, real_t z);
void m4_rotate(mat4_t m, real_t x, real_t y, real_t z);
void m4_rotate_x(mat4_t m, real_t angle);
void m4_rotate_y(mat4_t m, real_t angle);
void m4_rotate_z(mat4_t m, real_t angle);
void m4_rotate_axis(mat4_t m, real_t angle, real_t x, real_t y, real_t z);
void m4_rotate_quat(mat4_t m, quat_t q);
void m4_scale(mat4_t m, real_t x, real_t y, real_t z);
static inline void m4_set_column(mat4_t m, vec4_t v, int idx);
static inline void m4_set_row(mat4_t m, vec4_t v, int idx);

void m4_transpose(mat4_t res, mat4_t m);
real_t m4_determinant(mat4_t m);
void m4_adjoint(mat4_t res, mat4_t m);
void m4_inverse(mat4_t res, mat4_t m);









void mat4x4_print(FILE *fp, mat4x4_t m);




#ifdef __cplusplus
}   /* extern "C" */






#endif	/* __cplusplus */

#endif // LIBNMATH_MATRIX_H_INCLUDED
