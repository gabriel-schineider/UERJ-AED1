#include <stdio.h>

void Inserir(int* L, int *N, int x)
{
	// assume-se L uma Lista Linear Sequencial Ordenada; também assume-se que o tamanho vigente é inferior à capacidade do vetor.
	// Complexidades... tempo: tetha(N), espaço: tetha(1)

	int i=0;
	while ((i < *N) && (L[i] < x))
	{
		i++;
	}
	for (int j=*N; j>i; j--)
	{
		L[j] = L[j-1];
	}
	L[i] = x; // Equivalente a "L[j] = x;" nesse caso
	*N += 1;
}


int main (void)
{
	int vetor[100] = {-149, -83, -14, -3, -2, -1, 1, 2, 4, 6, 8, 8, 8, 11, 12, 12, 12, 17, 21, 22, 27, 54};
	int n = 22;
	
	Inserir(vetor, &n, -200);
	Inserir(vetor, &n, 20);
	Inserir(vetor, &n, 200);
	Inserir(vetor, &n, 7);
	
	printf("{ ");
	for (int i=0; i<n; i++)
	{
		printf("%d ", vetor[i]);
	}
	printf("}\n\nN = %d\n", n);
	
	return 0;
}
