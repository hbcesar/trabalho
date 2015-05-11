#ifndef __TADFUNCOESCOMUNS_H_
#define __TADFUNCOESCOMUNS_H_
//Função que calcula o fatorial de um número
// Input: Um numero inteiro positivo
// Output: Fatorial do numero
// Pré-condição: Numero não e negativo
// Pós condição: Fatorial está correto
long int fatorial(int n);

// Funcao que calcula o custo de um caminho escrito como vetor
// Input:  A matriz, um vetor e o tamanho da matriz
// Output: O custo como um float
// Pré-condição:Matriz e vetores não são nulos
// Pós condição: Float é retornado corretamente
float custo(float** matriz, int* vetor, int n);

// Funcao que aloca um vetor
// Input: Tamanho do vetor
// Output: Ponteiro para o vetor alocado 
// Pré-condição: N é inteiro positivo
// Pós condição: Vetor é alocado corretamente
int* alocarVetor(int n);

// Funcao que aloca uma matriz
// Input: Tamanho da matriz
// Output:  Ponteiro para um vetor de vetores
// Pré-condição: N é um numero inteiro positivo
// Pós condição: Matriz é alocada corretamente
float** alocarMatriz(int n);

// Funcao que libera a memoria utilizada por uma matriz
// Input: O tamanho da matriz e a própria matriz
// Output:  Nenhum
// Pré-condição: Matrize não é nula
// Pós condição: Memória é desalocada
void liberarMatriz(int n, float** matriz);

// Funcão que imprime o caminho de um vetor 
// Input: Vetor de carminhos, custo total do caminho e tamanho do caminho
// Output: Nenhum
// Pré-condição: Vetor não é nulo
// Pós condição: Caminho e custo do caminho são impressos
void imprimirCaminho(int* caminho, float soma, int n);


#endif
