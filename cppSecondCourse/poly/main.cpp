#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw() { cout << "Shape::draw()" << endl; }
    virtual void show()=0;
    virtual void hide() { cout << "Shape::hide()" << endl; }
    ~Shape() { cout << "Shape::DTOR()" << endl; }
};
void Shape::show(){};




class Rectangle : public Shape
{
public:
    virtual void draw() { cout << "Rectangle::draw()" << endl; }
    virtual void show() { cout << "Rectangle::show()" << endl; }
    virtual void hide() { cout << "Rectangle::hide()" << endl; }
    ~Rectangle() { cout << "Rectangle::DTOR()" << endl; }
};

class Polygon : public Shape
{
public:
    virtual void draw() { cout << "Polygon::draw()" << endl; }
    virtual void show() { cout << "Polygon::show()" << endl; }
    virtual void hide() { cout << "Polygon::hide()" << endl; }
    ~Polygon() { cout << "Polygon::DTOR()" << endl; }
};

class Ellipse : public Shape
{
public:
    virtual void draw() { cout << "Ellipse::draw()" << endl; }
    virtual void show() { cout << "Ellipse::show()" << endl; }
    virtual void hide() { cout << "Ellipse::hide()" << endl; }
    ~Ellipse() { cout << "Ellipse::DTOR()" << endl; }
};

void show_any_shape(Shape& s){
    s.draw();
}

int main()
{

    Rectangle r1,r2;
    Ellipse e1,e2;
    Polygon p1,p2;
    show_any_shape(r1);



}