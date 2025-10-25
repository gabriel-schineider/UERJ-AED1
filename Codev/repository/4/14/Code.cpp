#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct No {
	int E;
	No * Prox;
} No;

void Insere(No * &L, int e) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = L; L = novo; 
}

No * SemRepeticoes(No * L) {
	/* insert your code here */
}

void Escreve(No * L) {
	int n = 0;
	No * p = L;
	while (p != NULL) {
		n++; p = p->Prox;
	}
	int * Lv = (int *) malloc(sizeof(int)*n);
	p = L; int i = 0;
	while (p != NULL) {
		Lv[i] = p->E; i++; p = p->Prox;
	}
	std::sort(Lv,Lv+n);
	printf("["); for (int i=0; i<n; i++) printf("%d", Lv[i]); printf("]\n");
	free(Lv);
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
	int n; No * L = NULL; No * Lr;
	while (scanf("%d", &n)>0) {
		if (n>-1) {
			/* lê n, e1, e2, ..., en */
			for (int i=0; i<n; i++) {
				int e; scanf("%d", &e);	Insere(L,e); 
			}
			Lr = SemRepeticoes(L); Escreve(Lr); Destroi(Lr); Destroi(L);
		} else {
			/* automatic test */
			if (n==-1) {
				n = 1000;
				for (int i=0; i<n; i++) {
					Insere(L,(i%2==0 ? 2 : 3));
				}
				Lr = SemRepeticoes(L); Escreve(Lr); Destroi(Lr); Destroi(L);
			} else {
				n = 1000;
				for (int i=0; i<n; i++) {
					Insere(L,i);
				}
				Lr = SemRepeticoes(L); Escreve(Lr); Destroi(Lr); Destroi(L);
			}
		}
	}
	return 0;
}