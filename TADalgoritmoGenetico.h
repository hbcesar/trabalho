#ifndef __TADALGORITMOGENETICO_H_
#define __TADALGORITMOGENETICO_H_
//Funcao que cria os filhos a partir de vetores pais
// Input: Dois ponteiros para vetores de cidades e o número de cidades
// Output: Ponteiro para um vetor de vetores que contém os filhos
// Pré-condição: Número de cidade não é nula e vetores dos pais não são nulos
// Pós condição: Vetores filhos estão alocados e já estão permutados
int** criaFilhos(int* vet1, int* vet2, int n);

// Principal função que calcula o melhor carminho a partir das iterações do algortimo genético
// Input:  A matriz de cidades e o tamanho da matriz
// Output: nenhum
// Pré-condição: Matriz não é nula e nao tem tamanho 0
// Pós condição: Melhor caminho das iterações é impresso
void algoritmoGenetico(float** matriz, int n);

// Funcao que realiza a mutação entre 2 vetores filhos
// Input: Os vetores filhos e o número de cidads
// Output: Nenhum 
// Pré-condição:Vetores filhos estão alocados e não são nulos
// Pós condição: Mutação entre vetores ocorre
void mutacao(int** filhos, int n);

#endif
