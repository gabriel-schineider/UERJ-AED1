#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct No {
	int E;
	No * Prox;
} No;


bool InsereBuscaRemove(No * L, int x) {
	/* insert your code here */
}

void Insere(No * &L, int e, No * &u) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = NULL; 
	if (u == NULL) {
		L = novo; 
	} else {
		u->Prox = novo;
	}
	u = novo; 
}

void Escreve(No * L) {
	int n = 0;
	No * p = L->Prox;
	printf("["); 
	while (p->Prox != NULL) { printf("%d ", p->E); p = p->Prox; };
	printf("]\n");
}

void Destroi(No * &L) {
	No * p, * pr; p = L; 
	while (p != NULL) {
		pr = p; p = p->Prox; 
		free(pr);
	}
	L = NULL; 
}


int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; No * L; No * u; int x; int r;
	while (scanf("%d", &n)>0) {
		L = NULL; u = NULL;
		if (n!=-1) {
			/* lê e1, e2, ..., en, x */
			Insere(L,3000,u);
			for (int i=0; i<n; i++) {
				scanf("%d", &x); Insere(L,x,u); 
			}
			Insere(L,3000,u);
			scanf("%d", &x); 
			r = InsereBuscaRemove(L, x); 
			printf("%d ", r); Escreve(L); Destroi(L); 
		} else {
			/* automatic test */
			n = 500000;
			Insere(L,3000,u);
			for (int i=0; i<n; i++) {
				Insere(L,i,u); 
			}
			Insere(L,3000,u);
			r = InsereBuscaRemove(L, 300000); 
			printf("%d ", r); Escreve(L); Destroi(L); 
		}
	}
	return 0;
}