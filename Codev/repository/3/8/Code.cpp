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


bool PilhasIdenticas(Pilha &p1, Pilha &p2) {
	/* insert your code here */
	
	bool iguais = true;
	
	if ( Tamanho(p1) != Tamanho(p2) )
	{
		iguais = false;
	}
	else
	{
		while ( Tamanho(p1) > 0 )
		{
			if ( Desempilha(p1) != Desempilha(p2) )
			{
				iguais = false;
				break;
			}
		}
	}
	
	return iguais;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; Pilha p1; Pilha p2;
	while (scanf("%d", &n) > 0) {
		if (n != -1) {
			int e;
			Constroi(p1); Constroi(p2);
			for (int i = 0; i < n; i++) {
				scanf("%d", &e); Empilha(p1, e);
			}
			scanf("%d", &n); 
			for (int i = 0; i < n; i++) {
				scanf("%d", &e); Empilha(p2, e);
			}
		} else {
			/* automatic test */
			n = 1000000;
			Constroi(p1); Constroi(p2);
			for (int i = 0; i < n; i++) {
				Empilha(p1, i+1); Empilha(p2, i+1);
			}
		}
		printf("%d\n", PilhasIdenticas(p1, p2));
		Destroi(p1); Destroi(p2);
	}
	return 0;
}
