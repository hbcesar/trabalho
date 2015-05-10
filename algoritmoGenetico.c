#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include "TADalgoritmoGenetico.h"
#include "TADnn.h"
#include "TADfuncoesComuns.h"

void dividirVetor(int n, int* parte1, int* parte2){
	if ((n % 3 == 0) || (n%3==1)){
		(*parte1) = n/3;
		(*parte2) = n - (n/3);
	} else if (n % 3 == 2){
		(*parte1) = (n/3) + 1;
		(*parte2) = n - (n/3);
	}
}

void mutacao(int** filhos, int n){
	int p1=0, p2=0;
	int aux;

	//seta rand de acordo com o tempo 
	srand(time(NULL));
	//evita que o rand retorne numeros iguais para p1 e p2
	while( p1 == p2){
		p1 = rand() % n;
		p2 = rand() % n;
	}

	//faz mutacao no primeiro filho
	aux = filhos[0][p1];
	filhos[0][p1]=filhos[0][p2];
	filhos[0][p2]=aux;

	//faz mutacao no segundo filho
	aux = filhos[1][p1];
	filhos[1][p1]=filhos[1][p2];
	filhos[1][p2]=aux;
}

int** criaFilhos(int* vet1, int* vet2, int n){
	short unsigned int flag = 1; //flag auxiliar, usada para identificar se um numero ja existe no vetor filho ou nao
	int i, j, k;
	int parte1;
	int parte2;
	int* filho1 = (int*)malloc(n*sizeof(int));
	int* filho2 = (int*)malloc(n*sizeof(int));
	int** lista_filhos = (int**)malloc(2*sizeof(int*));


	dividirVetor(n, &parte1, &parte2);
	// printf("%d %d \n", parte1, parte2);

	// zera os vetores antes de começar, apenas por garantia
	for(i=0; i<n; i++){
		filho1[i] = filho2[i] = 0;
	}

	//copia o meio de vet1 para o primeiro filho, e o meio de vet2 para o segundo filho
	for(i=parte1; i<parte2; i++){
		filho1[i]=vet1[i];
		filho2[i]=vet2[i];
	}

	// copiados, faz-se o cruzamento
	// primeiro do vetor2 com filho 1
	for(i=0, k=0; i<n; i++){
		for(j=parte1; j<parte2; j++){
			if(vet2[i] == filho1[j]){
				flag = 0;
				break;
			}
		}
		if(k 	== parte1)
			k=parte2;
		if (flag){
			filho1[k]=vet2[i];
			k++;
		}
		flag = 1;
	}

	//entao, com o vetor1 e filho2
	for(i=0, k=0; i<n; i++){
		for(j=parte1; j<parte2; j++){
			if(vet1[i] == filho2[j]){
				flag = 0;
				break;
			}
		}
		if(k == parte1)
			k=parte2;
		if (flag){
			filho2[k]=vet1[i];
			k++;
		}
		flag = 1;
	}


	lista_filhos[0]=filho1;
	lista_filhos[1]=filho2;

	//antes de retornar, apaga os vetores pais
	free(vet1);
	free(vet2);

	return lista_filhos;
}

void algoritmoGenetico(float** matriz, int n){
	int i=0;
	int* vet1;
	int* vet2;
	int** caminhos;
	float valor1, valor2;
	float menor1, menor2;
	float menor1_aux, menor2_aux;

	menor1_aux = menor2_aux = FLT_MAX;

	//recebe o "melhor" caminho de NN
	vet1 = nearestNeighbor(1, n, matriz, NULL);
	vet2 = nearestNeighbor(n, n, matriz, NULL);

	//calcula o custo do caminho recebido por NN
	menor1 = custo(matriz, vet1, n);
	menor2 = custo(matriz, vet2, n);

	//faz a criação dos primeiros filhos e faz a mutacao dos mesmos
	caminhos = criaFilhos(vet1, vet2, n);
	mutacao(caminhos, n);

	//calcula o custo do primeiro filho gerado
	valor1 = custo(matriz, caminhos[0], n);
	valor2 = custo(matriz, caminhos[1], n);

	/*
	 * entao entra em loop até que:
	 * 1 - o numero de iterações exceda 100 ou
	 * 2 - pelo menos um filho encontrado tenha valor total do percurso menor
	 * do que encontrado pelo algoritmo NN
	 */
	while (i<99 && ((valor1 > menor1) || (valor1 > menor2) || (valor2 > menor1) || (valor2 > menor2))){
		
		//os dois ifs a seguir guardam o menor valor encontrado durante o loop
		if(valor1 < menor1_aux){
			menor1_aux = valor1;
			vet1 = caminhos[0];
		}

		if(valor2 < menor2_aux){
			menor2_aux = valor2;
			vet2 = caminhos[1];
		}

		//faz cruzamento dos filhos
		caminhos = criaFilhos(caminhos[0], caminhos[1], n);
		//mutacao
		mutacao(caminhos, n);
		//e entao calcula o custo de ambos
		valor1 = custo(matriz, caminhos[0], n);
		valor2 = custo(matriz, caminhos[1], n);

		i++; //atualiza variavel de parada
	}

	//imprime o caminho mais barato encontrado
	if(menor1_aux < menor2_aux)
		imprimirCaminho(vet1, menor1_aux, n);
	else imprimirCaminho(vet2, menor2_aux, n);

	//libera memória alocada pra galera toda
	// (vet1 e vet2 ja foram desalocados)
	free(caminhos[0]);
	free(caminhos[1]);
	free(caminhos);
}