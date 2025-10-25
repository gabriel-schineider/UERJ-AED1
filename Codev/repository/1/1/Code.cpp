#include <stdio.h>
#include <stdlib.h>

long long int CalculaSoma(int n) {
	long long int soma=0;
	for (int i=1; i<=n; i++)
	{
	soma += i;
	}
	
	return soma;
}

int main() {
	int n;
	while (scanf("%d", &n)>0) {
		printf("%lld\n", CalculaSoma(n));
	}
	
	return 0;
}
