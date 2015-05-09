#include <stdlib.h>
#include <stdio.h>
#include "TADfuncoesComuns.h"

long int fatorial(int n){
	if(n==1)
		return 1;
	else
		return (n*fatorial(n-1));
}

int* alocarVetor(int n){
	int i;
	int* vet;

	vet = (int*)malloc(n*sizeof(int));

	for(i=0; i<n; i++){
		vet[i] = 0;
	}

	return vet;
}

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

void liberarMatriz(int n, float** matriz){
	int i;

	for(i=0; i<n; i++){
		free(matriz[i]);
	}

	free(matriz);
}

//retorna o custo de um caminho (usando vetor)
float custo(float** matriz, int* vetor, int n){
	int i;
	int a, b;
	float soma = 0;

	for(i=0; i<n-1; i++){
		a = vetor[i];
		b = vetor[i+1];
		soma = soma + matriz[a][b];
	}

	//soma o fim do percurso, a volta da ultima cidade para a primeira
	a = vetor[n-1];
	b = vetor[0];
	soma = soma + matriz[a][b];

	return soma;

}

//imprime o caminho (usando vetor)
void imprimirCaminho(int* caminho, float soma, int n){
	int i;

	for(i=0; i<n; i++){
		printf("%d\n", caminho[i]);
	}

	printf("%.2f\n", soma);

	printf("*\n");

}