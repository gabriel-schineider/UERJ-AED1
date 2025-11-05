#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
	char op; // '+' ou '-' ou '*' ou '/' ou '@'
	         // se op='@', então indica que o nó representa o número E
	int E;
	No * Esq;
	No * Dir;
} No;


No * ExpressaoParaArvore(char C[], int ini, int fim) {
	//converter a expressão parentizada C[ini..fim]
	/* insert your code here */
}

void Escrever(No * T) {
	if (T != NULL) {
		Escrever(T->Esq); Escrever(T->Dir);
		if (T->op != '@') {
			printf("%c ", T->op);
		} else {
			printf("%d ", T->E);
		}
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

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	char * e = (char *) malloc(sizeof(char) * 1000000); 
	No * T;
	while (scanf("%s", e)>0) {
		/* teste manual */
		T = ExpressaoParaArvore(e, 0, strlen(e)-1);
		Escrever(T); printf("\n");
		Destroi(T);
	}
	free(e);
	return 0;
}