#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape
{
public:
    virtual void draw() =0;
    virtual void show() =0; // Make class abstract
    virtual void hide() =0;
    ~Shape() { cout << "Shape::DTOR()" << endl; }
};

void Shape::show() {
    cout << "Default implentation" << endl;
}

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
    void show() {
        Shape::show();
        cout << "Polygon::show()!!!" << endl;
    }
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

void showAll(const std::vector<shared_ptr<Shape>>& v){
    for(auto shape:v){
        shape->show();
    }

}

int main()
{
    // Using shared_ptr to automatically clean up heap
    // shared_ptr doesn't require the DTOR to be virutal, unique pointers do
    std::vector<shared_ptr<Shape>> z;
    z.push_back(shared_ptr<Shape>(new Rectangle()));
    z.push_back(shared_ptr<Shape>(new Rectangle()));
    z.push_back(shared_ptr<Shape>(new Polygon()));
    z.push_back(shared_ptr<Shape>(new Polygon()));
    z.push_back(shared_ptr<Shape>(new Ellipse()));
    z.push_back(shared_ptr<Shape>(new Ellipse()));
    showAll(z);

    // Destructors called

}

