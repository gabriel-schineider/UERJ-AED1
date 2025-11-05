#include <stdio.h>
#include <stdlib.h>
#include "Bib1.h"
#include "Bib2.h"

/* Se achar útil empregar uma pilha ou fila em sua solução,
   utilize-a pela respectiva interface padrão 
   disponibilizada abaixo */ 
   
/* pilha */
void Constroi(Pilha &P);
void Destroi(Pilha &P);
void Empilha(Pilha &P, int x);
int Desempilha(Pilha &P);
int Topo(Pilha &P);
int Tamanho(Pilha &P);
/* pilha */

/* fila */
void Constroi(Fila &F);
void Destroi(Fila &F);
void Enfileira(Fila &F, int x);
int Desenfileira(Fila &F);
int Proximo(Fila &F);
int Tamanho(Fila &F);
/* fila */


void ManobrarVagoes(int n, int V[]) {
	/* insert your code here */
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; int * V; 
	while (scanf("%d", &n) > 0) {
		if (n != -1) {
			V = (int *) malloc(sizeof(int) * n);
			for (int i = 0; i < n; i++) {
				scanf("%d", &V[i]);
			}
		} else {
			/* automatic test */
			n = 1000;
			V = (int *) malloc(sizeof(int) * n);
			int M = n; int m = 1;
			for (int i = n-1; i >= 0; i = i-2) {
				V[i] = M; V[i-1] = m;
				M = M-1; m = m+1;
			}
		}
		ManobrarVagoes(n, V);
		free(V);
	}
	return 0;
}