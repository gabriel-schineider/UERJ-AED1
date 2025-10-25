#include <stdio.h>
#include <stdbool.h>

void Remover (int L[], int* N, int x)
{
	// assume-se L uma Lista Linear Sequencial Não Ordenada
	// Complexidades... tempo: tetha(N), espaço: tetha(1)
	
	int i=0;
	while (i < *N)
	{
		if (L[i] == x)
		{
			L[i] = L[*N-1];
			*N -= 1;
		}
		else
		{
			i++;
		}
	}
}


int main (void)
{
	int lista[100] = {1, 2, 4, 623, 64, 2, 3, -23};
	int n = 8;
	Remover(lista, &n, 2);
	
	printf("Lista:\n");
	for (int i=0; i<n; i++)
	{
		printf("L[%d] = %d \n", i, *(lista+i));
	}
	printf("\nN = %d \n", n);
	
	return 0;
}
