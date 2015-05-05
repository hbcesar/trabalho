struct cidade { 
int numero; 
struct cidade* prox; 
}; 

typedef struct cidade Cidade;

int custo_guloso (float** matriz, int n, Cidade* lista);
void lista_guloso (float** matriz, int n, Cidade* lista);
Cidade* insereCidade (float** matriz, int n);
Cidade* copia_lista(Cidade* lista1);