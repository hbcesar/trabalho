struct lista_permutacoes{
	int* permutacoes;
	struct lista_permutacoes* prox;
};

typedef struct lista_permutacoes Lista_Permutacoes;

struct interface_lista{
	Lista_Permutacoes* primeiro;
	Lista_Permutacoes* ultimo;
};

typedef struct interface_lista Interface_Lista;


void otima(int n, long int p, float** matriz);
void visit(int k, int n, int* valor, Interface_Lista* il);
void addItem(int* vetor, Interface_Lista* il, int n);
void calcularOtima(float** matriz, int** permutacoes, int n, long int p);
void imprimeCombinacoes(int** permutacoes, int n, long int p);
void liberarVetores(int** permutacoes, int* valor, long int p);
Interface_Lista* alocarInterface(void);