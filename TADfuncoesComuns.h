#ifndef __TADFUNCOESCOMUNS_H_
#define __TADFUNCOESCOMUNS_H_

long int fatorial(int n);
float custo(float** matriz, int* vetor, int n);
int* alocarVetor(int n);
float** alocarMatriz(int n);
void liberarMatriz(int n, float** matriz);
void imprimirCaminho(int* caminho, float soma, int n);


#endif