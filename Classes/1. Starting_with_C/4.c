// (1) Creating and (2) Using a function to double a number

#include <stdio.h>

// Passing by value <==> Without passing by referrence

int times2 (int num)
{
	return num *= 2;
}

// Passing by referrence

void x2 (int* num)
{
	*num *= 2;
}


int main (void)
{
	int num;
	scanf("%d", &num);
	times2(num);
	printf("%d \n", num);
	
	//\\
	
	int num2;
	scanf("%d", &num2);
	x2(&num2);
	printf("%d \n", num2);
	
	return 0;
}
