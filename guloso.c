#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADfuncoesComuns.h"
#include "TADguloso.h"

//interface contendo ponteiro para primeiro e ultimo elemento da lista de cidades
Interface* alocarLista(int n){
	Interface* novo = (Interface*)malloc(sizeof(Interface));

	novo->primeira = criarCidade(0);
	novo->ultima = criarCidade(n-1);
	novo->primeira->prox = novo->ultima;

	return novo;
}

//cria novo nó para lista/cidade
Cidade* criarCidade(int n){
	Cidade* novo = (Cidade*)malloc(sizeof(Cidade));

	novo->numero = n;
	novo->prox = NULL;

	return novo;
}

//insere a nova cidade na lista dada posicao
Cidade* inserirLista(Interface* lista, Cidade* novo, int posicao){
	Cidade* aux = lista->primeira;
	int i;

	//para o caso do novo elemento a ser inserido vier a
	//se tornar o primeiro da lista
	if(posicao == 0){
		novo->prox = aux;
		lista->primeira = novo;
		return lista->primeira;
	}

	//caso nao for o primeiro (se funcao nao retornou)
	//percorre o ponteiro até posicao de insercao
	for(i=0; i<posicao-1; i++){
		aux = aux->prox;
	}

	//insere
	novo->prox = aux->prox;
	aux->prox = novo;

	//caso o no seja inserido no final, atualiza interface lista
	if(lista->ultima->prox != NULL)
		lista->ultima = lista->ultima->prox;

	return lista->primeira;
}

float calcularCusto(float** matriz, Cidade* a, Cidade* b, Cidade* c){
	int i=0, j=0;
	float custo = 0.0;

	//calcula custo de cidade A para B
	i=a->numero;
	j=b->numero;
	custo = matriz[i][j];

	//calcula custo de cidade B para C e soma com custo de A para B
	i=b->numero;
	j=c->numero;
	custo = custo + matriz[i][j];

	return custo;
}

float custoTotal(Interface* lista, float** matriz, int n){
	float custo = 0.0;
	int i=0,j=0, k;
	Cidade* aux = lista->primeira;
	Cidade* aux2 = aux->prox;

	//percorre a lista toda somando o custo de uma cidade para outra
	for(k=0; k<n-1; k++){
		i=aux->numero;
		j=aux2->numero;
		custo = custo + matriz[i][j];

		aux = aux->prox;
		aux2 = aux2->prox;
	}

	//ao final do loop calcula o custo para se retornar da ultima cidade da lista
	//para a primeira
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
		novo = criarCidade(i); //cria no
		aux = lista->primeira; //seta auxiliar para primeiro elemento da lista
		aux2 = aux->prox;

		//calcula custo caso a cidade seja a primeira/ultima da lista
		menor = calcularCusto(matriz, lista->ultima, novo, lista->primeira);
		j=0;

		/*
		 * entra em loop e calcula o custo caso a cidade seja inserida 
		 * em posicoes intermediarias da lista
		 * Importante demonstrar que o nó NAO é inserido na lista
		 * até que se ache a melhor posicao a ser inserida
		 */
		while(aux2->prox != NULL){
			custo = calcularCusto(matriz, aux, novo, aux2);
			aux = aux2;
			aux2 = aux2->prox;
			j++; //atualiza a variavel da posicao
			
			if(custo < menor){
				posicao = j;
				menor = custo;
			}

		}

		//efetivamente insere o nó na lista
		lista->primeira = inserirLista(lista, novo, posicao);
	}

	//retorna aux pro começo pra calcular o custo total final
	aux = lista->primeira;
	custo = custoTotal(lista, matriz, n);
	
	//imprime o caminho e custo
	while(aux!=NULL){
	 	printf("%d \n",aux->numero);
	 	aux = aux->prox;
	}

	printf("%.2f \n",custo);
	printf("*\n");

	//libera a lista
	liberarLista(lista);
}



