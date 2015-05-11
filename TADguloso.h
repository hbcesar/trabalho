#ifndef __TADGULOSO_H_
#define __TADGULOSO_H_
//Estrutura cidae que contém o número da mesma e um ponteiro para a proxima cidade
struct cidade { 
	int numero; 
	struct cidade* prox; 
}; 

typedef struct cidade Cidade;

//Lista de cidades com ponteiro para a primeira e a ultima cidade da lista (sentinela)
struct interface{
	Cidade* primeira;
	Cidade* ultima;
};

typedef struct interface Interface;

// Funcao que aloca a lista de cidades
// Input: Nenhum
// Output: Ponteiro para estrutura interface
// Pré-condição: Nenhuma
// Pós condição: Sentinela da lista é alocada
Interface* alocarLista();

// FUncao que aloca uma estrutura cidade
// Input: Número da cidade
// Output: Ponteiro para estrutura cidade
// Pré-condição: Número da cidade é um inteiro positivo
// Pós condição: Estrutura cidade é alocada
Cidade* criarCidade(int n);

//FUncao que isnere uma cidade na lista de cidades
// Input: Ponteiro da lista de cidade, estrutura cidade a ser inserida e posicao
// Output: Estrutura cidade
// Pré-condição: Lista, cidade a ser inserida e posição são válidas
// Pós condição: CIdade é inserida corretamente na lista
Cidade* inserirLista(Interface* lista, Cidade* novo, int posicao);

//Funcao que calcula o custo de perocrrer 3 cidades
// Input: A matriz e as três cidades a serem calculados os custos
// Output: Custo em ponto flutuante
// Pré-condição: Matriz e cidade não sao nulas
// Pós condição: CUsto é calculado e está correto
float calcularCusto(float** matriz, Cidade* a, Cidade* b, Cidade* c);

// Funcao que percorre uma lista toda calcula o custo
// Input: A lista de cidades, a matriz e o tamanho da matriz
// Output: Custo total em ponto flutuante
// Pré-condição: Lista, matriz e n são inteiros positivos válidos
// Pós condição: Custo total é calculado corretamente
float custoTotal(Interface* lista, float** matriz, int n);

// Funcao que vai calculando todos os custos possíveis para achar melhor posicao a ser inserida na lista
// Input:  Matriz e tamanho da matriz
// Output: Nenhum
// Pré-condição: Matriz e n não são nulos
// Pós condição: Lista é está com o método guloso realizado corretamente
void metodo_guloso(float** matriz, int n);

// FUncao que desaloca estrutura lista
// Input: A lista a ser desalocada
// Output:  Nenhum
// Pré-condição: Existe algo alocado na lista
// Pós condição: Memória da lista é liberada
void liberarLista(Interface* lista);

#endif
