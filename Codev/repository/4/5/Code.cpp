#include <stdio.h>
#include <stdlib.h>

int RaizQuad(int n) {
	// assume n >= 0
	// retorna r tal que r^2 <= n < (r+1)^2
	/* insert your code here */
	if (n == 0)
	{
		return 0;
	}
	else
	{
		int r = RaizQuad(n-1);
		if (((r+1)*(r+1)) == n)
		{
			return r+1;
		}
		if ( (r*r <= n) && (((r+1)*(r+1)) > n) )
		{
			return r;
		}
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
