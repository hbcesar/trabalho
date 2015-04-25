#include <stdio.h>
#include <stdlib.h>

int** criaFilhos(int* vet1, int* vet2, int n){
	short unsigned int flag = 1; //flag auxiliar, usada para identificar se um numero ja existe no vetor filho ou nao
	int i, j;
	int parte1 = (n/3) - 1; //o -1 serve apenas para adequar a leitura de vetores em C
	int parte2 = n - (n/3) - 1;
	int* filho1 = (int*)malloc(n*sizeof(int));
	int* filho2 = (int*)malloc(n*sizeof(int));
	int** lista_filhos = (int**)malloc(2*sizeof(int*));

	printf("%d %d \n", parte1, parte2);

	//copia o meio de vet1 para o primeiro filho, e o meio de vet2 para o segundo filho
	for(i=parte1; i<parte2; i++){
		filho1[i]=vet1[i];
		filho2[i]=vet2[i];
	}

	// copiados, vamos fazer o cruzamento hmmmmm safadinho atravez de um algoritmo
	// que pensa que sou tuas nega
	//primeiro do vetor2 com filho 1
	for(i=0; i<n; i++){
		for(j=parte1; j<parte2; j++){
			if(vet2[i] == filho1[j]){
				flag = 0;
				break;
			}
		}
		if (flag)
			filho1[i]=vet2[i];
		flag = 1;
	}

	//then, com o vetor1 e filho2
	for(i=0; i<n; i++){
		for(j=parte1; j<parte2; j++){
			if(vet1[i] == filho2[j]){
				flag = 0;
				break;
			}
		}
		if (flag)
			filho2[i]=vet1[i];
		flag = 1;
	}

	//imprime os filhos, por questao de testes
	for(i=0; i<n; i++){
		printf("%d ", filho1[i]);
	}

	printf("\n");

		for(i=0; i<n; i++){
		printf("%d ", filho2[i]);
	}

	printf("\n");


	lista_filhos[0]=filho1;
	lista_filhos[1]=filho2;

	return lista_filhos;
}