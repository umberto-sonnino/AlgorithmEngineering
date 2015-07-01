/* =====================================================================
 *  check-mat-transp.c
 * =====================================================================

 *  Author:         (C) 2011 Camil Demetrescu
 *  License:        See the end of this file for license information
 *  Created:        May 21, 2011

 *  Last changed:   $Date: 2011/05/22 08:37:01 $
 *  Changed by:     $Author: demetres $
 *  Revision:       $Revision: 1.2 $
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* macros, types, function prototypes */
#define B 4000000

typedef unsigned item_type;

static void check_mat(FILE* f, long n);


/* ---------------------------------------------------------------------
 *  main
 * ---------------------------------------------------------------------
*/
int main(int argc, char** argv) {

    FILE* f;
    long long s;
    long n;

    /* check command line parameters */
    if (argc < 2) 
        exit(printf("Usage: %s filename\n", argv[0]));

    /* open file for read */
    f = fopen(argv[1], "r");
    if (f == NULL) exit((printf("can't open file %s\n", argv[1]), 1));

    /* compute number s of matrix elements in the file */
    fseeko(f, 0LL, SEEK_END);
    s = ftello(f)/sizeof(item_type);
    fseeko(f, 0LL, SEEK_SET);

    /* compute matrix side */
    n = (long)sqrt(s);

    /* check if matrix is squared */
    if (n*n != s) exit((printf("matrix is not squared\n"), 1));

    /* print info */
    printf("file size: %lld bytes\n", s);
    printf("matrix size: %ld x %ld\n", n, n);

    /* check if matrix is transposed */
    printf("checking matrix...\n");
    check_mat(f, n);

    fclose(f);

    return 0;
}


/* ---------------------------------------------------------------------
 *  check_mat
 * ---------------------------------------------------------------------
*/
static void check_mat(FILE* f, long n) {

    item_type* buf = malloc(B*sizeof(item_type));
    if (buf == NULL) exit((printf("out of memory\n"), 1));

    size_t k, r;
    long c = 0, transp = 0, normal = 0, i, j;

    for (;;) {
        r = fread(buf, sizeof(item_type), B, f);
        if (r == 0) break;
        for (k = 0; k < r; k++) {
            i = c/n;
            j = c%n;
            if (i == j) {
                if (buf[k] != i*n+j) goto err;
            }
            else if (buf[k] == i*n+j) {
                if (transp > 0) goto err;
                normal++;
            }
            else if (buf[k] == j*n+i) {
                if (normal > 0) goto err;
                transp++;
            }
            else goto err;
            c++;
        }
    }

    if (normal) printf("*** ERROR: non-transposed matrix ***\n");
    else printf("*** OK: transposed matrix ***\n");

    free(buf);
    
    return;

  err:
    printf("*** ERROR: cell M[%ld][%ld]=%u\n", i, j, buf[k]);
    exit(1);
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
