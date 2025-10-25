#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct No {
	int E;
	No * Prox;
} No;

void InsereFinalEnc(No * &L, int e, No * &u) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = NULL; 
	if (u == NULL) {
		L = novo; 
	} else {
		u->Prox = novo;
	}
	u = novo; 
}

void InsereInicioEnc(No * &L, int e) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = L; L = novo; 
}

void Destroi(No * L) {
	No * p, * pr; p = L; 
	while (p != NULL) {
		pr = p; p = p->Prox; 
		free(pr);
	}
}


No * ProdutoPolinomios(No * P, No * Q) {
	//codev
	No * R = NULL; No * uR; 
	No * T; No * uT; 
	No * p; No * q; 

	p = P; 
	
	R = NULL; uR = NULL; InsereFinalEnc(R, 0, uR);
	int zeros = 0;
	while (p != NULL) {
		No * T = ProdutoPolinomioEscalar(Q, p->E);
		for (int i=1; i<=zeros; i++) {
			InsereInicioEnc(T, 0);
		}
		No * Rtemp = SomaPolinomios(R, T); Destroi(T); Destroi(R);
		R = Rtemp;
		zeros = zeros+1;
		p = p->Prox;
	}
	return R;
	//codev
}

void Escreve(No * L) {
	No * p = L;
	printf("["); while (p != NULL) { printf("%d ", p->E); p = p->Prox; }; printf("]\n");
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n1, n2; No * P; No * Q; No * u; int e; No * R;
	while (scanf("%d %d", &n1, &n2)>0) {
		P = NULL; Q = NULL;
		if (n1!=-1) {
			/* lê coeficientes de P e Q */
			u = NULL;
			for (int i=0; i<=n1; i++) {
				scanf("%d", &e); 
				InsereFinalEnc(P,e,u); 
			}
			u = NULL;
			for (int i=0; i<=n2; i++) {
				scanf("%d", &e); 
				InsereFinalEnc(Q,e,u); 
			}
		} else {
			/* automatic test */
			n1 = 1000; n2 = 1000;
			u = NULL;
			for (int i=0; i<=n1; i++) {
				InsereFinalEnc(P,1,u); 
			}
			u = NULL;
			for (int i=0; i<=n2; i++) {
				InsereFinalEnc(Q,1,u); 
			}
		}
		R = ProdutoPolinomios(P, Q);
		Escreve(R); Destroi(R); Destroi(P); Destroi(Q);
	}
	return 0;
}