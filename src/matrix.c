/*

    This file is part of the nemesis math library.

    matrix.c
    Matrices

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
extern "C" {
#endif	/* __cplusplus */

void mat3x3_print(FILE *fp, mat3x3_t m)
{
    int i;
    for(i=0; i<3; i++)
    {
        fprintf(fp, "[ %12.5f %12.5f %12.5f ]\n", (float)m[i][0], (float)m[i][1], (float)(float)m[i][2]);
    }
}

void mat4x4_print(FILE *fp, mat4x4_t m)
{
    int i;
    for(i=0; i<4; i++)
    {
        fprintf(fp, "[ %12.5f %12.5f %12.5f %12.5f ]\n", (float)m[i][0], (float)m[i][1], (float)m[i][2], (float)m[i][3]);
    }
}

#ifdef __cplusplus
}   /* extern "C" */
#endif
