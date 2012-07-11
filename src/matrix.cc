/*

    This file is part of libnmath.

    matrix.cc
    Matrix

    Copyright (C) 2008, 2010 - 2012
    Papadopoulos Nikolaos

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General
    Public License along with this program; if not, write to the
    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301 USA

*/

#include "matrix.h"
#include "vector.h"

#ifdef __cplusplus
    #include <cmath>
#else
    #include <math.h>
#endif  /* __cplusplus */

namespace NMath {

#ifdef __cplusplus
extern "C" {
#endif    /* __cplusplus */

/*
    3x3 matrices
*/

void mat3x3_translate(mat3x3_t m, scalar_t x, scalar_t y)
{
    mat3x3_t tm;
    mat3x3_identity(tm);
    tm[0][3] = x;
    tm[1][3] = y;
    mat3x3_mul(m, m, tm);
}

void mat3x3_rotate(mat3x3_t m, scalar_t angle)
{
    mat3x3_t rm;
    mat3x3_identity(rm);
    rm[0][0] = cos(angle); rm[0][1] = -sin(angle);
    rm[1][0] = sin(angle); rm[1][1] = cos(angle);
    mat3x3_mul(m, m, rm);
}

void mat3x3_scale(mat3x3_t m, scalar_t x, scalar_t y)
{
    mat3x3_t sm;
    mat3x3_identity(sm);
    sm[0][0] = x;
    sm[1][1] = y;
    mat3x3_mul(m, m, sm);
}

void mat3x3_shear(mat3x3_t m, scalar_t s)
{
    mat3x3_t rm;
    mat3x3_identity(rm);
    rm[0][1] = s;
    mat3x3_mul(m, m, rm);
}

void mat3x3_mirror_x(mat3x3_t m)
{
    static mat3x3_t id = {{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    mat3x3_mul(m, m, id);
}

void mat3x3_mirror_y(mat3x3_t m)
{
    static mat3x3_t id = {{1, 0, 0}, {0, -1, 0}, {0, 0, 1}};
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

scalar_t mat3x3_determinant(mat3x3_t m)
{
    scalar_t det11 = m[1][1] * (m[2][2] - m[1][2] * m[2][1]);
    scalar_t det12 = m[1][0] * (m[2][2] - m[1][2] * m[2][0]);
    scalar_t det13 = m[1][0] * (m[2][1] - m[1][1] * m[2][0]);

    return m[0][0] * det11 - m[0][1] * det12 + m[0][2] * det13;
}

void mat3x3_adjoint(mat3x3_t res, mat3x3_t m)
{
    mat3x3_t coef;

    coef[0][0] =  (m[1][1] * m[2][2] - m[1][2] * m[2][1]);
    coef[0][1] =  (m[1][0] * m[2][2] - m[1][2] * m[2][0]);
    coef[0][2] =  (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    coef[1][0] =  (m[0][1] * m[2][2] - m[0][2] * m[2][1]);
    coef[1][1] =  (m[0][0] * m[2][2] - m[0][2] * m[2][0]);
    coef[1][2] =  (m[0][0] * m[2][1] - m[0][1] * m[2][0]);
    coef[2][0] =  (m[0][1] * m[1][2] - m[0][2] * m[1][1]);
    coef[2][1] =  (m[0][0] * m[1][2] - m[0][2] * m[1][0]);
    coef[2][2] =  (m[0][0] * m[1][1] - m[0][1] * m[1][0]);

    mat3x3_transpose(res, coef);

    int i=0, j=0;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            res[i][j] = j%2 ? -res[i][j] : res[i][j];
            if(i%2)
                res[i][j] = -res[i][j];
        }
    }
}

void mat3x3_inverse(mat3x3_t res, mat3x3_t m)
{
    int i, j;
    mat3x3_t adj;
    scalar_t det;

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

    memset(dest, 0, sizeof(mat4x4_t));
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            dest[i][j] = src[i][j];
        }
    }
    dest[3][3] = 1.0;
}

/*
    4x4 matrices
*/

void mat4x4_translate(mat4x4_t m, scalar_t x, scalar_t y, scalar_t z)
{
    mat4x4_t tm;
    mat4x4_identity(tm);
    tm[0][3] = x;
    tm[1][3] = y;
    tm[2][3] = z;
    mat4x4_mul(m, m, tm);
}

void mat4x4_rotate(mat4x4_t m, scalar_t x, scalar_t y, scalar_t z)
{
    mat4x4_rotate_x(m, x);
    mat4x4_rotate_y(m, y);
    mat4x4_rotate_z(m, z);
}

void mat4x4_rotate_x(mat4x4_t m, scalar_t angle)
{
    mat4x4_t rm;
    mat4x4_identity(rm);
    rm[1][1] = cos(angle); rm[1][2] = -sin(angle);
    rm[2][1] = sin(angle); rm[2][2] = cos(angle);
    mat4x4_mul(m, m, rm);
}

void mat4x4_rotate_y(mat4x4_t m, scalar_t angle)
{
    mat4x4_t rm;
    mat4x4_identity(rm);
    rm[0][0] = cos(angle); rm[0][2] = sin(angle);
    rm[2][0] = -sin(angle); rm[2][2] = cos(angle);
    mat4x4_mul(m, m, rm);
}

void mat4x4_rotate_z(mat4x4_t m, scalar_t angle)
{
    mat4x4_t rm;
    mat4x4_identity(rm);
    rm[0][0] = cos(angle); rm[0][1] = -sin(angle);
    rm[1][0] = sin(angle); rm[1][1] = cos(angle);
    mat4x4_mul(m, m, rm);
}

void mat4x4_rotate_axis(mat4x4_t m, scalar_t angle, scalar_t x, scalar_t y, scalar_t z)
{
    mat4x4_t xform;
    scalar_t sina = sin(angle);
    scalar_t cosa = cos(angle);
    scalar_t one_minus_cosa = 1.0 - cosa;
    scalar_t nxsq = x * x;
    scalar_t nysq = y * y;
    scalar_t nzsq = z * z;

    mat4x4_identity(xform);
    xform[0][0] = nxsq + (1.0 - nxsq) * cosa;
    xform[0][1] = x * y * one_minus_cosa - z * sina;
    xform[0][2] = x * z * one_minus_cosa + y * sina;
    xform[1][0] = x * y * one_minus_cosa + z * sina;
    xform[1][1] = nysq + (1.0 - nysq) * cosa;
    xform[1][2] = y * z * one_minus_cosa - x * sina;
    xform[2][0] = x * z * one_minus_cosa - y * sina;
    xform[2][1] = y * z * one_minus_cosa + x * sina;
    xform[2][2] = nzsq + (1.0 - nzsq) * cosa;

    mat4x4_mul(m, m, xform);
}

void mat4x4_scale(mat4x4_t m, scalar_t x, scalar_t y, scalar_t z)
{
    mat4x4_t sm;
    mat4x4_identity(sm);
    sm[0][0] = x;
    sm[1][1] = y;
    sm[2][2] = z;
    mat4x4_mul(m, m, sm);
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

scalar_t mat4x4_determinant(mat4x4_t m)
{
    scalar_t det11 =    (m[1][1] * (m[2][2] * m[3][3] - m[3][2] * m[2][3])) -
                        (m[1][2] * (m[2][1] * m[3][3] - m[3][1] * m[2][3])) +
                        (m[1][3] * (m[2][1] * m[3][2] - m[3][1] * m[2][2]));

    scalar_t det12 =    (m[1][0] * (m[2][2] * m[3][3] - m[3][2] * m[2][3])) -
                        (m[1][2] * (m[2][0] * m[3][3] - m[3][0] * m[2][3])) +
                        (m[1][3] * (m[2][0] * m[3][2] - m[3][0] * m[2][2]));

    scalar_t det13 =    (m[1][0] * (m[2][1] * m[3][3] - m[3][1] * m[2][3])) -
                        (m[1][1] * (m[2][0] * m[3][3] - m[3][0] * m[2][3])) +
                        (m[1][3] * (m[2][0] * m[3][1] - m[3][0] * m[2][1]));

    scalar_t det14 =    (m[1][0] * (m[2][1] * m[3][2] - m[3][1] * m[2][2])) -
                        (m[1][1] * (m[2][0] * m[3][2] - m[3][0] * m[2][2])) +
                        (m[1][2] * (m[2][0] * m[3][1] - m[3][0] * m[2][1]));

    return m[0][0] * det11 - m[0][1] * det12 + m[0][2] * det13 - m[0][3] * det14;
}

void mat4x4_adjoint(mat4x4_t res, mat4x4_t m)
{
    int i, j;
    mat4x4_t coef;

    coef[0][0] =    (m[1][1] * (m[2][2] * m[3][3] - m[3][2] * m[2][3])) -
                    (m[1][2] * (m[2][1] * m[3][3] - m[3][1] * m[2][3])) +
                    (m[1][3] * (m[2][1] * m[3][2] - m[3][1] * m[2][2]));

    coef[0][1] =    (m[1][0] * (m[2][2] * m[3][3] - m[3][2] * m[2][3])) -
                    (m[1][2] * (m[2][0] * m[3][3] - m[3][0] * m[2][3])) +
                    (m[1][3] * (m[2][0] * m[3][2] - m[3][0] * m[2][2]));

    coef[0][2] =    (m[1][0] * (m[2][1] * m[3][3] - m[3][1] * m[2][3])) -
                    (m[1][1] * (m[2][0] * m[3][3] - m[3][0] * m[2][3])) +
                    (m[1][3] * (m[2][0] * m[3][1] - m[3][0] * m[2][1]));
    coef[0][3] =    (m[1][0] * (m[2][1] * m[3][2] - m[3][1] * m[2][2])) -
                    (m[1][1] * (m[2][0] * m[3][2] - m[3][0] * m[2][2])) +
                    (m[1][2] * (m[2][0] * m[3][1] - m[3][0] * m[2][1]));

    coef[1][0] =    (m[0][1] * (m[2][2] * m[3][3] - m[3][2] * m[2][3])) -
                    (m[0][2] * (m[2][1] * m[3][3] - m[3][1] * m[2][3])) +
                    (m[0][3] * (m[2][1] * m[3][2] - m[3][1] * m[2][2]));
    coef[1][1] =    (m[0][0] * (m[2][2] * m[3][3] - m[3][2] * m[2][3])) -
                    (m[0][2] * (m[2][0] * m[3][3] - m[3][0] * m[2][3])) +
                    (m[0][3] * (m[2][0] * m[3][2] - m[3][0] * m[2][2]));
    coef[1][2] =    (m[0][0] * (m[2][1] * m[3][3] - m[3][1] * m[2][3])) -
                    (m[0][1] * (m[2][0] * m[3][3] - m[3][0] * m[2][3])) +
                    (m[0][3] * (m[2][0] * m[3][1] - m[3][0] * m[2][1]));
    coef[1][3] =    (m[0][0] * (m[2][1] * m[3][2] - m[3][1] * m[2][2])) -
                    (m[0][1] * (m[2][0] * m[3][2] - m[3][0] * m[2][2])) +
                    (m[0][2] * (m[2][0] * m[3][1] - m[3][0] * m[2][1]));

    coef[2][0] =    (m[0][1] * (m[1][2] * m[3][3] - m[3][2] * m[1][3])) -
                    (m[0][2] * (m[1][1] * m[3][3] - m[3][1] * m[1][3])) +
                    (m[0][3] * (m[1][1] * m[3][2] - m[3][1] * m[1][2]));
    coef[2][1] =    (m[0][0] * (m[1][2] * m[3][3] - m[3][2] * m[1][3])) -
                    (m[0][2] * (m[1][0] * m[3][3] - m[3][0] * m[1][3])) +
                    (m[0][3] * (m[1][0] * m[3][2] - m[3][0] * m[1][2]));
    coef[2][2] =    (m[0][0] * (m[1][1] * m[3][3] - m[3][1] * m[1][3])) -
                    (m[0][1] * (m[1][0] * m[3][3] - m[3][0] * m[1][3])) +
                    (m[0][3] * (m[1][0] * m[3][1] - m[3][0] * m[1][1]));
    coef[2][3] =    (m[0][0] * (m[1][1] * m[3][2] - m[3][1] * m[1][2])) -
                    (m[0][1] * (m[1][0] * m[3][2] - m[3][0] * m[1][2])) +
                    (m[0][2] * (m[1][0] * m[3][1] - m[3][0] * m[1][1]));

    coef[3][0] =    (m[0][1] * (m[1][2] * m[2][3] - m[2][2] * m[1][3])) -
                    (m[0][2] * (m[1][1] * m[2][3] - m[2][1] * m[1][3])) +
                    (m[0][3] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]));
    coef[3][1] =    (m[0][0] * (m[1][2] * m[2][3] - m[2][2] * m[1][3])) -
                    (m[0][2] * (m[1][0] * m[2][3] - m[2][0] * m[1][3])) +
                    (m[0][3] * (m[1][0] * m[2][2] - m[2][0] * m[1][2]));
    coef[3][2] =    (m[0][0] * (m[1][1] * m[2][3] - m[2][1] * m[1][3])) -
                    (m[0][1] * (m[1][0] * m[2][3] - m[2][0] * m[1][3])) +
                    (m[0][3] * (m[1][0] * m[2][1] - m[2][0] * m[1][1]));
    coef[3][3] =    (m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])) -
                    (m[0][1] * (m[1][0] * m[2][2] - m[2][0] * m[1][2])) +
                    (m[0][2] * (m[1][0] * m[2][1] - m[2][0] * m[1][1]));

    mat4x4_transpose(res, coef);

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
    scalar_t det;

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

#ifdef __cplusplus
}   /* extern "C" */

const Matrix3x3f Matrix3x3f::identity = Matrix3x3f(1, 0, 0, 0, 1, 0, 0, 0, 1);

Matrix3x3f::Matrix3x3f()
{
    *this = identity;
}

Matrix3x3f::Matrix3x3f(const scalar_t m11, const scalar_t m12, const scalar_t m13,
                       const scalar_t m21, const scalar_t m22, const scalar_t m23,
                       const scalar_t m31, const scalar_t m32, const scalar_t m33)
{
    m_data[0][0] = m11; m_data[0][1] = m12; m_data[0][2] = m13;
    m_data[1][0] = m21; m_data[1][1] = m22; m_data[1][2] = m23;
    m_data[2][0] = m31; m_data[2][1] = m32; m_data[2][2] = m33;
}

Matrix3x3f::Matrix3x3f(const mat3x3_t m)
{
    memcpy(m_data, m, sizeof(mat3x3_t));
}

Matrix3x3f::Matrix3x3f(const Matrix3x3f &mat)
{
    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            m_data[i][j] = mat[i][j];
        }
    }
}

Matrix3x3f::Matrix3x3f(const Matrix4x4f &mat)
{
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            m_data[i][j] = mat[i][j];
        }
    }
}

Matrix3x3f &Matrix3x3f::operator =(const Matrix3x3f &rhs)
{
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			m_data[i][j] = rhs[i][j];
		}
	}

	return *this;
}

Matrix3x3f &Matrix3x3f::operator =(const Matrix4x4f &rhs)
{
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			m_data[i][j] = rhs[i][j];
		}
	}

	return *this;
}

Matrix3x3f &Matrix3x3f::operator +=(const Matrix3x3f &rhs)
{
    scalar_t *op1 = m_data[0];
    const scalar_t *op2 = rhs[0];

    for (unsigned int i = 0; i < 9; i++) {
        *op1++ += *op2++;
    }

	return *this;
}

Matrix3x3f &Matrix3x3f::operator -=(const Matrix3x3f &rhs)
{
    scalar_t *op1 = m_data[0];
    const scalar_t *op2 = rhs[0];

    for (unsigned int i = 0; i < 9; i++) {
        *op1++ -= *op2++;
    }

	return *this;
}

Matrix3x3f &Matrix3x3f::operator *=(const Matrix3x3f &rhs)
{
    Matrix3x3f res;
    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            res.m_data[i][j] = m_data[i][0] * rhs[0][j] + m_data[i][1] * rhs[1][j] + m_data[i][2] * rhs[2][j];
        }
    }
    memcpy(m_data, rhs[0], 9 * sizeof(scalar_t));

	return *this;
}

Matrix3x3f &Matrix3x3f::operator *=(const scalar_t r)
{
    scalar_t *mptr = m_data[0];

    for (unsigned int i = 0; i < 9; i++) {
        *mptr++ *= r;
    }

	return *this;
}

void Matrix3x3f::translate(const Vector2f &t)
{
    Matrix3x3f tmat(1, 0, t.x, 0, 1, t.y, 0, 0, 1);
    *this *= tmat;
}

void Matrix3x3f::set_translation(const Vector2f &t)
{
    *this = Matrix3x3f(1, 0, t.x, 0, 1, t.y, 0, 0, 1);
}

void Matrix3x3f::rotate(scalar_t angle)
{
    scalar_t cos_a = cos(angle);
    scalar_t sin_a = sin(angle);
    Matrix3x3f m(cos_a, -sin_a, 0, sin_a, cos_a, 0, 0, 0, 1);
    *this *= m;
}

void Matrix3x3f::rotate(const Vector3f &euler)
{
    Matrix3x3f xrot, yrot, zrot;
    xrot = Matrix3x3f(1, 0, 0, 0, cos(euler.x), -sin(euler.x), 0, sin(euler.x), cos(euler.x));
    yrot = Matrix3x3f(cos(euler.y), 0, sin(euler.y), 0, 1, 0, -sin(euler.y), 0, cos(euler.y));
    zrot = Matrix3x3f(cos(euler.z), -sin(euler.z), 0, sin(euler.z), cos(euler.z), 0, 0, 0, 1);
    *this *= xrot * yrot * zrot;
}

void Matrix3x3f::rotate(const Vector3f &axis, scalar_t angle)
{
    scalar_t sina = (scalar_t)sin(angle);
    scalar_t cosa = (scalar_t)cos(angle);
    scalar_t invcosa = 1-cosa;
    scalar_t nxsq = axis.x * axis.x;
    scalar_t nysq = axis.y * axis.y;
    scalar_t nzsq = axis.z * axis.z;

    Matrix3x3f xform;
    xform.m_data[0][0] = nxsq + (1-nxsq) * cosa;
    xform.m_data[0][1] = axis.x * axis.y * invcosa - axis.z * sina;
    xform.m_data[0][2] = axis.x * axis.z * invcosa + axis.y * sina;
    xform.m_data[1][0] = axis.x * axis.y * invcosa + axis.z * sina;
    xform.m_data[1][1] = nysq + (1-nysq) * cosa;
    xform.m_data[1][2] = axis.y * axis.z * invcosa - axis.x * sina;
    xform.m_data[2][0] = axis.x * axis.z * invcosa - axis.y * sina;
    xform.m_data[2][1] = axis.y * axis.z * invcosa + axis.x * sina;
    xform.m_data[2][2] = nzsq + (1-nzsq) * cosa;

    *this *= xform;
}

void Matrix3x3f::set_rotation(scalar_t angle)
{
    scalar_t cos_a = cos(angle);
    scalar_t sin_a = sin(angle);
    *this = Matrix3x3f(cos_a, -sin_a, 0, sin_a, cos_a, 0, 0, 0, 1);
}

void Matrix3x3f::set_rotation(const Vector3f &euler)
{
    Matrix3x3f xrot, yrot, zrot;
    xrot = Matrix3x3f(1, 0, 0, 0, cos(euler.x), -sin(euler.x), 0, sin(euler.x), cos(euler.x));
    yrot = Matrix3x3f(cos(euler.y), 0, sin(euler.y), 0, 1, 0, -sin(euler.y), 0, cos(euler.y));
    zrot = Matrix3x3f(cos(euler.z), -sin(euler.z), 0, sin(euler.z), cos(euler.z), 0, 0, 0, 1);
    *this = xrot * yrot * zrot;
}

void Matrix3x3f::set_rotation(const Vector3f &axis, scalar_t angle)
{
    scalar_t sina = (scalar_t)sin(angle);
    scalar_t cosa = (scalar_t)cos(angle);
    scalar_t invcosa = 1-cosa;
    scalar_t nxsq = axis.x * axis.x;
    scalar_t nysq = axis.y * axis.y;
    scalar_t nzsq = axis.z * axis.z;

    load_identity();
    m_data[0][0] = nxsq + (1-nxsq) * cosa;
    m_data[0][1] = axis.x * axis.y * invcosa - axis.z * sina;
    m_data[0][2] = axis.x * axis.z * invcosa + axis.y * sina;
    m_data[1][0] = axis.x * axis.y * invcosa + axis.z * sina;
    m_data[1][1] = nysq + (1-nysq) * cosa;
    m_data[1][2] = axis.y * axis.z * invcosa - axis.x * sina;
    m_data[2][0] = axis.x * axis.z * invcosa - axis.y * sina;
    m_data[2][1] = axis.y * axis.z * invcosa + axis.x * sina;
    m_data[2][2] = nzsq + (1-nzsq) * cosa;
}

void Matrix3x3f::scale(const Vector3f &vec)
{
    Matrix3x3f mat(vec.x, 0, 0, 0, vec.y, 0, 0, 0, vec.z);
    *this *= mat;
}

void Matrix3x3f::set_scaling(const Vector3f &vec)
{
    *this = Matrix3x3f(vec.x, 0, 0, 0, vec.y, 0, 0, 0, vec.z);
}

void Matrix3x3f::set_column_vector(const Vector3f &vec, unsigned int index)
{
    m_data[0][index] = vec.x;
    m_data[1][index] = vec.y;
    m_data[2][index] = vec.z;
}

void Matrix3x3f::set_row_vector(const Vector3f &vec, unsigned int index)
{
    m_data[index][0] = vec.x;
    m_data[index][1] = vec.y;
    m_data[index][2] = vec.z;
}

Vector3f Matrix3x3f::get_column_vector(unsigned int index) const
{
    return Vector3f(m_data[0][index], m_data[1][index], m_data[2][index]);
}

Vector3f Matrix3x3f::get_row_vector(unsigned int index) const
{
    return Vector3f(m_data[index][0], m_data[index][1], m_data[index][2]);
}

void Matrix3x3f::transpose()
{
    Matrix3x3f tmp = *this;
    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            m_data[i][j] = tmp[j][i];
        }
    }
}

Matrix3x3f Matrix3x3f::transposed() const
{
    Matrix3x3f res;
    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            res[i][j] = m_data[j][i];
        }
    }
    return res;
}

scalar_t Matrix3x3f::determinant() const
{
    return  m_data[0][0] * (m_data[1][1] * m_data[2][2] - m_data[1][2] * m_data[2][1]) -
            m_data[0][1] * (m_data[1][0] * m_data[2][2] - m_data[1][2] * m_data[2][0]) +
            m_data[0][2] * (m_data[1][0] * m_data[2][1] - m_data[1][1] * m_data[2][0]);
}

Matrix3x3f Matrix3x3f::adjoint() const
{
    Matrix3x3f coef;

    coef.m_data[0][0] =  (m_data[1][1] * m_data[2][2] - m_data[1][2] * m_data[2][1]);
    coef.m_data[0][1] =  (m_data[1][0] * m_data[2][2] - m_data[1][2] * m_data[2][0]);
    coef.m_data[0][2] =  (m_data[1][0] * m_data[2][1] - m_data[1][1] * m_data[2][0]);
    coef.m_data[1][0] =  (m_data[0][1] * m_data[2][2] - m_data[0][2] * m_data[2][1]);
    coef.m_data[1][1] =  (m_data[0][0] * m_data[2][2] - m_data[0][2] * m_data[2][0]);
    coef.m_data[1][2] =  (m_data[0][0] * m_data[2][1] - m_data[0][1] * m_data[2][0]);
    coef.m_data[2][0] =  (m_data[0][1] * m_data[1][2] - m_data[0][2] * m_data[1][1]);
    coef.m_data[2][1] =  (m_data[0][0] * m_data[1][2] - m_data[0][2] * m_data[1][0]);
    coef.m_data[2][2] =  (m_data[0][0] * m_data[1][1] - m_data[0][1] * m_data[1][0]);

    coef.transpose();

    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            coef.m_data[i][j] = j % 2 ? -coef.m_data[i][j] : coef.m_data[i][j];

            if(i%2)
                coef.m_data[i][j] = -coef.m_data[i][j];
        }
    }

    return coef;
}

Matrix3x3f Matrix3x3f::inverse() const
{
    Matrix3x3f adjMat = adjoint();
    return adjMat * (1.0f / determinant());
}

Matrix3x3f operator +(const Matrix3x3f &m1, const Matrix3x3f &m2)
{
    return Matrix3x3f(m1) += m2;
}

Matrix3x3f operator -(const Matrix3x3f &m1, const Matrix3x3f &m2)
{
    return Matrix3x3f(m1) -= m2;
}

Matrix3x3f operator *(const Matrix3x3f &m1, const Matrix3x3f &m2)
{
    return Matrix3x3f(m1) *= m2;
}

Matrix3x3f operator *(const Matrix3x3f &mat, scalar_t r)
{
    return Matrix3x3f(mat) *= r;
}

Matrix3x3f operator *(scalar_t r, const Matrix3x3f &mat)
{
    return Matrix3x3f(mat) *= r;
}

const Matrix4x4f Matrix4x4f::identity = Matrix4x4f(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

Matrix4x4f::Matrix4x4f()
{
    *this = identity;
}

Matrix4x4f::Matrix4x4f( const scalar_t m11, const scalar_t m12, const scalar_t m13, const scalar_t m14,
                        const scalar_t m21, const scalar_t m22, const scalar_t m23, const scalar_t m24,
                        const scalar_t m31, const scalar_t m32, const scalar_t m33, const scalar_t m34,
                        const scalar_t m41, const scalar_t m42, const scalar_t m43, const scalar_t m44)
{
    m_data[0][0] = m11; m_data[0][1] = m12; m_data[0][2] = m13; m_data[0][3] = m14;
    m_data[1][0] = m21; m_data[1][1] = m22; m_data[1][2] = m23; m_data[1][3] = m24;
    m_data[2][0] = m31; m_data[2][1] = m32; m_data[2][2] = m33; m_data[2][3] = m34;
    m_data[3][0] = m41; m_data[3][1] = m42; m_data[3][2] = m43; m_data[3][3] = m44;
}

Matrix4x4f::Matrix4x4f(const mat4x4_t m)
{
    memcpy(m_data, m, sizeof(mat4x4_t));
}

Matrix4x4f::Matrix4x4f(const Matrix3x3f &mat)
{
    load_identity();
    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            m_data[i][j] = mat[i][j];
        }
    }
}

Matrix4x4f::Matrix4x4f(const Matrix4x4f &mat)
{
    load_identity();
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            m_data[i][j] = mat[i][j];
        }
    }
}

Matrix4x4f &Matrix4x4f::operator =(const Matrix3x3f &rhs)
{
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			m_data[i][j] = rhs[i][j];
		}
	}

	return *this;
}

Matrix4x4f &Matrix4x4f::operator =(const Matrix4x4f &rhs)
{
	for (unsigned int i = 0; i < 4; i++) {
		for (unsigned int j = 0; j < 4; j++) {
			m_data[i][j] = rhs[i][j];
		}
	}

	return *this;
}

Matrix4x4f &Matrix4x4f::operator +=(const Matrix4x4f &rhs)
{
    scalar_t *op1 = m_data[0];
    const scalar_t *op2 = rhs[0];

    for (unsigned int i = 0; i < 16; i++) {
        *op1++ += *op2++;
    }

	return *this;
}

Matrix4x4f &Matrix4x4f::operator -=(const Matrix4x4f &rhs)
{
    scalar_t *op1 = m_data[0];
    const scalar_t *op2 = rhs[0];

    for (unsigned int i = 0; i < 16; i++) {
        *op1++ -= *op2++;
    }

	return *this;
}

Matrix4x4f &Matrix4x4f::operator *=(const Matrix4x4f &rhs)
{
    Matrix4x4f res;
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            res.m_data[i][j] = m_data[i][0] * rhs[0][j] + 
                               m_data[i][1] * rhs[1][j] + 
                               m_data[i][2] * rhs[2][j] +
                               m_data[i][3] * rhs[3][j];

        }
    }
    memcpy(m_data, rhs[0], 16 * sizeof(scalar_t));

	return *this;
}

Matrix4x4f &Matrix4x4f::operator *=(const scalar_t r)
{
    scalar_t *mptr = m_data[0];

    for (unsigned int i = 0; i < 16; i++) {
        *mptr++ *= r;
    }

	return *this;
}

void Matrix4x4f::translate(const Vector3f &trans)
{
    Matrix4x4f tmat(1, 0, 0, trans.x, 0, 1, 0, trans.y, 0, 0, 1, trans.z, 0, 0, 0, 1);
    *this *= tmat;
}

void Matrix4x4f::set_translation(const Vector3f &trans)
{
    *this = Matrix4x4f(1, 0, 0, trans.x, 0, 1, 0, trans.y, 0, 0, 1, trans.z, 0, 0, 0, 1);
}

void Matrix4x4f::rotate(const Vector3f &euler)
{
    Matrix3x3f xrot, yrot, zrot;
    xrot = Matrix3x3f(1, 0, 0, 0, cos(euler.x), -sin(euler.x), 0, sin(euler.x), cos(euler.x));
    yrot = Matrix3x3f(cos(euler.y), 0, sin(euler.y), 0, 1, 0, -sin(euler.y), 0, cos(euler.y));
    zrot = Matrix3x3f(cos(euler.z), -sin(euler.z), 0, sin(euler.z), cos(euler.z), 0, 0, 0, 1);
    *this *= Matrix4x4f(xrot * yrot * zrot);
}

void Matrix4x4f::rotate(const Vector3f &axis, scalar_t angle)
{
    scalar_t sina = (scalar_t)sin(angle);
    scalar_t cosa = (scalar_t)cos(angle);
    scalar_t invcosa = 1-cosa;
    scalar_t nxsq = axis.x * axis.x;
    scalar_t nysq = axis.y * axis.y;
    scalar_t nzsq = axis.z * axis.z;

    Matrix3x3f xform;
    xform.m_data[0][0] = nxsq + (1-nxsq) * cosa;
    xform.m_data[0][1] = axis.x * axis.y * invcosa - axis.z * sina;
    xform.m_data[0][2] = axis.x * axis.z * invcosa + axis.y * sina;
    xform.m_data[1][0] = axis.x * axis.y * invcosa + axis.z * sina;
    xform.m_data[1][1] = nysq + (1-nysq) * cosa;
    xform.m_data[1][2] = axis.y * axis.z * invcosa - axis.x * sina;
    xform.m_data[2][0] = axis.x * axis.z * invcosa - axis.y * sina;
    xform.m_data[2][1] = axis.y * axis.z * invcosa + axis.x * sina;
    xform.m_data[2][2] = nzsq + (1-nzsq) * cosa;

    *this *= Matrix4x4f(xform);
}

void Matrix4x4f::set_rotation(const Vector3f &euler)
{
    Matrix3x3f xrot, yrot, zrot;
    xrot = Matrix3x3f(1, 0, 0, 0, cos(euler.x), -sin(euler.x), 0, sin(euler.x), cos(euler.x));
    yrot = Matrix3x3f(cos(euler.y), 0, sin(euler.y), 0, 1, 0, -sin(euler.y), 0, cos(euler.y));
    zrot = Matrix3x3f(cos(euler.z), -sin(euler.z), 0, sin(euler.z), cos(euler.z), 0, 0, 0, 1);
    *this = Matrix4x4f(xrot * yrot * zrot);
}

void Matrix4x4f::set_rotation(const Vector3f &axis, scalar_t angle)
{
    scalar_t sina = (scalar_t)sin(angle);
    scalar_t cosa = (scalar_t)cos(angle);
    scalar_t invcosa = 1-cosa;
    scalar_t nxsq = axis.x * axis.x;
    scalar_t nysq = axis.y * axis.y;
    scalar_t nzsq = axis.z * axis.z;

    load_identity();
    m_data[0][0] = nxsq + (1-nxsq) * cosa;
    m_data[0][1] = axis.x * axis.y * invcosa - axis.z * sina;
    m_data[0][2] = axis.x * axis.z * invcosa + axis.y * sina;
    m_data[1][0] = axis.x * axis.y * invcosa + axis.z * sina;
    m_data[1][1] = nysq + (1-nysq) * cosa;
    m_data[1][2] = axis.y * axis.z * invcosa - axis.x * sina;
    m_data[2][0] = axis.x * axis.z * invcosa - axis.y * sina;
    m_data[2][1] = axis.y * axis.z * invcosa + axis.x * sina;
    m_data[2][2] = nzsq + (1-nzsq) * cosa;
}

void Matrix4x4f::scale(const Vector4f &vec)
{
    Matrix4x4f smat(vec.x, 0, 0, 0, 0, vec.y, 0, 0, 0, 0, vec.z, 0, 0, 0, 0, vec.w);
    *this *= smat;
}

void Matrix4x4f::set_scaling(const Vector4f &vec)
{
     *this = Matrix4x4f(vec.x, 0, 0, 0, 0, vec.y, 0, 0, 0, 0, vec.z, 0, 0, 0, 0, vec.w);
}

void Matrix4x4f::set_column_vector(const Vector4f &vec, unsigned int index)
{
    m_data[0][index] = vec.x;
    m_data[1][index] = vec.y;
    m_data[2][index] = vec.z;
    m_data[3][index] = vec.w;
}

void Matrix4x4f::set_row_vector(const Vector4f &vec, unsigned int index)
{
    m_data[index][0] = vec.x;
    m_data[index][1] = vec.y;
    m_data[index][2] = vec.z;
    m_data[index][3] = vec.w;
}

Vector4f Matrix4x4f::get_column_vector(unsigned int index) const
{
    return Vector4f(m_data[0][index], m_data[1][index], m_data[2][index], m_data[3][index]);
}

Vector4f Matrix4x4f::get_row_vector(unsigned int index) const
{
    return Vector4f(m_data[index][0], m_data[index][1], m_data[index][2], m_data[index][3]);
}

void Matrix4x4f::transpose()
{
    Matrix4x4f tmp = *this;
    for (unsigned int i = 0; i < 4; i++) {
        for(unsigned int j = 0; j < 4; j++) {
            m_data[i][j] = tmp[j][i];
        }
    }
}

Matrix4x4f Matrix4x4f::transposed() const
{
    Matrix4x4f res;
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            res[i][j] = m_data[j][i];
        }
    }
    return res;
}

scalar_t Matrix4x4f::determinant() const
{
    scalar_t det11 = (m_data[1][1] * (m_data[2][2] * m_data[3][3] - m_data[3][2] * m_data[2][3])) -
                     (m_data[1][2] * (m_data[2][1] * m_data[3][3] - m_data[3][1] * m_data[2][3])) +
                     (m_data[1][3] * (m_data[2][1] * m_data[3][2] - m_data[3][1] * m_data[2][2]));

    scalar_t det12 = (m_data[1][0] * (m_data[2][2] * m_data[3][3] - m_data[3][2] * m_data[2][3])) -
                     (m_data[1][2] * (m_data[2][0] * m_data[3][3] - m_data[3][0] * m_data[2][3])) +
                     (m_data[1][3] * (m_data[2][0] * m_data[3][2] - m_data[3][0] * m_data[2][2]));

    scalar_t det13 = (m_data[1][0] * (m_data[2][1] * m_data[3][3] - m_data[3][1] * m_data[2][3])) -
                     (m_data[1][1] * (m_data[2][0] * m_data[3][3] - m_data[3][0] * m_data[2][3])) +
                     (m_data[1][3] * (m_data[2][0] * m_data[3][1] - m_data[3][0] * m_data[2][1]));

    scalar_t det14 = (m_data[1][0] * (m_data[2][1] * m_data[3][2] - m_data[3][1] * m_data[2][2])) -
                     (m_data[1][1] * (m_data[2][0] * m_data[3][2] - m_data[3][0] * m_data[2][2])) +
                     (m_data[1][2] * (m_data[2][0] * m_data[3][1] - m_data[3][0] * m_data[2][1]));

    return m_data[0][0] * det11 - m_data[0][1] * det12 + m_data[0][2] * det13 - m_data[0][3] * det14;
}

Matrix4x4f Matrix4x4f::adjoint() const
{
    Matrix4x4f coef;

    coef.m_data[0][0] = (m_data[1][1] * (m_data[2][2] * m_data[3][3] - m_data[3][2] * m_data[2][3])) -
                        (m_data[1][2] * (m_data[2][1] * m_data[3][3] - m_data[3][1] * m_data[2][3])) +
                        (m_data[1][3] * (m_data[2][1] * m_data[3][2] - m_data[3][1] * m_data[2][2]));

    coef.m_data[0][1] = (m_data[1][0] * (m_data[2][2] * m_data[3][3] - m_data[3][2] * m_data[2][3])) -
                        (m_data[1][2] * (m_data[2][0] * m_data[3][3] - m_data[3][0] * m_data[2][3])) +
                        (m_data[1][3] * (m_data[2][0] * m_data[3][2] - m_data[3][0] * m_data[2][2]));

    coef.m_data[0][2] = (m_data[1][0] * (m_data[2][1] * m_data[3][3] - m_data[3][1] * m_data[2][3])) -
                        (m_data[1][1] * (m_data[2][0] * m_data[3][3] - m_data[3][0] * m_data[2][3])) +
                        (m_data[1][3] * (m_data[2][0] * m_data[3][1] - m_data[3][0] * m_data[2][1]));

    coef.m_data[0][3] = (m_data[1][0] * (m_data[2][1] * m_data[3][2] - m_data[3][1] * m_data[2][2])) -
                        (m_data[1][1] * (m_data[2][0] * m_data[3][2] - m_data[3][0] * m_data[2][2])) +
                        (m_data[1][2] * (m_data[2][0] * m_data[3][1] - m_data[3][0] * m_data[2][1]));

    coef.m_data[1][0] = (m_data[0][1] * (m_data[2][2] * m_data[3][3] - m_data[3][2] * m_data[2][3])) -
                        (m_data[0][2] * (m_data[2][1] * m_data[3][3] - m_data[3][1] * m_data[2][3])) +
                        (m_data[0][3] * (m_data[2][1] * m_data[3][2] - m_data[3][1] * m_data[2][2]));

    coef.m_data[1][1] = (m_data[0][0] * (m_data[2][2] * m_data[3][3] - m_data[3][2] * m_data[2][3])) -
                        (m_data[0][2] * (m_data[2][0] * m_data[3][3] - m_data[3][0] * m_data[2][3])) +
                        (m_data[0][3] * (m_data[2][0] * m_data[3][2] - m_data[3][0] * m_data[2][2]));

    coef.m_data[1][2] = (m_data[0][0] * (m_data[2][1] * m_data[3][3] - m_data[3][1] * m_data[2][3])) -
                        (m_data[0][1] * (m_data[2][0] * m_data[3][3] - m_data[3][0] * m_data[2][3])) +
                        (m_data[0][3] * (m_data[2][0] * m_data[3][1] - m_data[3][0] * m_data[2][1]));

    coef.m_data[1][3] = (m_data[0][0] * (m_data[2][1] * m_data[3][2] - m_data[3][1] * m_data[2][2])) -
                        (m_data[0][1] * (m_data[2][0] * m_data[3][2] - m_data[3][0] * m_data[2][2])) +
                        (m_data[0][2] * (m_data[2][0] * m_data[3][1] - m_data[3][0] * m_data[2][1]));

    coef.m_data[2][0] = (m_data[0][1] * (m_data[1][2] * m_data[3][3] - m_data[3][2] * m_data[1][3])) -
                        (m_data[0][2] * (m_data[1][1] * m_data[3][3] - m_data[3][1] * m_data[1][3])) +
                        (m_data[0][3] * (m_data[1][1] * m_data[3][2] - m_data[3][1] * m_data[1][2]));

    coef.m_data[2][1] = (m_data[0][0] * (m_data[1][2] * m_data[3][3] - m_data[3][2] * m_data[1][3])) -
                        (m_data[0][2] * (m_data[1][0] * m_data[3][3] - m_data[3][0] * m_data[1][3])) +
                        (m_data[0][3] * (m_data[1][0] * m_data[3][2] - m_data[3][0] * m_data[1][2]));

    coef.m_data[2][2] = (m_data[0][0] * (m_data[1][1] * m_data[3][3] - m_data[3][1] * m_data[1][3])) -
                        (m_data[0][1] * (m_data[1][0] * m_data[3][3] - m_data[3][0] * m_data[1][3])) +
                        (m_data[0][3] * (m_data[1][0] * m_data[3][1] - m_data[3][0] * m_data[1][1]));

    coef.m_data[2][3] = (m_data[0][0] * (m_data[1][1] * m_data[3][2] - m_data[3][1] * m_data[1][2])) -
                        (m_data[0][1] * (m_data[1][0] * m_data[3][2] - m_data[3][0] * m_data[1][2])) +
                        (m_data[0][2] * (m_data[1][0] * m_data[3][1] - m_data[3][0] * m_data[1][1]));

    coef.m_data[3][0] = (m_data[0][1] * (m_data[1][2] * m_data[2][3] - m_data[2][2] * m_data[1][3])) -
                        (m_data[0][2] * (m_data[1][1] * m_data[2][3] - m_data[2][1] * m_data[1][3])) +
                        (m_data[0][3] * (m_data[1][1] * m_data[2][2] - m_data[2][1] * m_data[1][2]));

    coef.m_data[3][1] = (m_data[0][0] * (m_data[1][2] * m_data[2][3] - m_data[2][2] * m_data[1][3])) -
                        (m_data[0][2] * (m_data[1][0] * m_data[2][3] - m_data[2][0] * m_data[1][3])) +
                        (m_data[0][3] * (m_data[1][0] * m_data[2][2] - m_data[2][0] * m_data[1][2]));

    coef.m_data[3][2] = (m_data[0][0] * (m_data[1][1] * m_data[2][3] - m_data[2][1] * m_data[1][3])) -
                        (m_data[0][1] * (m_data[1][0] * m_data[2][3] - m_data[2][0] * m_data[1][3])) +
                        (m_data[0][3] * (m_data[1][0] * m_data[2][1] - m_data[2][0] * m_data[1][1]));

    coef.m_data[3][3] = (m_data[0][0] * (m_data[1][1] * m_data[2][2] - m_data[2][1] * m_data[1][2])) -
                        (m_data[0][1] * (m_data[1][0] * m_data[2][2] - m_data[2][0] * m_data[1][2])) +
                        (m_data[0][2] * (m_data[1][0] * m_data[2][1] - m_data[2][0] * m_data[1][1]));

    coef.transpose();

    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            coef.m_data[i][j] = j % 2 ? -coef.m_data[i][j] : coef.m_data[i][j];

            if (i % 2)
                coef.m_data[i][j] = -coef.m_data[i][j];
        }
    }

    return coef;
}

Matrix4x4f Matrix4x4f::inverse() const
{
    Matrix4x4f adjMat = adjoint();
    return adjMat * (1.0f / determinant());
}

Matrix4x4f operator +(const Matrix4x4f &m1, const Matrix4x4f &m2)
{
    return Matrix4x4f(m1) += m2;
}

Matrix4x4f operator -(Matrix4x4f &m1, const Matrix4x4f &m2)
{
    return Matrix4x4f(m1) -= m2;
}

Matrix4x4f operator *(const Matrix4x4f &m1, const Matrix4x4f &m2)
{
    return Matrix4x4f(m1) *= m2;
}

Matrix4x4f operator *(const Matrix4x4f &mat, scalar_t r)
{
    return Matrix4x4f(mat) *= r;
}

Matrix4x4f operator *(scalar_t r, const Matrix4x4f &mat)
{
    return Matrix4x4f(mat) *= r;
}

} /* namespace NMath */

#endif /* __cplusplus */
