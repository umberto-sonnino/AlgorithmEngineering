#include <stdio.h>
#include <stdlib.h>


//sezione di codice per trasporre una qualunque matrice di int

int main(){
int i, j, matrix[4][4], k, l;

k = 0;
l = 0;
for(i = 0; i<4;i++){
	for(j=0;j<4;j++){
		matrix[i][j] = k++;
		printf("%d ", matrix[i][j]);
	}
	printf("\n");
}

for(i = 0; i<3;i++){
	for(j=i+1;j<4;j++){
		l = matrix[i][j];
		matrix[i][j] = matrix[j][i];
		matrix[j][i] = l;
	}
}
printf("\n");
for(i = 0; i<4;i++){
	for(j=0;j<4;j++){
		printf("%d ", matrix[i][j]);
	}
	printf("\n");
}
printf("\n");
for(i = 0; i<3;i++){
	for(j=i+1;j<4;j++){
		printf("i:%d j:%d ", i, j);
	}
	printf("\n");
}

return 0;

}
