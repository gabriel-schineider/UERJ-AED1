#include <stdio.h>

int nFa (int n)
{
	// assume-se n >= 0
	// retorna n!
	
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return nFa(n-1) * n;
	}
}

int main (void)
{
// Aplicação da Função Recursiva Fatorial (nFa)
	int N = 11;
	for (int i=0; i<N; i++)
	{
		printf("%d! = %d \n", i, nFa(i));
	}
	
	return 0;
}