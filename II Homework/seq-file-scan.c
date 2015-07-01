/* =====================================================================
 *  seq-file-scan.c
 * =====================================================================

 *  Author:         (C) 2011 Camil Demetrescu
 *  License:        See the end of this file for license information
 *  Created:        May 25, 2011

 *  Last changed:   $Date: 2011/05/25 20:07:26 $
 *  Changed by:     $Author: demetres $
 *  Revision:       $Revision: 1.1 $
*/

#include <stdio.h>
#include <stdlib.h>

/* 64 MB RAM buffer */
#define B 64*1024*1024

int main(int argc, char** argv){

	FILE* f;
	void* buf;

	/* check command line parameters */
	if (argc < 2) exit(printf("Usage: %s file-name\n", argv[0]));

	/* open file for reading */
	f = fopen(argv[1], "r");
	if (f == NULL) exit((printf("can't open file %s\n", argv[1]), 1));

	/* allocate block */
	buf = malloc(B);
	if (buf == NULL) exit((printf("out of memory\n"), 1));

	/* read file sequentially */
	printf("read file sequentially...\n");
	while (fread(buf, 1, B, f) > 0);

	/* cleanup */
	free(buf);
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
