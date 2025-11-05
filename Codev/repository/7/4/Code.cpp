#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>


long long int NumeroMaisFrequente(long long int L[], int n) {
	/* insert your code here */
}

void Insere(long long int L[], int &n, long long int e) {
	L[n] = e;
	n = n + 1;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n; long long int * L; int n;
	while (scanf("%d", &max_n) > 0) {
		if (max_n != -1) {
			L = (long long int *) malloc(sizeof(long long int) * max_n);
			n = 0;
			for (int i = 0; i < max_n; i++) {
				long long int e;
				scanf("%lld", &e);
				Insere(L, n, e);
			}
		} else {
			/* automatic test */
			max_n = 3000000;
			L = (long long int *) malloc(sizeof(long long int) * max_n);
			n = 0;
			for (long long int i = max_n; i > 0; i--) {
				Insere(L, n, 1000000*i);
			}
			L[100000] = 1000000*(long long int)191191;
		}
		printf("%lld\n", NumeroMaisFrequente(L, n));
		free(L);
	}
	return 0;
}