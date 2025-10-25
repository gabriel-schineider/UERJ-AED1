#include <stdio.h>
#include <stdbool.h>

bool Buscar (int L[], int N, int x)
{
	// assume-se L uma Lista Linear Sequencial Não Ordenada
	// retorna o índice da primeira ocorrência de x em L ou -1 caso x não esteja em L
	// Complexidades... tempo: O(N), espaço: tetha(1)
	
	for (int i=0; i<N; i++)
	{
		if (L[i] == x)
		{
			return i;
		}
	}
	return -1;
}


int main (void)
{
	int lista[8] = {1, 2, 4, 623, 64, 2, 3, -23};
	printf("Buscar(-23) -> %b\n", Buscar(lista, 8, -23));
	printf("Buscar(440) -> %b\n", Buscar(lista, 8, 440));

	return 0;
}
