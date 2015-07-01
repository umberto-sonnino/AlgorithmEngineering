/* =====================================================================
 *  make-matrix-file.c
 * =====================================================================

 *  Author:         (C) 2011 Camil Demetrescu
 *  License:        See the end of this file for license information
 *  Created:        May 21, 2011

 *  Last changed:   $Date: 2011/05/22 08:47:59 $
 *  Changed by:     $Author: demetres $
 *  Revision:       $Revision: 1.1 $
*/

#include <stdio.h>
#include <stdlib.h>

/* type of file items */
typedef unsigned item_type;


/* ---------------------------------------------------------------------
 *  main
 * ---------------------------------------------------------------------
*/
int main(int argc, char** argv){

    FILE* f;
    long s, i;
    long long N;
    
    /* check command line parameters */
    if (argc < 3) exit (printf("Usage: %s file-name matrix-side\n", argv[0]));
    
    /* convert matrix side from string to integer format */
    s = atol(argv[2]);
    N = (long long)s*s;

    /* open file for writing */
    f = fopen(argv[1], "w+");
    if (f == NULL) exit(printf("can't open file\n"));

    /* print info */
    printf("matrix size: %ld x %ld\n", s, s);
    printf("matrix cell size: %u bits\n", (unsigned)sizeof(item_type)*8);
    printf("output file name: %s\n", argv[1]);
    printf("output file size: %llu MB\n", N*sizeof(item_type)/(1024*1024));
    printf("creating file containing matrix in row-major order...\n");

    /* create file */
    for (i=0; i<N; ++i) {
        item_type val = i;
        fwrite(&val, sizeof(item_type), 1, f);
    }

    fclose(f);
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
