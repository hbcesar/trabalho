#ifndef __TADSOLUCAOOTIMA_H_
#define __TADSOLUCAOOTIMA_H_
//Funcao que imprime na tela o melhor caminho da solucao otima
// Input: Matriz de entrada, tamanho da matriz e numero de combinacoes
// Output: Nenhum
// Pré-condição: Matriz nao é nula e n e inteiro positivo valido
// Pós condição: Melhor caminho da solucao otima eh encontrado
void otima(int n, long int p, float** matriz);

// Funcao que calcula todas as permutacoes posiveis de um vetor de n posicos
// Input: Tamanho dos vetores, vetor de permutacoes, ponteiro para um vetor de permutacoes.
// Output:Nenhum
// Pré-condição: TOdas as entradas sao validas e estao alocadas 
// Pós condição: Vetor de permutacoes contem todas as permutacoes possiveis
void visit(int k, int n, int* valor, int** permutacoes);

// Adiciona uma permutacao ao vetor de permutacoes
// Input:  Ponteiro para uma permutacao, vetor de vetores de permutacoes, e tamanho dos vetores
// Output:  Nenhum
// Pré-condição:  Todas as entradas estao alocadas n é inteiro positivo
// Pós condição: Vetor de permutacao é adicionado ao vetor de vetores de permutacoes
void addItem(int* vetor, int** permutacoes, int n);

// Funcao que acha o menor caminho de todos as permutacoes 
// Input: A matriz, seu tamnho, vetor de vetores de permutacoes e numero de permutacoes
// Output:Nenhum
// Pré-condição: Entradas sao validas e alocadas e  n eh inteiro positivo 
// Pós condição: Menor caminho de todas as permutacoes é encontrada
void calcularOtima(float** matriz, int** permutacoes, int n, long int p);

// Funcao que imprime todas as combinacoes do vetor de vetores de permutacoes
// Input: O vetor de permutacoes, o tamanho do vetor e o numero de permutacoes
// Output: Nenhum
// Pré-condição:  N eh inteiro positivo e vetores estão alocados
// Pós condição: Combinacoes sao impressas
void imprimeCombinacoes(int** permutacoes, int n, long int p);

// Funcao que libera a memoria de todos os vetores alocados
// Input: Vetor de vetores de permutacoes, um vetor de permutacoes e numero de permutacoes
// Output: Nenhum
// Pré-condição: Vetores estoa alocados e nao sao nulos e permutacoes é maior que 0
// Pós condição: Vetores sao desalocados e memoria é desocupada
void liberarVetores(int** permutacoes, int* valor, long int p);

#endif
