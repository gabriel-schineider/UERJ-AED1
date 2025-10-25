#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "Bib1.h"


int QuantidadeIntervalo(int L[], int n, int a, int b) {
	/* insert your code here */
}

void Insere(int L[], int &n, int e) {
	L[n] = e; n = n+1;
}

int C_QuantidadeIntervalo(int L[], int n, int a, int b, int q=100000) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	int r;
	for (int t=1; t<=q; t++) r = QuantidadeIntervalo(L, n, a, b); 
	r = QuantidadeIntervalo(L, n, a, b);
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
	return r;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n; int * L; int n; int a, b;
	while (scanf("%d", &max_n)>0) {
		if (max_n!=-1) {
			L = (int *) malloc(sizeof(int)*max_n); n = 0;
			for (int i=0; i<max_n; i++) {
				int e; scanf("%d", &e);	Insere(L,n,e);
			}
			scanf("%d %d", &a, &b);	
		} else {
			/* automatic test */
			max_n = 1000000;
			L = (int *) malloc(sizeof(int)*max_n); 
			n = 0;
			for (int i=0; i<max_n; i++) {
				Insere(L,n,3*i); 
			}
			a = 3*200000; b = 3*900000;
		}
		printf("%d\n", C_QuantidadeIntervalo(L, n, a, b));
		free(L); 
	}
	return 0;
}