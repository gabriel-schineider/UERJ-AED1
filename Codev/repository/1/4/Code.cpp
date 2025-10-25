#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int QtdePrimos(int n) {
	/* insert your code here */
	long long int c = 0;
	for (int i=2; i<=n; i++)
	{
		bool primo = true;
		for (int j=2; j<=sqrt(i); j++)
		{
			if (i % j == 0) { primo = false; break; }
		}
		if (primo) { c++; }
	}
	return c;
}

int main() {
	int n;  
	while (scanf("%d", &n)>0) {
		printf("%d\n", QtdePrimos(n));
	}
}
