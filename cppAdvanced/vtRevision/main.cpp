#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape
{
public:
    virtual void draw() { cout << "Shape::draw()" << endl; }
    virtual void show() { cout << "Shape::show()!!!" << endl; }
    virtual void hide() { cout << "Shape::hide()" << endl; }
    ~Shape() { cout << "Shape::DTOR()" << endl; }
};

class Rectangle : public Shape
{
public:
    void draw() { cout << "Rectangle::draw()" << endl; }
    void show() { cout << "Rectangle::show()!!!" << endl; }
    void hide() { cout << "Rectangle::hide()" << endl; }
    ~Rectangle() { cout << "Rectangle::DTOR()" << endl; }
};

class Polygon : public Shape
{
public:
    void draw() { cout << "Polygon::draw()" << endl; }
    void show() { cout << "Polygon::show()!!!" << endl; }
    void hide() { cout << "Polygon::hide()" << endl; }
    ~Polygon() { cout << "Polygon::DTOR()" << endl; }
};

class Ellipse : public Shape
{
public:
    void draw() { cout << "Ellipse::draw()" << endl; }
    void show() { cout << "Ellipse::show()!!!" << endl; }
    void hide() { cout << "Ellipse::hide()" << endl; }
    ~Ellipse() { cout << "Ellipse::DTOR()" << endl; }
};

void showAll(const std::vector<Shape*>& v){
    for(auto shape:v){
        shape->show();
    }

}

int main()
{
    /*
    Rectangle r1,r2;
    Polygon p1,p2;
    Ellipse e1,e2;

    // Can't pass by reference with the stl, hence using a pointer
    std::vector<Shape*> v;
    v.push_back(&r1);
    v.push_back(&r2);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&e1);
    v.push_back(&e2);
    showAll(v);
*/
    std::vector<Shape*> z;
    z.push_back(new Rectangle());
    z.push_back(new Rectangle());
    z.push_back(new Polygon());
    z.push_back(new Polygon());
    z.push_back(new Ellipse());
    z.push_back(new Ellipse());
    showAll(z);

}

