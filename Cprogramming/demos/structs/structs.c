#include<stdio.h>

typedef struct 
{
	char c;
	int x;
	int y;
} Point;

void display(Point* ptr)
{
	printf("%i \n", sizeof(*ptr));
	printf("X: %i, Y: %i\n",ptr->x,ptr->y);
}

int main(void)
{
	Point p1;
	p1.x=100;
	p1.y=200;
	display(&p1);

	Point p2;
	p2.x=125;
	p2.y=225;
	display(&p2);

	Point p3;
	p3=p1;

	display(&p3);
}
