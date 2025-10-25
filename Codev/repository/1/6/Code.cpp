#include <stdio.h>
#include <stdlib.h>

int Maior(int A[], int n) {
	/* insert your code here */
	long int maior = A[0];
	for (int i=0; i<n; i++)
	{
		if (A[i] > maior)
		{
			maior = A[i];
		}
	}
	return maior;
}

int main() {
	int n; 
	int * A;
	while (scanf("%d", &n)>0) {
		A = (int *) malloc(sizeof(int)*n);
		for (int i=0; i<n; i++) {
			scanf("%d", &A[i]);
		} 
		printf("%d\n", Maior(A, n));
		free(A);
	}
}
