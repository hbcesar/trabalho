#ifndef __TADALGORITMOGENETICO_H_
#define __TADALGORITMOGENETICO_H_

int** criaFilhos(int* vet1, int* vet2, int n);
void algoritmoGenetico(float** matriz, int n);
void mutacao(int** filhos, int n);

#endif