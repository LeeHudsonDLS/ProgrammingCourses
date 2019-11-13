//'Hello world test'

#include <iostream>
#include <stdio.h>


class Point
{
	public:
		Point(const std::string& name, int x, int y);
		~Point();
		void moveBy(int,int);	
		void display();

	private:
		std::string name;
		int x;
		int y;

};

//*******************************

using namespace std;

Point::Point(const string& name, int x0, int y0) :  name(""),x(x0),y(y0)
{
}

Point::~Point()
{
	std::cout <<"Destruction"<< std::endl;
}

void Point::moveBy(int dx, int dy){
	x+=dx;
	y+=dy;
}

void Point::display(){
	std::cout <<"X = "<< x << " Y = "<< y << std::endl;
}






int main()
{
	string myString("test");
	try{
		Point* ptr = new Point("Heap",11,11);
		ptr->display();
		throw exception();
		delete ptr;
	}catch(exception e){
		std::cout <<"Exception"<< std::endl;
	}
	

	//printf("%d\n",x);

}

