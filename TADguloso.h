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

void alocarLista();
Cidade* criarCidade(int n);
Cidade* inserirLista(Interface* lista, Cidade* novo, int posicao);
float calcularCusto(Cidade* a, Cidade* b, Cidade* c);
float custoTotal(Interface* lista);
void guloso(float** matriz, int n);
