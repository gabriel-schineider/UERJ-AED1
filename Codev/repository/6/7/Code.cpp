#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>


int ParesForaOrdem(int L[], int n) {
	/* insert your code here */
}

void Insere(int L[], int &n, int e) {
	L[n] = e; n = n+1;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n; int * L; int n; 
	while (scanf("%d", &max_n)>0) {
		if (max_n!=-1) {
			L = (int *) malloc(sizeof(int)*max_n); n = 0;
			for (int i=0; i<max_n; i++) {
				int e; scanf("%d", &e);	Insere(L,n,e);
			}
		} else {
			/* automatic test */
			max_n = 50000;
			L = (int *) malloc(sizeof(int)*max_n); 
			n = 0;
			for (int i=max_n; i>0; i--) {
				Insere(L,n,i); 
			}
		}
		printf("%d\n", ParesForaOrdem(L, n));
		free(L); 
	}
	return 0;
}