#include <stdio.h>
#include <stdlib.h>
#include "TADsolucaoOtima.h"
#include "TADfuncoesComuns.h"

float** alocarMatriz(int n){
	float** matriz;
	int i, j;

	matriz = (float**)malloc(n*sizeof(float*));

	for(i=0; i<n; i++){
		matriz[i]=(float*)malloc(n*sizeof(float));
	}

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			matriz[i][j]=0;
		}
	}

	return matriz;
}

void lerMatriz(int n, float** matriz){
	int i, j;

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%f", &matriz[i][j]);
		}
	}

}

void imprimirMatriz(int n, float** matriz){
	int i,j;

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%.2f\t", matriz[i][j]);
		}
		printf("\n");
	}
}

void liberarMatriz(int n, float** matriz){
	int i;

	for(i=0; i<n; i++){
		free(matriz[i]);
	}

	free(matriz);
}

int main(int argc, char* argv []){
	float** matriz = NULL;
	int n;
	long int p=0;

	n = atoi(argv[1]);
	p = fatorial(n);

	matriz = alocarMatriz(n);
	lerMatriz(n, matriz);
	//imprimirMatriz(n, matriz);
	otima(n, p, matriz);

	liberarMatriz(n, matriz);

	return 0;

}