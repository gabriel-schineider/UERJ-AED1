#include <stdio.h>

void Remover (int* lista, int* tamanho, int elemento) // O(n)
{
	int i=0; int j; int c=0;
	for (i; i<*tamanho; i++)
	{
		if (lista[i] == elemento)
		{
			c++;
		}
		else
		{
			if (lista[i] > elemento)
			{
				break;
			}
		}
	}
	for (j=i ; j<*tamanho; j++)
	{
		lista[j-c] = lista[j];
	}
	*tamanho -= c;
}


int main (void)
{
	int vetor[100] = {-149, -83, -14, -3, -2, -1, 1, 2, 4, 4, 6, 8, 8, 8, 11, 12, 12, 12, 17, 21, 22, 27, 54};
	int n = 23;
	
	Remover(vetor, &n, 4);
	
	for (int i=0; i<n; i++)
	{
		printf("%d ", vetor[i]);
	}
	printf("\n%d\n", n);
	
	return 0;
}
