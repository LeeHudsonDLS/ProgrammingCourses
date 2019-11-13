#include <iostream>
#include <stdio.h>
using namespace std;

class Point
{

	public:
		static Point& createPoint(int x, int y)
		{
			Point* ptr = new Point(x,y);
			return *ptr;
		}
	private:
		Point(const Point&);
		Point();
		Point(int,int):x(x),y(y){}
		int x;
		int y;

};



int main()
{
	Point& p = Point::createPoint(9,10);

}
