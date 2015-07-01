#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//sezione di codice per trasporre una qualunque matrice di int
//letta da file in row-major
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
void mat_transp(FILE* f, long n, long b){
	
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
						printf("BLOCCO DIAGONALE:\n");
						block_print(blocco, b);
						block_transpose(blocco, b);
						printf("TRASPOSTO:\n");
						block_print(blocco, b);
						
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
					
					printf("\nBLOCCO:\n");
					block_print(blocco, b);

					block_transpose(blocco, b);

					printf("\nBLOCCO TRASPOSTO:\n");
					block_print(blocco, b);
					
					fseek(f, (i*b+j*n*b)*sizeof(unsigned), SEEK_SET);
					k = 0;
					do{	
						fread(&temp[k*b], sizeof(unsigned), b, f);
						fseek(f, (n-b)*sizeof(unsigned), SEEK_CUR);
						++k;
					}while(k<b);
					
					printf("\nTEMP:\n");
					block_print(temp, b);
					
					block_transpose(temp, b);
					
					printf("\nTEMP TRASPOSTO:\n");
					block_print(temp, b);
					
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

int main(int argc, char** argv){

FILE *fp;


fp = fopen("9x9.mat", "r+");

mat_transp(fp, 9, 3);


return 1;

}

