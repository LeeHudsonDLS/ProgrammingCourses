
#include <iostream>
using namespace std;

class Person
{
	public:
		void sleep(){cout << "Sleeping" << endl;}

		//Need the keyword "virtual" to make them polymorphic
		virtual void eat(){cout << "Mcdonalds" << endl;}
		virtual void drink(){cout << "Special Brew" << endl;} 
		
};

class Employee : public Person
{
	public:
		void eat(){cout << "Nandos" << endl;}
		void drink(){cout << "Peroni" << endl;} 
		
};

class SalesPerson : public Employee
{
	public:
		void eat(){cout << "Fat duck" << endl;}
		void drink(){cout << "Champagne" << endl;} 
		
};

void nightOut(Person& p)
{
	p.eat();
	p.drink();
	p.sleep();	
}

int main()
{
	Person p1,p2;
	Employee e1,e2;
	SalesPerson s1,s2;
	nightOut(p1);
	nightOut(e1);
	nightOut(s1);

}

