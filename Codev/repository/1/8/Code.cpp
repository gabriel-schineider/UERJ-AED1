#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PermutacaoCircular(char A[], int n, int k) {
	/* insert your code here */
	char currentChar, holdingChar;
	int currentIndex, cycleIndex;
	
	currentChar = A[0];
	currentIndex = 0; cycleIndex = 0;
	
	int position;
	for (int i=0; i < n; i++)
	{
		position = (currentIndex + k) % n;
		holdingChar = A[position];
		A[position] = currentChar;
		currentChar = holdingChar;
		currentIndex = position;
		
		if (currentIndex == cycleIndex)
		{
			cycleIndex++;
			currentIndex = cycleIndex;
			currentChar = A[currentIndex];
		}
	}
}

int main() {
	int n,k; 
	char * A; 
	while (scanf("%d %d", &n, &k)>0) {
		A = (char *) malloc(sizeof(char)*(n+600000));
		scanf("%s", A);
		PermutacaoCircular(A, n, k);
		printf("%s\n", A);
		free(A);
	}
}
