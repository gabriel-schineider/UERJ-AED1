#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E; int Q;
	No * Esq;
	No * Dir;
} No;

int QuantidadeMenorIgual(No * T, int a) {
	/* insert your code here */
}

void Destroi(No * &T) {
	if (T != NULL) {
		Destroi(T->Esq);
		Destroi(T->Dir);
		free(T);
		T = NULL;
	}
}

void Insere(No * &T, int x) {
	if (T == NULL) {
		T = (No *) malloc(sizeof(No));
		T->Esq = NULL; T->Dir = NULL; T->E = x; T->Q = 1; 
	} else if (T->E > x) {
		Insere(T->Esq, x); T->Q = T->Q + 1;
	} else { // T->E < x
		Insere(T->Dir, x); T->Q = T->Q + 1;
	}
}

void InsereBal(No * &T, int i, int j) {
	if (i <= j) {
		int m = (i+j)/2;
		Insere(T, m);
		InsereBal(T, i, m-1);
		InsereBal(T, m+1, j);
	}
}

int C_QuantidadeMenorIgual(No * T, int a, int q=100000) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	int r;
	for (int t=1; t<=q; t++) r = QuantidadeMenorIgual(T, a);
	r = QuantidadeMenorIgual(T, a);
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
	return r;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	No * T; int n; int x; int a;
	while (scanf("%d", &n)>0) {
		T = NULL;
		if (n > 0) {
			/* teste manual: */
			for (int i = 0; i<n; i++) {
				scanf("%d", &x);
				Insere(T, x);
			}
			scanf("%d", &a);
		} else {
			/* teste automático */
			InsereBal(T, 1, 500000);
			a = 358254;
		}
		printf("%d\n", C_QuantidadeMenorIgual(T, a)); 
		Destroi(T);
	}
	return 0;
}