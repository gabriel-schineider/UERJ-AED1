#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ContaMisteriosa(int n) {
	/* insert your code here */
	double soma = 0.0;
	long long int dezN = pow(10,n);
	double menos1 = 1; // Assuming this variable as double garantee the division (*) bellow has a floating-point result.
	for (long long int k=1; k<=dezN; k++)
	{
		soma += menos1/(2*k-1); // (*) preserves decimal precision
		menos1 = -menos1;
	}
	return 4*soma;
}

int main() {
	int n;  
	while (scanf("%d", &n)>0) {
		printf("%.8f\n", ContaMisteriosa(n));
	}
}
