#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADfuncoesComuns.h"
#include "TADguloso.h"

Cidade* insereCidade (float** matriz, int n){
	Cidade* novo = (Cidade*)malloc(sizeof(Cidade));
	novo->numero = n;
	novo->prox = NULL;
	return novo;

}

void lista_guloso (float** matriz, int n, Cidade* lista){
	int i;
	int custo_total = 0;
	int custo_local = 0;
	Cidade* listaaux;
	Cidade* aux;
	aux->prox = lista;
	lista = insereCidade (matriz,0); //insere primeira cidade da matriz na lista
	lista = insereCidade (matriz,n-1); // insere ultima cidade da matriz na lista

	listaaux = copia_lista(lista); // copia a lista
	custo_total = custo_guloso (matriz,n,listaaux); //calcula o custo total da lista

	for (i=1;i<n-1;i++){ //começa da segunda linha da matriz até a penultima
			for (aux->prox=lista;aux!=NULL;aux=aux->prox){ // aux será inserido na primeira posição
			aux->numero = i; 
			custo_local = custo_guloso (matriz,n,aux); // calcula o custo da lista 
			// ERRO AQUI EM CIMA: "AUX NAO VAI MAIS APONTAR PARA O INICIO DA LISTA, COMO TER O PONTEIRO PARA O INICIO DA LISTA NOVAMENTE?"
					if  (custo_local < custo_total){ // se custo for menor que o custo da outra lista, copia uma lista para a outra
					listaaux = copia_lista(lista);
					}
			aux->prox = lista->prox; // atualiza o ponteiro aux para percorrer a lista toda
			lista->prox = aux;
			}
	}
	Cidade* aux2;

	for (aux2=listaaux;aux2!=NULL;aux2=aux2->prox){
		printf("%d \n",aux2->numero);
	}
	printf("%d \n",custo_total);
	printf("*\n");

	
}

int custo_guloso (float** matriz, int n, Cidade* lista){
	int custo = 0;
	int i,j;
	Cidade* aux;
	Cidade* aux2;

			for (aux=lista,aux2=lista->prox;aux2->prox!=NULL;aux=aux2,aux2=aux2->prox){
				i=aux->numero;
				j=aux2->numero;
				custo = custo + matriz[i-1][j-1];

			}

return custo;
}

Cidade* copia_lista(Cidade* lista1){

     Cidade*  lista2 = NULL;
     Cidade* copia = NULL;

     //Percorre a lista
     while(lista1 != NULL) {

          // Aloca o novo nó para ser copiado
          Cidade *novo = (Cidade*)malloc (sizeof(Cidade));

          // Copia um nó para o nó destino
          novo->numero = lista1->numero;
          novo->prox = NULL;

          if (lista2 == NULL) {
                
                lista2 = novo;
                copia = novo;
          }
          else {
                copia->prox = novo;
                copia = novo;
          }

          lista1 = lista1->prox;
    }

    return lista2;
}


