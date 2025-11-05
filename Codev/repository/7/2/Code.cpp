#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

bool SaoAnagramas(char A[], char B[], int n) {
	/* insert your code here */
}

void Insere(char L[], int &n, char e) {
	L[n] = e; n = n+1;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n; char * A; char * B; int n;
	while (scanf("%d", &max_n)>0) {
		if (max_n!=-1) {
			A = (char *) malloc(sizeof(char)*(max_n+1)); 
			B = (char *) malloc(sizeof(char)*(max_n+1)); 
			n = max_n;
			scanf("%s", A); scanf("%s", B);
		} else {
			/* automatic test */
			max_n = 1000000;
			A = (char *) malloc(sizeof(char)*(max_n+1)); 
			B = (char *) malloc(sizeof(char)*(max_n+1)); 
			n = max_n;
			int T = 'z'-'a'+1;
			for (int i=max_n-1; i>=0; i--) {
				A[i] = 'a' + (i%T); 
			}
			for (int i=0; i < max_n; i++) {
				B[i] = 'a' + (i%T); 
			}
		}
		printf("%d\n", SaoAnagramas(A, B, n));
		free(A); free(B); 
	}
	return 0;
}