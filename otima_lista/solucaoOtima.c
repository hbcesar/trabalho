#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "TADsolucaoOtima.h"
#include "TADfuncoesComuns.h"

Interface_Lista* alocarInterface(){
	Interface_Lista* novo = (Interface_Lista*)malloc(sizeof(Interface_Lista));
	novo->primeiro = NULL;
	novo->ultimo = NULL;

	return novo;
}

void otima(int n, long int p, float** matriz){
	int* valor;
	Interface_Lista* il;
	//int** permutacoes;

	valor = alocarVetor(n);
	il = alocarInterface();
	// permutacoes = (int**) malloc(p*sizeof(int*));

	// if(permutacoes == NULL)
	// 	printf("ERRO: Nao há espaço suficiente em memória\n");

 	visit(0, n, valor, il);
 	//imprimeCombinacoes(permutacoes, n, p);
 	// calcularOtima(matriz, permutacoes, n, p);
 	// liberarVetores(permutacoes, valor, p);
}

void visit(int k, int n, int* valor, Interface_Lista* il){
  	int i;
  	static int level = -1;

    level = level+1;
    valor[k] = level;
    if (level == n)
      addItem(valor, il, n);
    else
      for (i = 0; i < n; i++)
        if (valor[i] == 0)
          visit(i, n, valor, il);
    
    level = level-1;
    valor[k] = 0;
}

void imprimeCombinacoes(int** permutacoes, int n, long int p){
	int i, j;

	printf("teste\n");

	for(i=0; i< p; i++){
		for(j=0; j<n; j++){
			printf("%d ", permutacoes[i][j]);
		}
		printf("\n");
	}
}

// void addItem(int* vetor, int** permutacoes, int n){
// 	static int indice = 0;
//   	int i = 0;

//   	int* novo = (int*)malloc(n*sizeof(int));

//   	for(i=0; i<n; i++){
//   		novo[i]=vetor[i] -1;
//   	}

//   	permutacoes[indice++] = novo;
// }

void addItem(int* vetor, Interface_Lista* il, int n){
	static int indice = 0;
  	int i = 0;

  	int* novo_vetor = (int*)malloc(n*sizeof(int));
  	Lista_Permutacoes* novo_no = (Lista_Permutacoes*)malloc(sizeof(Lista_Permutacoes));

  	for(i=0; i<n; i++){
  		novo_vetor[i]=vetor[i] -1;
  	}

  	novo_no->permutacoes=novo_vetor;
  	novo_no->prox = NULL;

  	//permutacoes[indice++] = novo;
  	if(il->primeiro == NULL){
  		il->primeiro = novo_no;
  		il->ultimo = il->primeiro;
  	} else{
  		il->ultimo->prox = novo_no;
  		il->ultimo = il->ultimo->prox;
  	}
}

void calcularOtima(float** matriz, int** permutacoes, int n, long int p){
	int i, j, a, b;
	float menor=FLT_MAX, soma =0;
	int indice_menor=0;

	for(i=0; i<p; i++){
		for(j=0; j<n-1; j++){
			a = permutacoes[i][j];
			b = permutacoes[i][j+1];
			soma = soma + matriz[a][b];
		}
		a = permutacoes[i][n-1];
		b = permutacoes[i][0];
		soma = soma + matriz[a][b];
		if(soma<menor){
			menor = soma;
			indice_menor = i;
		}
		soma = 0;
	}

	imprimirCaminho(permutacoes[indice_menor], menor, n);

}

void liberarVetores(int** permutacoes, int* valor, long int p){
	int i;

	for(i=0; i<p; i++){
		free(permutacoes[i]);
	}

	free(valor);
	free(permutacoes);
}