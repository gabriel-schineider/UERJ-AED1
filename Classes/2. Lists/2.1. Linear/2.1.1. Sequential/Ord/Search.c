#include <stdio.h>
#include <stdbool.h>

bool Buscar (int* lista, int n, int x) // O(log n)
{
	int i=0; int j=n; int k;
	while (i <= j)
	{
		k = (i+j)/2;
		if (x == lista[k])
		{
			return true;
		}
		else
		{
			if (x > lista[k])
			{
				i = k + 1;
			}
			else
			{
				j = k - 1;
			}
		}
	}
	return false;
}


int main (void)
{
	int vetor[100] = {-149, -83, -14, -3, -2, -1, 1, 2, 4, 6, 8, 8, 8, 11, 12, 12, 12, 17, 21, 22, 27, 54};
	int n = 22;
	
	printf("%d \n", Buscar(vetor, n, 12));
	
		
	return 0;
}
