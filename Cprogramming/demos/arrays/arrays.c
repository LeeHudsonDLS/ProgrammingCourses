#include<stdio.h>

int main(void)
{

	//char s[6] = {'A','B','C','D','E','\0'};
	char s[12] = "ABCDEF";
	printf("Array is %i elements long\n",sizeof(s));
	printf("Array is %i elements long\n",strlen(s));
	printf("%s\n",&s);
	int x = 1;
	x = 2;
	printf("%i",x);	
	return 0;

}
