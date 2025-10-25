#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct No {
	int E;
	No * Prox;
} No;

typedef struct ListaLinear {
	No * Inicio;
	int N;
} ListaLinear;

ListaLinear Diferenca(ListaLinear L1, ListaLinear L2) {
	/* insert your code here */
}

void Insere(ListaLinear &L, int e, No * &u) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = NULL; 
	if (u == NULL) {
		L.Inicio = novo; 
	} else {
		u->Prox = novo;
	}
	u = novo; L.N = L.N+1;
}

void Escreve(ListaLinear L) {
	int n = L.N;
	No * p = L.Inicio;
	int * Lv = (int *) malloc(sizeof(int)*n);
	int i = 0;
	while (p != NULL) {
		Lv[i] = p->E; i++; p = p->Prox;
	}
	std::sort(Lv,Lv+n);
	printf("["); for (int i=0; i<n; i++) printf("%d ", Lv[i]); printf("]\n");
	free(Lv);
}

void Destroi(ListaLinear L) {
	No * p, * pr; p = L.Inicio; 
	while (p != NULL) {
		pr = p; p = p->Prox; 
		free(pr);
	}
}

ListaLinear C_Diferenca(ListaLinear L1, ListaLinear L2, int q=1) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	ListaLinear r;
	//for (int t=0; t<q; t++) {
	r = Diferenca(L1,L2);
	//}
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
	return r;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n1, max_n2; ListaLinear L1; ListaLinear L2; ListaLinear L; No * u;
	while (scanf("%d %d", &max_n1, &max_n2)>0) {
		if (max_n1!=-1) {
			/* lê n1, e1, e2, ..., en1, n2,  e1, e2, ..., en2 */
			L1.Inicio = NULL; L1.N = 0; u = NULL;
			for (int i=0; i<max_n1; i++) {
				int e; scanf("%d", &e);	Insere(L1,e,u);
			}
			L2.Inicio = NULL; L2.N = 0; u = NULL;
			for (int i=0; i<max_n2; i++) {
				int e; scanf("%d", &e);	Insere(L2,e,u);
			}
			L = C_Diferenca(L1,L2); Escreve(L);
			Destroi(L1); Destroi(L2); Destroi(L); 
		} else {
			/* automatic test */
			max_n1 = 9000; max_n2 = max_n1;
			L1.Inicio = NULL; L1.N = 0; u = NULL;
			for (int i=0; i<max_n1; i++) {
				int e; Insere(L1,i*2,u);
			}
			L2.Inicio = NULL; L2.N = 0; u = NULL;
			for (int i=0; i<max_n2; i++) {
				int e; Insere(L2,i*3,u);
			}
			L = C_Diferenca(L1,L2); Escreve(L);
			Destroi(L1); Destroi(L2); Destroi(L); 
		}
	}
	return 0;
}