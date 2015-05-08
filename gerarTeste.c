#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200

int main(int argc, char** argv){
	int n = atoi(argv[1]), i, j;
	srand(time(NULL));
	for (i = 0; i < n; ++i){
		for (j = 0; j < n; ++j)
			if(i == j)
				printf("%d ", 9999999);
			else
				printf("%d ", 1 + rand()%MAX);
		printf("\n");
	}
}



	



