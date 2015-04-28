#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADfuncoesComuns.h"
#include "TADsolucaoOtima.h"
#include "TADnn.h"
#include "TADalgoritmoGenetico.h"
#define exato 1
#define nn 2
#define guloso 3
#define genetico 4



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
	int n, tipo, valor = 0;
	long int p = 0;
	int* caminho = NULL;

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
	else if(tipo == nn){
		caminho = nearestNeighbor(0, n, matriz, &valor);
		imprimirCaminho(caminho, valor, n);
	}
	else if (tipo == guloso){}
		//chama funcao guloso
	else if (tipo == genetico){
		algoritmoGenetico(matriz, n);
	}

	//libera a memoria alocada para matriz
	liberarMatriz(n, matriz);


	return 0;

}