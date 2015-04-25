#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADsolucaoOtima.h"
#include "TADfuncoesComuns.h"
#include "TADalgoritmoGenetico.h"
#define exato 1
#define nn 2
#define guloso 3
#define genetico 4

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

int defineTipo(char* tipo){
	if(strcmp(tipo, "exato") == 0)
		return exato;
	else if(strcmp(tipo, "nn") == 0)
		return nn;
	else if(strcmp(tipo, "guloso") == 0)
		return guloso;
	else if(strcmp(tipo, "genetico") == 0)
		return genetico;
	else return 0;
}

int main(int argc, char* argv []){
	float** matriz = NULL;
	int n, tipo;
	long int p = 0;
	int** filhos;

	//obtem o numero de linhas da matriz
	n = atoi(argv[1]);
	//obtem o numero de combinacoes que serao realizadas
	p = fatorial(n);

	//aloca espaço para a matriz
	matriz = alocarMatriz(n);
	//le as entradas da matriz
	lerMatriz(n, matriz);
	//imprimirMatriz(n, matriz);
	
	tipo = defineTipo(argv[2]);
	if(tipo == exato)
		otima(n, p, matriz);
	else if(tipo == nn){}
		//chama funcao nn
	else if (tipo == guloso){}
		//chama funcao guloso
	else if (tipo == genetico){}
		//chama funcao genetico

	//libera a memoria alocada para matriz
	liberarMatriz(n, matriz);


	return 0;

}