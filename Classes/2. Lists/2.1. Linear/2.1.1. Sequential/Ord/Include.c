#include <stdio.h>

void Inserir(int* lista, int *n, int x) // O(n)
{
	int i=0;
	while ((i < *n) && (x >= lista[i]))
	{
		i++;
	}
	for (int j=*n; j>i; j--)
	{
		lista[j] = lista[j-1];
	}
	lista[i] = x;
	*n += 1;
}


int main (void)
{
	int vetor[100] = {-149, -83, -14, -3, -2, -1, 1, 2, 4, 6, 8, 8, 8, 11, 12, 12, 12, 17, 21, 22, 27, 54};
	int n = 22;
	
	Inserir(vetor, &n, -200);
	Inserir(vetor, &n, 20);
	Inserir(vetor, &n, 200);
	
	for (int i=0; i<n; i++)
	{
		printf("%d ", vetor[i]);
	}
	
	return 0;
}
