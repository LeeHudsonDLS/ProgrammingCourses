#include<stdio.h>
#include<stdlib.h>
//Pointers and arrays are very similar. Arrays declared x[5] allocates 5 bytes + 1byte for the start address.
//You can't modify x directly. If the array is int *x you can modify X. That's the only difference.

//a[1] == *(a+1) == *a+1
void f(int *p); //can be int a[]


int main(void)
{
	int a[3][2] = {{10,20},{30,40},{50,60}};

	return 0;
}

void f(int *p)
{
	//int i;
	printf("a in the function is %i bytes long \n",sizeof(p));
	for(int i=0; i < 6; i++)
	{
		printf("%3i\n",p[i]);
		printf("%3i\n",*(p+i));
	}
/*
	As P is a pointer you can increment it. This means when it is possible to say p[-1]!
	p++;
	p++;
	p--;
	p--;
*/
	
}

