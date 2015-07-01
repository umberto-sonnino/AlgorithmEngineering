/* =====================================================================
 *  mat-transp.h
 * =====================================================================

 *  Author:         (C) 2011 Camil Demetrescu
 *  License:        See the end of this file for license information
 *  Created:        May 21, 2011

 *  Last changed:   $Date: 2011/05/22 07:45:10 $
 *  Changed by:     $Author: demetres $
 *  Revision:       $Revision: 1.3 $
*/

#ifndef __MAT_TRANSP__
#define __MAT_TRANSP__

#include <stdio.h>


/* type of matrix cells */
typedef unsigned item_type;


/** Perform in-place transposition of n x n square matrix of 32-bit   
    values contained in a file.
    @param f pointer to file containing the matrix to be transposed
    @param n number of columns and rows of the matrix
    @param b block size for file accesses
    @return size of main memory used for transposition in bytes
*/
void mat_transp(FILE* f, long n, long b);

#endif


/* Copyright (C) 2011 Camil Demetrescu

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
*/
