#ifndef __TADFUNCOESCOMUNS_H_
#define __TADFUNCOESCOMUNS_H_
//
// Input: 
// Output: 
// Pré-condição: 
// Pós condição:
long int fatorial(int n);

//
// Input: 
// Output: 
// Pré-condição: 
// Pós condição:
float custo(float** matriz, int* vetor, int n);

//
// Input: 
// Output: 
// Pré-condição: 
// Pós condição:
int* alocarVetor(int n);

//
// Input: 
// Output: 
// Pré-condição: 
// Pós condição:
float** alocarMatriz(int n);

//
// Input: 
// Output: 
// Pré-condição: 
// Pós condição:
void liberarMatriz(int n, float** matriz);

//
// Input: 
// Output: 
// Pré-condição: 
// Pós condição:
void imprimirCaminho(int* caminho, float soma, int n);


#endif
