#include<stdio.h>
#include<string.h>

void reversePrint(const char* text)
{
	char c = text[0];
	if(strlen(text) > 1)
	{
		reversePrint(++text);
	}
	putchar(c);
}

int main(void)
{
	reversePrint("ABCDEFGHIJKLMNOP");
}
