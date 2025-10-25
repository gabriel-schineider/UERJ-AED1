# include <stdio.h>

int main (void)
{
	// INSTEAD OF USING A HIGH HEADACHEBLE MAINTAINING CODE LIKE:
	/*
	float V[24 * 365];
	*V = 2.2;
	V[1] = 3.8;
	V[47] = 2.7;
	V[(31+28+31+30+2)*24 + 3] = 4.6;
	*/
	
	// WE CAN, SIMPLY, DO:
	float V[24][31][12][45];
	V[2][2][4][18] = 4.6;
	
	printf("%f \n", V[2][2][4][18]);
	
	return 0;
}
