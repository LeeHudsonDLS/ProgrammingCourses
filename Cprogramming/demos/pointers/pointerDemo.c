#include<stdio.h>

int main(void)
{

	int x;
	int *px = &x;
	int **q = &px;
	printf("Enter a number:");
	
	//scanf needs an address to put the data in, level 1.
	//&x is the address of x
	//px points to the address of x

	//scanf("%i", &x);
	//scanf("%i", px);
	scanf("%i", *q);
	printf("You typed : %i\n",x);
	return 0;
}
