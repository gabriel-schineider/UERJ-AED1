#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Esq;
	No * Dir;
} No;

int Maior(No * T) {
	/* insert your code here */
}

int C_Maior(No * T, int q=100000) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	for (int t=1; t<= q; t++) Maior(T);
	int r = Maior(T);
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
	return r;
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

void PreencheCheiaBusca(No * &T, int &i, int h) {
	if (h==0) {
		T = NULL;
	} else {
		T = (No *) malloc(sizeof(No));
		PreencheCheiaBusca(T->Esq, i, h-1);
		T->E = i; i += 1; 
		PreencheCheiaBusca(T->Dir, i, h-1);
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
			printf("%d\n", Maior(T));
			Destroi(T);
			n=0;
		} else {
			/* teste automático */
			int i = 1;
			PreencheCheiaBusca(T, i, 20);
			printf("%d\n", C_Maior(T));
			Destroi(T);
		}
	}
	free(e);
	return 0;
}