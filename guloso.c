#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADfuncoesComuns.h"
#include "TADguloso.h"

Interface* alocarLista(int n){
	Interface* novo = (Interface*)malloc(sizeof(Interface));

	novo->primeira = criarCidade(0);
	novo->ultima = criarCidade(n-1);
	novo->primeira->prox = novo->ultima;

	return novo;
}

Cidade* criarCidade(int n){
	Cidade* novo = (Cidade*)malloc(sizeof(Cidade));

	novo->numero = n;
	novo->prox = NULL;

	return novo;
}

Cidade* inserirLista(Interface* lista, Cidade* novo, int posicao){
	Cidade* aux = lista->primeira;
	int i;

	if(posicao == 0){
		novo->prox = aux;
		lista->primeira = novo;
		return lista->primeira;
	}

	for(i=0; i<posicao-1; i++){
		aux = aux->prox;
	}

	novo->prox = aux->prox;
	aux->prox = novo;

	if(lista->ultima->prox != NULL)
		lista->ultima = lista->ultima->prox;

	return lista->primeira;
}

float calcularCusto(float** matriz, Cidade* a, Cidade* b, Cidade* c){
	int i=0, j=0;
	float custo = 0;

	i=a->numero;
	j=b->numero;
	custo = matriz[i][j];

	i=b->numero;
	j=c->numero;
	custo = custo + matriz[i][j];

	return custo;
}

float custoTotal(Interface* lista, float** matriz){
	float custo = 0.0;
	int i=0,j=0;
	Cidade* aux = lista->primeira;
	Cidade* aux2 = aux->prox;

	while(aux2->prox != NULL){
		i=aux->numero;
		j=aux2->numero;
		custo = custo + matriz[i][j];

		aux = aux->prox;
		aux2 = aux2->prox;
	}

	i=aux->numero;
	j=aux2->numero;
	custo = custo + matriz[i][j];

	i=lista->ultima->numero;
	j=lista->primeira->numero;
	custo = custo + matriz[i][j];

	return custo;
}

void liberarLista(Interface* lista){
	Cidade* aux = lista->primeira;
	Cidade* aux2 = aux->prox;

	while(aux2 != NULL){
		free(aux);
		aux = aux2;
		aux2 = aux2->prox;
	}

	free(aux); //libera o ultimo no da lista
	free(lista); //libera interface

}

void metodo_guloso(float** matriz, int n){
	Interface* lista;
	Cidade* novo;
	Cidade *aux, *aux2;
	int i, j, posicao=0;
	float custo = 0.0, menor = 0.0;

	lista = alocarLista(n);

	for(i=1; i<n-1; i++){
		novo = criarCidade(i);
		aux = lista->primeira;
		aux2 = aux->prox;

		menor = calcularCusto(matriz, lista->ultima, novo, lista->primeira);
		j=0;

		while(aux2->prox != NULL){
			custo = calcularCusto(matriz, aux, novo, aux2);
			aux = aux2;
			aux2 = aux2->prox;
			if(custo < menor){
				posicao = j;
				menor = custo;
			}
			j++;
		}

		lista->primeira = inserirLista(lista, novo, posicao);
	}

	aux = lista->primeira;
	custo = custoTotal(lista, matriz);
	
	while(aux!=NULL){
	 	printf("%d \n",aux->numero);
	 	aux = aux->prox;
	}

	printf("%.2f \n",custo);
	printf("*\n");

	liberarLista(lista);
}



