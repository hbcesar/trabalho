all: METODOS
	./executavel 10 exato < teste.txt
METODOS:
	gcc -c funcoesComuns.c
	gcc -c solucaoOtima.c
	gcc -c main.c
	gcc funcoesComuns.o solucaoOtima.o main.o -o executavel
	
