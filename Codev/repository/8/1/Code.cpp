#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "Bib1.h"

/* Interface padrão de fila de prioridade */
void Constroi(FilaPrioridade &F, int n);
int Tamanho(FilaPrioridade &F);
void Enfileira(FilaPrioridade &F, int x);
int Desenfileira(FilaPrioridade &F);
int Topo(FilaPrioridade &F);
void Destroi(FilaPrioridade &F);
/* Interface padrão de fila de prioridade */

void Maiores(int L[], int n, int k, int M[]) {
	/* insert your code here */
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int * L; int n; int k;
	while (scanf("%d", &n)>0) {
		if (n!=-1) {
			L = (int *) malloc(sizeof(int)*n); 
			for (int i=0; i<n; i++) {
				scanf("%d", &L[i]);
			}
			scanf("%d", &k);
		} else {
			/* automatic test */
			n = 2000000;
			L = (int *) malloc(sizeof(int)*n); 
			for (int i=0; i<n; i++) {
				L[i] = i;
			}
			k = 100;
		}
		int * M = (int *) malloc(sizeof(int)*k);
		Maiores(L, n, k, M);
		for (int i=0; i<k; i++) printf("%d ", M[i]);
		printf("\n");
		free(M); free(L); 
	}
	return 0;
}