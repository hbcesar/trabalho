all: METODOS
	time ./executavel 500 genetico < teste500.txt

METODOS:
	gcc -c funcoesComuns.c
	gcc -c solucaoOtima.c
	gcc -c nn.c
	gcc -c guloso.c
	gcc -c algoritmoGenetico.c
	gcc -c main.c
	gcc funcoesComuns.o solucaoOtima.o algoritmoGenetico.o nn.o guloso.o main.o -o executavel

