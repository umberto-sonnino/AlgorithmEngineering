/* =====================================================================
 *  mat-transp-AUTHOR.c
 * =====================================================================

 *  Author:         (C) 2011 Author #1, Author #2
 *  License:        See the end of this file for license information
 *  Created:        mm dd, yy

 *  Last changed:   $Date: 2011/05/22 08:47:59 $
 *  Changed by:     $Author: demetres $
 *  Revision:       $Revision: 1.1 $
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "mat-transp.h"

/* ---------------------------------------------------------------------
 *  mat_transp
 * ---------------------------------------------------------------------
*/
void block_print(unsigned *block, long b){
	int l;
	for(l = 0; l<b*b;l++){
		if(l%b == 0)
		printf("\n");
		printf("%d ", block[l]);
		}
}
void block_transpose(unsigned *block, long b){
	int m, o;
	unsigned aux;
	
	for(m = 0; m<=b-2;m++)
		for(o=m+1;o<=b-1;o++){
			aux = block[m*b+o];
			block[m*b+o] = block[o*b+m];
			block[o*b+m] = aux;
		}
}
void mat_transp(FILE* f, long n, long b) {
    /* to be done... */
    
	int i, j, k;
	unsigned* blocco, *temp;
	
	
	blocco = malloc(b*b*sizeof(unsigned));//inizializzo un blocco pari ad una sottomatrice quadrata
	temp = malloc(b*b*sizeof(unsigned));
	for(i = 0; i < n/b; ++i)
		for(j = i; j < n/b; ++j){
			
					if(j==i){
						fseek(f, (j*b+i*n*b)*sizeof(unsigned), SEEK_SET);
						k=0;
						do{
							fread(&blocco[k*b], sizeof(unsigned), b, f);
							fseek(f, (n-b)*sizeof(unsigned), SEEK_CUR);	
							++k;
						}while(k<b);

						block_transpose(blocco, b);
						
						fseek(f, (j*b+i*n*b)*sizeof(unsigned), SEEK_SET);
						k=0;
						do{
							fwrite(&blocco[k*b], sizeof(unsigned), b, f);
							fseek(f, (n-b)*sizeof(unsigned), SEEK_CUR);
							++k;
						}while(k<b);
						
					}
					
					else{
					fseek(f, (j*b+i*n*b)*sizeof(unsigned), SEEK_SET);
					k = 0;
					do{
						fread(&blocco[k*b], sizeof(unsigned), b, f);
						fseek(f, (n-b)*sizeof(unsigned), SEEK_CUR);
						++k;
					}while(k<b);
					
					block_transpose(blocco, b);
					
					fseek(f, (i*b+j*n*b)*sizeof(unsigned), SEEK_SET);
					k = 0;
					do{	
						fread(&temp[k*b], sizeof(unsigned), b, f);
						fseek(f, (n-b)*sizeof(unsigned), SEEK_CUR);
						++k;
					}while(k<b);
					
					block_transpose(temp, b);
					
					fseek(f, (i*b+j*n*b)*sizeof(unsigned), SEEK_SET);
					k = 0;
					do{
						fwrite(&blocco[k*b], sizeof(unsigned), b, f);
						fseek(f, (n-b)*sizeof(unsigned), SEEK_CUR);
						++k;
					}while(k<b);
					
					fseek(f, (j*b+i*n*b)*sizeof(unsigned), SEEK_SET);
					k = 0;
					do{
						fwrite(&temp[k*b], sizeof(unsigned), b, f);
						fseek(f, (n-b)*sizeof(unsigned), SEEK_CUR);
						++k;
					}while(k<b);
				}
	}	
	
}
/* Copyright (C) 2011 Author #1, Author #2

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
