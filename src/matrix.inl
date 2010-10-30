/*

    This file is part of the Nemesis3dMath library.

    matrix.inl
    Matrix inline functions

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

#ifndef LIBNMATH_MATRIX_INL_INCLUDED
#define LIBNMATH_MATRIX_INL_INCLUDED

#ifndef LIBNMATH_MATRIX_H_INCLUDED
    #error "matrix.h must be included before matrix.inl"
#endif /* LIBNMATH_MATRIX_H_INCLUDED */

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

/* C matrix 3x3 functions */
static inline void mat3x3_identity(mat3x3_t m)
{
    static const mat3x3_t id = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    memcpy(m, id, sizeof id);
}

static inline void mat3x3_pack(mat3x3_t m,
    real_t m11, real_t m12, real_t m13,
    real_t m21, real_t m22, real_t m23,
    real_t m31, real_t m32, real_t m33)
{
    m[0][0] = m11; m[0][1] = m12; m[0][2] = m13;
    m[1][0] = m21; m[1][1] = m22; m[1][2] = m23;
    m[2][0] = m31; m[2][1] = m32; m[2][2] = m33;
}

static inline void mat3x3_copy(mat3x3_t dest, mat3x3_t src)
{
    memcpy(dest, src, sizeof(mat3x3_t));
}

static inline void mat3x3_to_mat4x4(mat4x4_t dest, mat3x3_t src)
{
    int i, j;

    memset(dest, 0, sizeof(mat4x4_t));
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            dest[i][j] = src[i][j];
        }
    }
    dest[3][3] = 1.0;

}

/* C matrix 4x4 functions */
static inline void mat4x4_identity(mat4x4_t m)
{
    static const mat4x4_t id = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    memcpy(m, id, sizeof id);
}

static inline void mat4x4_pack(mat4x4_t m,
    real_t m11, real_t m12, real_t m13, real_t m14,
    real_t m21, real_t m22, real_t m23, real_t m24,
    real_t m31, real_t m32, real_t m33, real_t m34,
    real_t m41, real_t m42, real_t m43, real_t m44)
{
    m[0][0] = m11; m[0][1] = m12; m[0][2] = m13; m[0][3] = m14;
    m[1][0] = m21; m[1][1] = m22; m[1][2] = m23; m[1][3] = m24;
    m[2][0] = m31; m[2][1] = m32; m[2][2] = m33; m[2][3] = m34;
    m[3][0] = m41; m[3][1] = m42; m[3][2] = m43; m[3][3] = m44;
}

static inline void mat4x4_copy(mat4x4_t dest, mat4x4_t src)
{
    memcpy(dest, src, sizeof(mat4x4_t));
}

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* LIBNMATH_MATRIX_INL_INCLUDED */
