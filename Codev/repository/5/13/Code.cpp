#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Esq;
	No * Dir;
} No;


void Ordenar(int A[], int N) {
	/* insert your code here */
}


void InsereBal(int e[], int &i, int ini, int fim) {
	if (ini <= fim) {
		int m = (ini+fim)/2;
		e[i] = m; i++; 
		InsereBal(e, i, ini, m-1);
		InsereBal(e, i, m+1, fim);
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
		} else {
			/* teste automático */
			n = 0;
			InsereBal(e, n, 1, 60000);
			e[n] = -1;
		}
		Ordenar(e, n);
		for (int i=0; i<n; i++) printf("%d ", e[i]); printf("\n");
		n=0;
	}
	free(e);
	return 0;
}