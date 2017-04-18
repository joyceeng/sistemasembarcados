#include <stdio.h>
#include <pthread.h>


pthread_t thread_1;


void* tarefa_1(void *p, int A[][61], int B[][60], int i){
long int c[i][j] = 0;
int q, w;
for (i = 0; i < 60; i++){
	printf("\nThread %d\n", i);
		for (q = 0; q < 60; q++){
			printf("\n");
			for (w = 0; w < 60; w++){
				c[q][w] = c[q][w] + a[q][w]*b[w][q];
			}
				printf ("%d\t", c[q][w]);
		}

	}
}

int main (){

long int A[60][61];
long int B[61][60];
int i, j, k, m;

	for (i = 0; i < 60; i++){
		printf("\n");
		for (j = 0; j < 61 ; j++){
			A[i][j] = rand();
			printf ("%d\t", A[i][j]); 
		}
	}

	for (k = 0; k < 61; k++){
		printf("\n");
		for (m = 0; m < 60 ; m++){
			B[k][m] = rand();
			printf ("%d\t", B[k][m]); 
		}
	}

for (i = 0; i < 60; i++){
    	pthread_create(&thread_1, NULL, tarefa_1, NULL, A[60][61], B[61][60], i)
}

return 0;
}
