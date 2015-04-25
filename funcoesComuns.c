#include <stdlib.h>
#include <stdio.h>
#include "TADfuncoesComuns.h"

long int fatorial(int n){
	if(n==1)
		return 1;
	else
		return (n*fatorial(n-1));
}

