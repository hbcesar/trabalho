#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "TADfuncoesComuns.h"


float menor(float* vetor, int n, int* indice_menor){
	float menor = FLT_MAX;
	int i;

	for(i=0;i<n;i++){
		if (vetor[i] < menor){
			menor = vetor[i];
			(*indice_menor) = i;
		}
	}

	return menor;
}

float** copiarMatriz(int n, float** matriz){
	int i, j;
	float** novo = alocarMatriz(n);

	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			novo[i][j] = matriz[i][j];
		}
	}

	return novo;
}



int* nearestNeighbor(int primeira_cidade, int n, float** matriz, int* valor){
	float* vetor_aux = (float*)malloc(n*sizeof(float));
	float* vetor;
	int* caminho = (int*)malloc(n*sizeof(int));
	int i, j, indice_menor = primeira_cidade-1; //esse -1 serve para "adequar" a leitura de vetores/matrizes
	float soma = 0, aux;


	for(i=0; i<n; i++){
		vetor_aux[i]=matriz[i][primeira_cidade-1];
	}

	for (i=0;i<n-1;i++){
		//inicia construindo o caminho, gravando a primeira cidade
		caminho[i]=indice_menor;

		for (j=0;j<n;j++){
			matriz[j][indice_menor] = FLT_MAX;
		}

	 	vetor = matriz[indice_menor];
	 	aux = menor(vetor, n, &indice_menor); //acha o menor valor da linha da matriz
		soma = soma + aux; // soma esses valores

		
	}

	//recebe o ultimo indice, ou seja, a ultima cidade do caminho antes de voltar para o ciclo
	caminho[i]=indice_menor;

	//soma a volta para a primeira cidade
	soma = soma + vetor_aux[indice_menor];
	
	if(valor != NULL)
		(*valor) = soma;

	//libera vetores temporariamente alocados para calculo
	free(vetor_aux);
	free(vetor);

	return caminho;

}