#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E; int Q;
	No * Esq;
	No * Dir;
} No;

void Insere(No * &T, int x) {
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

void Escrever(No * T) {
	if (T != NULL) {
		printf("(Q=%d,E=%d ", T->Q, T->E);
		printf("("); Escrever(T->Esq); printf(")"); 
		printf("("); Escrever(T->Dir); printf("))"); 
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

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	No * T; int n; int x;
	while (scanf("%d", &n)>0) {
		T = NULL;
		if (n > 0) {
			/* teste manual: */
			for (int i = 0; i<n; i++) {
				scanf("%d", &x);
				Insere(T, x);
			}
		} else {
			/* teste automático */
			InsereBal(T, 1, 50000);
			InsereBal(T, 1, 50000);
		}
		Escrever(T); printf("\n"); Destroi(T);
	}
	return 0;
}