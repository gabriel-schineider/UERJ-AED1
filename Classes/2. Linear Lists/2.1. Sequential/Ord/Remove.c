#include <stdio.h>

void Remover (int* L, int* N, int x)
{
	// assume-se L uma Lista Linear Sequencial Ordenada
	// Complexidades... tempo: tetha(N), espaço: tetha(1)

	int i = 0; int c = 0;

	while ( (i < *N) && (L[i] <= x) )
	{
		if (L[i] == x)
		{
			c++;
		}
		i++;
	}
	while (i < *N)
	{
		L[i - c] = L[i];
		i++;
	}
	*N -= c;
}


int main (void)
{
	int vetor[100] = {-149, -83, -14, -3, -2, -1, 1, 2, 4, 4, 6, 8, 8, 8, 11, 12, 12, 12, 17, 21, 22, 27, 54};
	int n = 23;
	int exit = 1;

	while (exit)
	{
		puts("\nLISTA ATUAL:");
		printf("{ ");
		for (int i=0; i<n; i++)
		{
			printf("%d ", vetor[i]);
		}
		printf("}\n\nN = %d\n\n", n);
		
		int x;
		printf("Insira o elemento que desejas remover: ");
		scanf("%d", &x);
		Remover(vetor, &n, x);
		
		printf("----------");
		puts("\nNOVA LISTA:");
		printf("{ ");
		for (int i=0; i<n; i++)
		{
			printf("%d ", vetor[i]);
		}
		printf("}\n\nN = %d\n", n);

		printf("\nDigite (1) para continuar removendo ou (0) para parar: ");
		scanf("%d", &exit);
		printf("----------");
	}	
	return 0;
}
