#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intMatrix.h"

struct _IntMatrix {
	int rows;
	int cols;
	int* data;
};

void writeData(IntMatrix* m){
	int i;
	for(i = 0; i<(m->cols)*(m->rows); ++i)
		printf("%d ", m->data[ i ] );

	printf("\n");
}
static int * IntMatrix_CellAt(IntMatrix *m, unsigned i, unsigned j) {
	return m->data + (i * m->cols) + j;
}

int main (int argc, const char * argv[]) {
    // insert code here...
	int i , j, k = 0;
	IntMatrix* matrix, *transpose;
    printf("Hello, World!\n");
	
	matrix = IntMatrix_New(3, 3);
	for(i = 0; i<3;i++)
		for(j = 0; j<3 ; ++j)
		{
			setCell(matrix, i, j, ++k);
		}
	printf("Sono uscito dal ciclo e provo a stampare tutti i numeri nella matrice\n");
	writeData(matrix);
	printf("Trasponiamo: ");
	IntMatrix_Transpose(matrix);
	writeData(matrix);
	//setCell(matrix, 1, 2, 4);
	//printf("Cella impostata: %d \n", matrix->data[ 5 ]);
    return 0;
		
}

IntMatrix* IntMatrix_New(unsigned righe, unsigned colonne){
	IntMatrix* nMat = malloc(sizeof(IntMatrix));
	nMat->rows = righe;
	nMat->cols = colonne;
	nMat->data = malloc(righe*colonne*sizeof(int));
	
	return nMat;
}

void IntMatrix_Delete(IntMatrix* m){
	free(m->data);
	free(m);
}

void setCell(IntMatrix* m, unsigned i, unsigned j, int val)
{
	int* cella = m->data+i*(m->cols)+j;
	
	*cella = val;
}

void getCell(IntMatrix* m, unsigned i, unsigned j, int* val)
{
	int* cella = (m->data+i*(m->cols)+j);

	*val = *cella ;
}

unsigned IntMatrix_GetNumRows(IntMatrix* m){
	return m->rows;
}
unsigned IntMatrix_GetNumCols(IntMatrix* m){
	return m->cols;
}

void IntMatrix_Transpose(IntMatrix* m){
	int j = 0, k = 0, i = 0, r = (m->rows)*(m->cols), *cella;
	IntMatrix* res = IntMatrix_New(m->rows, m->cols);
	
	for (i=0; i<r; ++i) {
		//transpose the matrix
		j = i/(m->cols);
		k = i%(m->cols);
		*cella = res->data+k*(m->cols) + j; 
		*cella = (m->data + i);
	}
	for(i = 0; i<r; ++i)
	{	//dopo avere usato un ciclo per copiare la trasposta in una matrice di appoggio, devo ricopiare indietro i valori in quella originale
		*cella = m->data + i;
		*cella = res->data+ i;
	}
	
}

/* Comment space:
 allora vediamo come possiamo rappresentare questa matrice trasponendola:
 123 456 789
 147 258 369  quindi gli elementi sulla diagonale fanno "da perno" e non cambiano posizione
 Mentre gil altri elementi cambiano eccome. Ad esempio:
 Posizione |0 1| -> |1 0| ma |0 1| nella rappresentazione su unico array e': i*n+j = 1 e infatti
 il 2 sta esattamente nella seconda cella del mio array
 Ora il calcolo dovrebbe invertirsi ossia: j*n+i, possibile? Proviamo: |0 1| = 1*3+0 = 3
 Sembra che funzioni proviamo con qualcos'altro:
 Abbiamo ad esempio l'8 in posizione 7 e si trova in |2 1| = i*n+j = 2*3+1 = 7 
 Trasponendolo l'8 va in posizione 5, ovvero da |2 1| -> |1 2| = j*n+i = 1*3+2 = 5
 Esatto! Ok la traposizione dovrebbe riuscire abbastanza semplicemente applicando il ciclo for
 per poi andare a scrivere nella cella corretta che si trova a 
							j*n+i
 Ok questa e' la regola pero' io parto da i. Quindi devo riuscire a trovare il modo per invertire
 la posizione. 
*/
