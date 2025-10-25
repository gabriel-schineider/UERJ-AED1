#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool ePrimo1 (long int n)
{
	for (long int i=2; i<n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool ePrimo2 (long int n)
{
	for (long int i=2; i<(long int)sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

/*bool ePrimo3 (int n)
{
	for (int i=2; i<n-(int)sqrt(n); i++); // THAT IS REALLY BAD OHHHHHH >W<
}*/


int main (void)
{
	printf("%d \n", ePrimo1(1223212141116213421));
	//printf("%d \n", ePrimo1(1223));
	
	return 0;
}
