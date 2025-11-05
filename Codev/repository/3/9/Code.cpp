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


int SomaSequenciaOperacoes(int S[], int n) {
	/* insert your code here */
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; int * S; 
	while (scanf("%d", &n) > 0) {
		if (n != -1) {
			S = (int *) malloc(sizeof(int)*n);
			for (int i = 0; i < n; i++) {
				scanf("%d", &S[i]);
			}
		} else {
			/* automatic test */
			n = 1000000;
			S = (int *) malloc(sizeof(int)*n);
			for (int i = 0; i < n/2; i++) {
				S[i] = 1; S[n/2+i] = 0;
			}
		}
		printf("%d\n", SomaSequenciaOperacoes(S, n));
		free(S);
	}
	return 0;
}