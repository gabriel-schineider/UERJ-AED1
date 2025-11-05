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


int AvaliarExpressao(No * T) {
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

void Insere(No * &T, char e[], int &i) {
	if (e[i] == '.') {
		i++;
		T = NULL;
	} else  {
		T = (No *) malloc(sizeof(No));
		if (('0' <= e[i]) && (e[i] <= '9')) {
			T->E = (e[i]-'0'); T->op = '@';
		} else {
			T->op = e[i];
		}
		i++;
		Insere(T->Esq, e, i);
		Insere(T->Dir, e, i);
	}
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	char * e = (char *) malloc(sizeof(char) * 1000000); int i;
	No * T;
	while (scanf("%s", e)>0) {
		/* teste manual */
		i = 0;
		Insere(T,e,i); 
		printf("%d\n", AvaliarExpressao(T));
		Destroi(T);
	}
	free(e);
	return 0;
}