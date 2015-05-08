#ifndef __TADNN_H_
#define __TADNN_H_

float menor (float* vetor, int n, int* indice_menor);
float coluna (float numero, int n, float** matriz);
int* nearestNeighbor(int primeira_cidade, int n, float** matriz, int* valor);

#endif