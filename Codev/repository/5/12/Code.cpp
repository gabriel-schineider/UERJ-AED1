#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Esq;
	No * Dir;
} No;

No * CriarArvoreAlturaMinima(int x[], int ini, int fim) {
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
		printf("(%d ", T->E);
		printf("("); Escrever(T->Esq); printf(")"); 
		printf("("); Escrever(T->Dir); printf("))"); 
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
			for (n=0; n<100000; n++) {
				e[n] = n+1;
			}
			e[n] = -1;
		}
		T = CriarArvoreAlturaMinima(e, 0, n-1);
		Escrever(T); printf("\n"); Destroi(T);
		n=0;
	}
	free(e);
	return 0;
}