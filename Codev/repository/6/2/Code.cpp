#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "Bib1.h"


int BuscaEmLote(int L[], int B[], int n) {
	/* insert your code here */
}

void Insere(int L[], int &n, int e) {
	L[n] = e; n = n+1;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n; int * L, * B; int n;
	while (scanf("%d", &max_n)>0) {
		if (max_n!=-1) {
			L = (int *) malloc(sizeof(int)*max_n); 
			B = (int *) malloc(sizeof(int)*max_n);
			n = 0;
			for (int i=0; i<max_n; i++) {
				int e; scanf("%d", &e);	Insere(L,n,e);
			}
			n = 0;
			for (int i=0; i<max_n; i++) {
				int e; scanf("%d", &e);	Insere(B,n,e);
			}
		} else {
			/* automatic test */
			max_n = 1000000;
			L = (int *) malloc(sizeof(int)*max_n); 
			B = (int *) malloc(sizeof(int)*max_n);
			n = 0;
			for (int i=0; i<max_n; i++) {
				Insere(L,n,i); 
			}
			n = 0;
			for (int i=0; i<max_n; i++) {
				Insere(B,n,2*i); 
			}
		}
		printf("%d\n", BuscaEmLote(L, B, n));
		free(L); free(B);
	}
	return 0;
}