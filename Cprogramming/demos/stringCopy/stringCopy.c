#include<stdio.h>

void stringCopy(char* d, const char* s)
{
	while(*d++=*s++);	

}

int main(void)
{
	short a[11];

	for(int i = 0; i < sizeof(a)/sizeof(short); i++){
		a[i]=i;
	}
	for(int j = 0; j < sizeof(a)/sizeof(short); j++){
		printf("%d\n",a[j]);
	}

	//printf("%s\n",a);
}
