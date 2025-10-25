#include <stdio.h>
#include <stdlib.h>

long long int Bin(int n, int k) {
	// assume n >= k >= 0
	// retorna binomial de n,k = n! / (k! (n-k)!)
	/* insert your code here */
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; int k; 
	while (scanf("%d %d", &n, &k)>0) {
		if (n>=0) {
			/* teste manual */
			printf("%lld\n", Bin(n,k));
		} else {
			/* teste automático */
			n = 50000; k = 49999;
			for (int t=1; t<=200; t++) Bin(n,k);
			printf("%lld\n", Bin(n,k));
		}
	}

	return 0;
}