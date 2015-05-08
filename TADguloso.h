#ifndef __TADGULOSO_H_
#define __TADGULOSO_H_

struct cidade { 
	int numero; 
	struct cidade* prox; 
}; 

typedef struct cidade Cidade;

struct interface{
	Cidade* primeira;
	Cidade* ultima;
};

typedef struct interface Interface;

Interface* alocarLista();
Cidade* criarCidade(int n);
Cidade* inserirLista(Interface* lista, Cidade* novo, int posicao);
float calcularCusto(float** matriz, Cidade* a, Cidade* b, Cidade* c);
float custoTotal(Interface* lista, float** matriz);
void metodo_guloso(float** matriz, int n);
void liberarLista(Interface* lista);

#endif
