#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct ListaLinear {
	int * E;
	int N;
} ListaLinear;

ListaLinear Intersecao(ListaLinear L1, ListaLinear L2) {
	/* insert your code here */
}

void Insere(ListaLinear &L, int e) {
	L.E[L.N] = e; L.N = L.N+1;
}

void Escreve(ListaLinear L) {
	std::sort(L.E,L.E+L.N);
	printf("["); for (int i=0; i<L.N; i++) printf("%d ", L.E[i]); printf("]\n");
}

ListaLinear C_Intersecao(ListaLinear L1, ListaLinear L2, int q=1) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	ListaLinear r;
	//for (int t=0; t<q; t++) {
	r = Intersecao(L1,L2);
	//}
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
	return r;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n1, max_n2; ListaLinear L1; ListaLinear L2; ListaLinear L;
	while (scanf("%d %d", &max_n1, &max_n2)>0) {
		if (max_n1!=-1) {
			/* lê n1, e1, e2, ..., en1, n2,  e1, e2, ..., en2 */
			L1.E = (int *) malloc(sizeof(int)*max_n1); L1.N = 0;
			for (int i=0; i<max_n1; i++) {
				int e; scanf("%d", &e);	Insere(L1,e);
			}
			L2.E = (int *) malloc(sizeof(int)*max_n2); L2.N = 0;
			for (int i=0; i<max_n2; i++) {
				int e; scanf("%d", &e);	Insere(L2,e);
			}
			L = C_Intersecao(L1,L2); Escreve(L);
			free(L1.E); free(L2.E); free(L.E);
		} else {
			/* automatic test */
			max_n1 = 9000; max_n2 = max_n1;
			L1.E = (int *) malloc(sizeof(int)*max_n1); L1.N = 0;
			L2.E = (int *) malloc(sizeof(int)*max_n2); L2.N = 0;
			for (int i=0; i<max_n1; i++) {
				Insere(L1,i*2); Insere(L2,i*3);
			}
			L = C_Intersecao(L1,L2); Escreve(L);
			free(L1.E); free(L2.E); free(L.E);
		}
	}
	return 0;
}