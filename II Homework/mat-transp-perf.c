/* =====================================================================
 *  test-mat-transp.c
 * =====================================================================

 *  Author:         (C) 2011 Camil Demetrescu
 *  License:        See the end of this file for license information
 *  Created:        May 21, 2011

 *  Last changed:   $Date: 2011/05/22 08:37:01 $
 *  Changed by:     $Author: demetres $
 *  Revision:       $Revision: 1.2 $
*/

#include "mat-transp.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <sys/resource.h>


/* ---------------------------------------------------------------------
 *  main
 * ---------------------------------------------------------------------
*/
int main(int argc, char** argv) {

    FILE* f;
    long long s;
    long n, b;
    struct rusage rusage;

    /* check command line parameters */
    if (argc < 3) 
        exit(printf("Usage: %s filename blocking-size\n", argv[0]));

    /* open file for update */
    f = fopen(argv[1], "r+");
    if (f == NULL) exit((printf("can't open file %s\n", argv[1]), 1));

    /* compute number s of matrix elements in the file */
    fseeko(f, 0LL, SEEK_END);
    s = ftello(f)/sizeof(item_type);

    /* compute matrix side */
    n = (long)sqrt(s);

    /* check if matrix is squared */
    if (n*n != s) exit((printf("matrix is not squared\n"), 1));

    /* convert block size from string to integer format */
    b = atol(argv[2]);
    if (b > n) b = n;

    /* print info */
    printf("file size: %lld bytes\n", s);
    printf("file offset model: %ld bit\n", (long)sizeof(off_t)*8);
    printf("matrix size: %ld x %ld\n", n, n);
    printf("block size: %ld items\n", b);

    /* in-place transposition of matrix on file */
    printf("transposing matrix...\n");
    mat_transp(f, n, b);

    fclose(f);

    /* print required internal memory */
    getrusage(RUSAGE_SELF, &rusage);
    printf("used internal memory: %ld MB\n",
        rusage.ru_maxrss/(1024*1024));

    return 0;
}


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
