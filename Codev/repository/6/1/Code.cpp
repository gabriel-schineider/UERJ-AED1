#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "Bib1.h"

int Distintos(int L[], int N) {
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
			/* lê n, e1, e2, ..., en */
			L = (int *) malloc(sizeof(int)*max_n); n = 0;
			for (int i=0; i<max_n; i++) {
				int e; scanf("%d", &e);	Insere(L,n,e);
			}
		} else {
			/* automatic test */
			max_n = 1000000;
			L = (int *) malloc(sizeof(int)*max_n); n = 0;
			for (int i=0; i<max_n; i++) {
				Insere(L,n,i%997);
			}
		}
		printf("%d\n", Distintos(L, n));
		free(L);
	}
	return 0;
}