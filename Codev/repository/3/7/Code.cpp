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


bool FilasIdenticas(Fila &f1, Fila &f2) {
	/* insert your code here */
	bool iguais = true;
	
	if ( Tamanho(f1) != Tamanho(f2) )
	{
		iguais = false;
	}
	else
	{	
		while (Tamanho(f1) > 0)
		{
			if ( Desenfileira(f1) != Desenfileira(f2) )
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
	int n; Fila f1; Fila f2;
	while (scanf("%d", &n) > 0) {
		if (n != -1) {
			int e;
			Constroi(f1); Constroi(f2);
			for (int i = 0; i < n; i++) {
				scanf("%d", &e); Enfileira(f1, e);
			}
			scanf("%d", &n); 
			for (int i = 0; i < n; i++) {
				scanf("%d", &e); Enfileira(f2, e);
			}
		} else {
			/* automatic test */
			int e; n = 1000000;
			Constroi(f1); Constroi(f2);
			for (int i = 0; i < n; i++) {
				Enfileira(f1, i+1); Enfileira(f2, i+1);
			}
		}
		printf("%d\n", FilasIdenticas(f1, f2));
		Destroi(f1); Destroi(f2);
	}
	return 0;
}
