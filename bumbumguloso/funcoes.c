// while(aux2->prox != NULL){
// 	novo->prox = aux2;
// 	aux->prox = novo;
// 	//calcula custo e guarda i
// 	aux->prox = novo->prox;
// 	aux=aux2;
// 	aux2 = aux2->prox;
// 	novo->prox = NULL;
// }

while(aux2->prox != NULL){
	custo = calcularCusto(aux, novo, aux2);
	aux = aux2;
	aux2 = aux2->prox;
	if(custo < menor){
		i++;
		menor = custo;
	}
}

inserirLista(novo, i)

float calcularCusto(Cidade* a, Cidade* b, Cidade* c){
	int i=0, j=0;
	float custo;

	i=a->numero;
	j=b->numero;
	custo = matriz[i-1][j-1];

	i=b->numero;
	j=c->numero;
	custo = custo + matriz[i-1][j-1];

	return custo;
}

Cidade* inserirLista(Cidade* lista, Cidade* novo, int posicao){
	Cidade* aux = lista;
	int i;

	for(i=0; i<posicao; i++){
		aux = aux->prox;
	}

	novo->prox = aux->prox;
	aux->prox = novo;

	return lista;
}
