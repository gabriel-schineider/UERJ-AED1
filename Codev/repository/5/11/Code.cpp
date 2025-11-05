#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Esq;
	No * Dir;
} No;


bool EhArvoreBusca(No * T) {
	/* insert your code here */
}

void Insere(No * &T, int e[], int &i) {
	if (e[i] == 0) {
		i++;
		T = NULL;
	} else  {
		T = (No *) malloc(sizeof(No));
		T->E = e[i]; i++;
		Insere(T->Esq, e, i);
		Insere(T->Dir, e, i);
	}
}

void Destroi(No * &T) {
	if (T != NULL) {
		Destroi(T->Esq);
		Destroi(T->Dir);
		free(T);
		T = NULL;
	}
}

void InsereBal(No * &T, int i, int j) {
	if (i <= j) {
		T = (No *) malloc(sizeof(No));
		int m = (i+j)/2;
		T->E = m;
		if (m == 900000) T->E = 1;
		InsereBal(T->Esq, i, m-1);
		InsereBal(T->Dir, m+1, j);
	} else {
		T = NULL;
	}
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	No * T = NULL; 
	int * e = (int *) malloc(sizeof(int) * 1000000); int n=0;
	while (scanf("%d", &e[n])>0) {
		if (e[n] > -1) {
			/* teste manual: visita preordem de T (0 para nulo) */
			while (e[n] != -1) {
				n++;
				scanf("%d", &e[n]);
			}
			int i=0;
			Insere(T,e,i);
		} else {
			/* teste automático */
			InsereBal(T, 1, 900000);
		}
		printf("%d\n", EhArvoreBusca(T));
		Destroi(T);
		n=0;
	}
	free(e);
	return 0;
}