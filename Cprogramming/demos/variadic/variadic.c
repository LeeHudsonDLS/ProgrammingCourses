#include<stdio.h>
#include<stdarg.h>

double average(int n, ...)
{	

	va_list params;

	va_start(params,n);
	double p0 = va_arg(params,double);
	double p1 = va_arg(params,double);
	double p2 = va_arg(params,double);
	va_end(params);

	return (p0 + p1 + p2)/n;
}


int main(void)
{
	double result;
	result = average(3,10.0,15.0,21.7);
	printf("%6.3lf",result);
}
