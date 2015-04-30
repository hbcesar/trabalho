all: METODOS
	./executavel 12 exato < teste12.txt
METODOS:
	gcc -c funcoesComuns.c
	gcc -c solucaoOtima.c
	gcc -c algoritmoGenetico.c
	gcc -c nn.c
	gcc -c main.c
	gcc funcoesComuns.o solucaoOtima.o algoritmoGenetico.o nn.o main.o -o executavel
	
