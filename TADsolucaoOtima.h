void otima(int n, long int p, float** matriz);
void visit(int k, int n, int* valor, int** permutacoes);
void addItem(int* vetor, int** permutacoes, int n);
void calcularOtima(float** matriz, int** permutacoes, int n, long int p);
void imprimeCombinacoes(int** permutacoes, int n, long int p);
void liberarVetores(int** permutacoes, int* valor, long int p);