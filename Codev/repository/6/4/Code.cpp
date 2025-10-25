#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "Bib1.h"

bool ProcuraSoma(int L[], int n, int k) {
	/* insert your code here */
}

void Insere(int L[], int &n, int e) {
	L[n] = e; n = n+1;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n; int * L; int n; int k;
	while (scanf("%d", &max_n)>0) {
		if (max_n!=-1) {
			L = (int *) malloc(sizeof(int)*max_n); n = 0;
			for (int i=0; i<max_n; i++) {
				int e; scanf("%d", &e);	Insere(L,n,e);
			}
			scanf("%d", &k);	
		} else {
			/* automatic test */
			max_n = 1000000;
			L = (int *) malloc(sizeof(int)*max_n); n = 0;
			for (int i=0; i<max_n; i++) {
				Insere(L,n,i); 
			}
			L[200000] = 2000000; k=2600000;
		}
		printf("%d\n", ProcuraSoma(L, n, k));
		free(L);
	}
	return 0;
}