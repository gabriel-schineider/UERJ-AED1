#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct No {
	int E;
	No * Prox;
} No;


No * Concatenar(No * L1, No * L2) {
	/* insert your code here */
}

void Escreve(No * L) {
	int n = 0;
	No * p = L;
	printf("["); 
	while (p != NULL) { printf("%d ", p->E); p = p->Prox; };
	printf("]\n");
}

void Destroi(No * L) {
	No * p, * pr; p = L; 
	while (p != NULL) {
		pr = p; p = p->Prox; 
		free(pr);
	}
}


void Insere(No * &L, int e, No * &u) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = NULL;
	if (u == NULL) { L = novo; } else { u->Prox = novo; };
	u = novo;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n1, max_n2; No * L1; No * L2; No * u; No * L;
	while (scanf("%d %d", &max_n1, &max_n2)>0) {
		if (max_n1!=-1) {
			/* lê n1, e1, e2, ..., en1, n2,  e1, e2, ..., en2 */
			L1 = NULL; u = NULL;
			for (int i=0; i<max_n1; i++) {
				int e; scanf("%d", &e);	Insere(L1,e,u);
			}
			L2 = NULL; u = NULL;
			for (int i=0; i<max_n2; i++) {
				int e; scanf("%d", &e);	Insere(L2,e,u);
			}
			L = Concatenar(L1,L2); Escreve(L);
			free(L);
		} else {
			/* automatic test */
			max_n1 = max_n2 = 500000;
			L1 = NULL; u = NULL;
			for (int i=0; i<max_n1; i++) {
				int e; scanf("%d", &e);	Insere(L1,e,u);
			}
			L2 = NULL; u = NULL;
			for (int i=0; i<max_n2; i++) {
				int e; scanf("%d", &e);	Insere(L2,e,u);
			}
			L = Concatenar(L1,L2); Escreve(L);
			free(L);
		}
	}
	return 0;
}