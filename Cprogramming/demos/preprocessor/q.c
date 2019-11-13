#include<stdio.h>

//#define CUBE(X) ((X) * (X) * (X))

int CUBE(int a)
{
	return a*a*a;
}

int main(void)
{
	int x = 3;
	int y = CUBE(x++);
	printf("%i\n",y);
	return 0;
}
