#include <stdio.h>


void Inserir (int L[], int* N, int x)
{
	// assume-se L uma Lista Linear Sequencial Não Ordenada; também assume-se que o tamanho vigente é inferior à capacidade do vetor.
	// Complexidades... tempo: tetha(1), espaço: tetha(1)
	
	L[*N] = x;
	*N += 1;
}


int main (void)
{
	int lista[100] = {1, 2, 4, 623, 64, 2, 3, -23};
	int n = 8;
	
	Inserir(lista, &n, 12);
	Inserir(lista, &n, 8);
	Inserir(lista, &n, 1);
	
	printf("array:\n");
	for (int i=0; i<=n+8; i++) // Printando mais espaços apenas para mostrar que, ao declarar um vetor, seus elementos recebem 0 como valor até que outro os sejam atribuído
	{
		printf("L[%d]: %d\n", i, *(lista+i));
	}
	printf("...\n\nN = %d \n", n);
	
	return 0;
}
