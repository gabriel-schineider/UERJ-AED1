#include <stdio.h>
#include <stdlib.h>

void ConcatenaPrefixos(char A[], char B[], int n, int m, char C[]) {
	/* insert your code here */
	int i=0;
	for (i; i<n; i++)
	{
		C[i] = A[i];
	}
	for (int j=0; j<m; j++)
	{
		C[i+j] = B[j];
	}
}

int main() {
	int n,m; 
	char A[100]; char B[100]; char C[200];
	while (scanf("%d %d", &n, &m)>0) {
		scanf("%s", A);
		scanf("%s", B);
		ConcatenaPrefixos(A, B, n, m, C);
		for (int i=0; i<n+m; i++) {
			printf("%c", C[i]);
		}
		printf("\n");
	}
}
