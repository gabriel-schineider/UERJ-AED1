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

typedef struct Mediana {
	double med; //mediana
	int n; //número de elementos inseridos
	FilaPrioridade ante; //antecedes a mediana (maxheap)
	FilaPrioridade post; //posteriores a mediana (minheap)
} Mediana;

double ObterMediana(Mediana &C) {
	/* insert your code here */
}

void Insere(Mediana &C, int x) {
	/* insert your code here */
}

void Constroi(Mediana &C, int n) {
	Constroi(C.ante, n);
	Constroi(C.post, n);
	C.n = 0; C.med = 0;
}

void Destroi(Mediana &C) {
	Destroi(C.ante);
	Destroi(C.post);
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
				L[i] = i;
			}
		}
		Mediana C; 
		Constroi(C, n);
		for (int i=0; i<n; i++) {
			Insere(C, L[i]);
			printf("%.1f ", ObterMediana(C));
		}
		printf("\n");
		Destroi(C);
		free(L); 
	}
	return 0;
}