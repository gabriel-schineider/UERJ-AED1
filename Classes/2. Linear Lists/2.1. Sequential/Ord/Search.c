#include <stdio.h>
#include <stdbool.h>

int Buscar (int* L, int N, int x)
{
	// assume-se L uma Lista Linear Sequencial Ordenada
	// retorna o índice do elemento ou -1 caso não pertença a L
	// Complexidades... tempo: O(log N), espaço: tetha(1)

	int i = 0; int f = N-1; int m;
	while (i <= f)
	{
		m = (i+f)/2;
		if (L[m] == x)
		{
			return m;
		}
		else
		{
			if (L[m] < x)
			{
				i = m + 1;
			}
			else
			{
				f = m - 1;
			}
		}
	}
	return -1;
}


int main (void)
{
	int vetor[100] = {-149, -83, -14, -3, -2, -1, 1, 2, 4, 6, 8, 8, 8, 11, 12, 12, 12, 17, 21, 22, 27, 54};
	int n = 22;
	
	printf("Posição do elemento 12 em L: %d \n", Buscar(vetor, n, 12));
	printf("Posição do elemento 10 em L: %d \n", Buscar(vetor, n, 10));
	
		
	return 0;
}
