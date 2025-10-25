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

void Destroi(No * L) {
	No * p, * pr; p = L; 
	while (p != NULL) {
		pr = p; p = p->Prox; 
		free(pr);
	}
}

No * SomaPolinomios(No * P, No * Q) {
	/* insert your code here */
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
				InsereEnc(P,e,u); 
			}
			u = NULL;
			for (int i=0; i<=n2; i++) {
				scanf("%d", &e); 
				InsereEnc(Q,e,u); 
			}
		} else {
			/* automatic test */
			n1 = 1000000; n2 = 1000000;
			u = NULL;
			InsereEnc(P,0,u); 
			for (int i=0; i<n1; i++) {
				InsereEnc(P,1,u); 
			}
			u = NULL;
			InsereEnc(Q,1,u); 
			for (int i=0; i<n2; i++) {
				InsereEnc(Q,-1,u); 
			}
		}
		R = SomaPolinomios(P, Q);
		Escreve(R); Destroi(R); Destroi(P); Destroi(Q);
	}
	return 0;
}