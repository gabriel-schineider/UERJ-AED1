#include <stdio.h>

int main (void)
{
	char V[100];
	*V = 'A';	*(V+99) = 'Z';
	
	// THE FOLLOWING LINES MEAN THE SAME...
	printf("%c %c \n", *V, *(V+99));
	//printf("%c %c \n", V[0], V[99]);
	
	return 0;
}
