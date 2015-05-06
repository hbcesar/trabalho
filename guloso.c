#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADfuncoesComuns.h"
#include "TADguloso.h"

void alocarLista(){
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

	for(i=0; i<posicao; i++){
		aux = aux->prox;
	}

	novo->prox = aux->prox;
	aux->prox = novo;

	if(lista->ultima->prox != NULL)
		lista->ultima = lista->ultima->prox;

	return lista;
}

float calcularCusto(Cidade* a, Cidade* b, Cidade* c){
	int i=0, j=0;
	float custo;

	i=a->numero;
	j=b->numero;
	custo = matriz[i-1][j-1];

	i=b->numero;
	j=c->numero;
	custo = custo + matriz[i-1][j-1];

	return custo;
}

float custoTotal(Interface* lista){
	float custo = 0.0;
	int i=0,j=0;
	Cidade* aux = lista->primeira;
	Cidade* aux2 = aux->prox;

	while(aux2->prox != NULL){
		i=aux->numero;
		j=aux2->numero;
		custo = custo + matriz[i-1][j-1];

		aux = aux->prox;
		aux2 = aux2->prox;
	}

	i=lista->ultima->numero;
	j=lista->primeira->numero;
	custo = custo + matriz[i-1][j-1];

	return custo;
}

void guloso(float** matriz, int n){
	Interface* lista;
	Cidade* novo;
	Cidade *aux; *aux2;
	int i, j, posicao=0;
	float custo = 0.0;

	lista = alocarLista();

	for(i=1; i<n-1; i++){
		novo = criarCidade(i);
		aux = lista->primeira;
		aux2 = aux->prox;

		menor = calcularCusto(lista->ultima, novo, lista->primeira);
		j=0;

		while(aux2->prox != NULL){
			custo = calcularCusto(aux, novo, aux2);
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
	
	// for (aux2=listaaux;aux2!=NULL;aux2=aux2->prox){
	// 	printf("%d \n",aux2->numero);
	// }

	// printf("%d \n",custo_total);
	// printf("*\n");

	//LIBERAR LISTA
}


