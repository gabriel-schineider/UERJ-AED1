#include <stdio.h>

int bin (int n, int k)
{
	// assume-se n >= k >= 0
	// retorna n! / ( (n-k)! * k! )
	
	if (n == k)
	{
		return 1;
	}
	else
	{
		return bin(n-1, k) * n / ( n - k ) ;
	}
}	// fazendo a recurssão com n-1

int main (void)
{
// Aplicação da Função Recursiva Binomial (bin)
	int e = 5;
	int p = 2;
	printf("Escolhendo %d elementos para colocar em %d posições, temos: %d configurações diferentes.\n", e, p, bin(e,p));
  
  return 0; 
}