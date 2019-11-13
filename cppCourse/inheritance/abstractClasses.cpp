
#include <iostream>
using namespace std;

class Shape
{
	public:
		virtual void draw() { cout << "Draw.draw()" << endl;}
		virtual void show() = 0; // Make this abstract, makes the whole class abstract
		virtual void hide() { cout << "Shape.hide()" << endl;}
};



class Triangle : public Shape
{
	public:
		virtual void draw() { cout << "Triangle.draw()" << endl;}
		virtual void show() { cout << "Triangle.show()" << endl;}
		virtual void hide() { cout << "Triangle.hide()" << endl;}
};

class Ellipse : public Shape
{
	public:
		virtual void draw() { Shape::draw(); cout << "Ellipse.draw()" << endl;}
		virtual void show() { cout << "Ellipse.show()" << endl;}
		virtual void hide() { cout << "Ellipse.hide()" << endl;}
};

class Rectangle : public Shape
{
	public:
		virtual void draw() { cout << "Rectangle.draw()" << endl;}
		virtual void show() { cout << "Rectangle.show()" << endl;}
		virtual void hide() { cout << "Rectangle.hide()" << endl;}
};


void drawAnyShape(Shape& s)
{
	s.draw();
}

int main()
{
	Triangle t;
	Ellipse e;
	Rectangle r;
	drawAnyShape(e);
	//Shape s;
	return 0;


}
