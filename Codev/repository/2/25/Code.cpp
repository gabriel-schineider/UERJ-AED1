#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct No {
	int E;
	No * Prox;
} No;

long long int AvaliaPolinomio(No * P, int x) {
	/* insert your code here */
}

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

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; No * P; No * u; int e; int x;
	while (scanf("%d", &n)>0) {
		P = NULL; u = NULL;
		if (n!=-1) {
			/* lê a_n, a_(n-1), ..., a_0, x */
			for (int i=0; i<=n; i++) {
				scanf("%d", &e); 
				InsereEnc(P,e,u); 
			}
			scanf("%d", &x); 
		} else {
			/* automatic test */
			n = 10000000;
			for (int i=0; i<=n; i++) {
				InsereEnc(P,1,u); 
			}
			x = 1;
		}
		printf("%lld\n", AvaliaPolinomio(P, x));
		Destroi(P);
	}
	return 0;
}