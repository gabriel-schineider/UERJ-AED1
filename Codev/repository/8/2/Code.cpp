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

void Ordenar(int L[], int n) {
	// esse método de ordenação é chamado de HeapSort
	/* insert your code here */
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int * L; int n; 
	while (scanf("%d", &n)>0) {
		if (n!=-1) {
			L = (int *) malloc(sizeof(int)*n); 
			for (int i=0; i<n; i++) {
				scanf("%d", &L[i]);
			}
		} else {
			/* automatic test */
			n = 100000;
			L = (int *) malloc(sizeof(int)*n); 
			for (int i=0; i<n; i++) {
				L[i] = n-i;
			}
		}
		Ordenar(L, n);
		for (int i=0; i<n; i++) printf("%d ", L[i]);
		printf("\n");
		free(L); 
	}
	return 0;
}