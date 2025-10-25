#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct No {
	int E;
	No * Prox;
} No;

void InsereEnc(No * &L, int e, No * &u) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = NULL; 
	if (u == NULL) {
		L = novo; 
	} else {
		u->Prox = novo;
	}
	u = novo; 
}

No * ProdutoPolinomioEscalar(No * P, int a) {
	/* insert your code here */
}

void Escreve(No * L) {
	No * p = L;
	printf("["); while (p != NULL) { printf("%d ", p->E); p = p->Prox; }; printf("]\n");
}

void Destroi(No * L) {
	No * p, * pr; p = L; 
	while (p != NULL) {
		pr = p; p = p->Prox; 
		free(pr);
	}
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; No * P; No * u; int e; No * R; int a;
	while (scanf("%d", &n)>0) {
		P = NULL; 
		if (n!=-1) {
			/* lê n, coeficientes de P, a */
			u = NULL;
			for (int i=0; i<=n; i++) {
				scanf("%d", &e); 
				InsereEnc(P,e,u); 
			}
			scanf("%d", &a); 
		} else {
			/* automatic test */
			n = 500000;
			u = NULL;
			for (int i=0; i<=n; i++) {
				InsereEnc(P,1,u); 
			}
			a = 2;
		}
		R = ProdutoPolinomioEscalar(P, a);
		Escreve(R); Destroi(R); Destroi(P); 
	}
	return 0;
}