#include <stdlib.h>
#include <stdio.h>
#include "TADfuncoesComuns.h"

long int fatorial(int n){
	if(n==1)
		return 1;
	else
		return (n*fatorial(n-1));
}

float custo(int ** matriz, int* vetor, int n){
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