#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

int MaiorDiferenca(int L[], int n) {
	/* insert your code here */
}

void Insere(int L[], int &n, int e) {
	L[n] = e; n = n+1;
}

int C_MaiorDiferenca(int L[], int n, int q=100000) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	int r;
	for (int t=1; t<=q; t++) r = MaiorDiferenca(L, n); 
	r = MaiorDiferenca(L, n);
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
	return r;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n; int * L; int n; 
	while (scanf("%d", &max_n)>0) {
		if (max_n!=-1) {
			L = (int *) malloc(sizeof(int)*max_n); n = 0;
			for (int i=0; i<max_n; i++) {
				int e; scanf("%d", &e);	Insere(L,n,e);
			}
		} else {
			/* automatic test */
			max_n = 1000000;
			L = (int *) malloc(sizeof(int)*max_n); 
			n = 0;
			for (int i=max_n; i>0; i--) {
				Insere(L,n,i); 
			}
			L[500000] = -1; L[70000] = 3000000;
		}
		printf("%d\n", C_MaiorDiferenca(L, n, 200));
		free(L); 
	}
	return 0;
}