#ifndef __TADNN_H_
#define __TADNN_H_
// Funcao que calcula o menor numero de um vetor
// Input: O vetor, seu tamanho e um ponteiro para o indice de uma posicao do vetor
// Output: O valor do menor numero
// Pré-condição: Vetor não é nulo
// Pós condição: Menor número do vetor é encontrado e retornado
float menor (float* vetor, int n, int* indice_menor);

//Funcao que copia uma matriz para outra
// Input: A matriz a ser copiada e o seu tamanho
// Output: Ponteiro para a matriz copiada
// Pré-condição: Matriz nao é nula e n é inteiro positivo
// Pós condição: Matriz é alocada e é identica à matriz original
float** copiarMatriz(int n, float** matriz)

// FUncao que varre a matriz procurando a cidade mais proxima a cada iteraçao
// Input: Numero da cidade, tamanho da matriz, a matriz de entrada e um ponteiro para um indice da matriz
// Output: Ponteiro para o vetor de caminhos
// Pré-condição:Matriz não é nula, n é inteiro positivo
// Pós condição: Vetor de caminhos é criado com a heuristica do vizinho mais proximo
int* nearestNeighbor(int primeira_cidade, int n, float** matriz, int* valor);

//Funcao que executa o NN para priemira e ultima cidade do caminho
// Input: Matriz e seu tamanho
// Output: Nenhum
// Pré-condição: Matriz não é nula e n eh inteiro valido
// Pós condição: NN é executado e imprime o caminho com seu respectivo custo
void executarNN(int n, float** matriz);

#endif
