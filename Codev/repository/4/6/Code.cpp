#include <stdio.h>
#include <stdlib.h>


int RaizQuad(int n) {
	// assume n >= 0
	// retorna ⌊√(n)⌋
	/* insert your code here */

	if (n == 0)
	{
		return 0;
	}

	int i, f, m;
	i = 0; f = n+1;
	m = RaizQuad(n/2);
	
	if (i+1 == f)
	{
		return i;
	}
	
	else if (m*m == n)
	{
		return m;
	}
	if (m*m > n)
	{
		return m+1;
	}
	else if (m*m < n)
	{
		return m;
	}
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; 
	while (scanf("%d", &n)>0) {
		if (n>=0) {
			/* teste manual */
			printf("%d\n", RaizQuad(n));
		} else {
			/* teste automático */
			n = 50000; 
			for (int t=1; t<=200; t++) RaizQuad(n);
			printf("%d\n", RaizQuad(n));
		}
	}

	return 0;
}
