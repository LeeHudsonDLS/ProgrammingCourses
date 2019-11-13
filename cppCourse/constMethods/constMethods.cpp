#include <iostream>
using namespace std;

class Point
{
	friend ostream& operator<<(ostream& out, const Point& p);
	public:
		Point(int x, int y) : x(x), y(y) {}

		//Need to make this method const to exlicitly say
		//we're not changing the parameter passed. The const version
		//will be called if the parameter passed is const
		void display() const { cout <<"immutable"<< *this << endl;}
		void display() { cout << "mutable" << *this << endl;}
	private:
		int x,y;
};

//Overriding the << operator to allow a cout<< to be able to print our object
ostream& operator<<(ostream& out, const Point& p)
{
	out <<"X:" << p.x << "," <<"Y:"<< p.y ;
	return out;
}

int main()
{
	Point p(4,5);
	const Point cp(40,50);
	cp.display();
	p.display();
	cout << p;
	cout << endl; //cout& = operator<<(cout,p)
}

