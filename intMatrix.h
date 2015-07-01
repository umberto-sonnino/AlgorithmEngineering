/*
 *  intMatrix.h
 *  Matrix
 *
 *  Created by Archetype on 6/1/11.
 *  Copyright 2011 Archetype. All rights reserved.
 *
 */

#ifndef _INT_MATRIX_H
#define _INT_MATRIX_H
	
typedef struct _IntMatrix IntMatrix;

IntMatrix * IntMatrix_New(unsigned righe, unsigned colonne);
void IntMatrix_Delete(IntMatrix* m);
void setCell(IntMatrix* m, unsigned i, unsigned j, int val);
void getCell(IntMatrix* m, unsigned i, unsigned j, int* val);
unsigned IntMatrix_GetNumRows(IntMatrix* m);
unsigned IntMatrix_GetNumCols(IntMatrix* m);
void IntMatrix_Transpose(IntMatrix* m);
IntMatrix* IntMatrix_Copy(IntMatrix* m);
IntMatrix* IntMatrix_Sum(IntMatrix* a, IntMatrix* b);
IntMatrix* IntMatrix_Prod(IntMatrix* a, IntMatrix* b);

#endif
