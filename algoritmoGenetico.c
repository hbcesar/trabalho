#include <stdio.h>
#include <stdlib.h>
#include "TADalgoritmoGenetico.h"
#include "TADnn.h"
#include "TADfuncoesComuns.h"

void algoritmoGenetico(float** matriz, int n){
	int i;
	int* vet1;
	int* vet2;
	int** caminhos;
	int valor1, valor2;

	vet1 = nearestNeighbor(1, n, matriz, NULL);
	vet2 = nearestNeighbor(n, n, matriz, NULL);

	caminhos = criaFilhos(vet1, vet2, n);

	// for(i=0; i < n; i++){
	// 	printf("%d ", vet1[i]);
	// }
	// printf("\n");
	// for(i=0; i < n; i++){
	// 	printf("%d ", vet2[i]);
	// }
	// printf("\n");
	// for(i=0; i < n; i++){
	// 	printf("%d ", caminhos[0][i]);
	// }
	// printf("\n");

	// for(i=0; i < n; i++){
	// 	printf("%d ", caminhos[1][i]);
	// }
	// printf("\n");
	valor1 = custo(matriz, caminhos[0], n);
	valor2 = custo(matriz, caminhos[1], n);

	imprimirCaminho(caminhos[0], valor1, n);
	imprimirCaminho(caminhos[1], valor2, n);

}

void dividirVetor(int n, int* parte1, int* parte2){
	if ((n % 3 == 0) || (n%3==1)){
		(*parte1) = n/3;
		(*parte2) = n - (n/3);
	} else if (n % 3 == 2){
		(*parte1) = (n/3) + 1;
		(*parte2) = n - (n/3);
	}
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

	// zera os vetores antes de começar prq C é uma bosta
	for(i=0; i<n; i++){
		filho1[i] = filho2[i] = 0;
	}

	//copia o meio de vet1 para o primeiro filho, e o meio de vet2 para o segundo filho
	for(i=parte1; i<parte2; i++){
		filho1[i]=vet1[i];
		filho2[i]=vet2[i];
	}

	// copiados, vamos fazer o cruzamento hmmmmm safadinho atravez de um algoritmo
	// que pensa que sou tuas nega
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

	//then, com o vetor1 e filho2
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

	return lista_filhos;
}