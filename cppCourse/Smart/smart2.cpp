/*Note: Copy constructor is called:

	1) when we're assigning by initization, ie, object(anotherObject)
	2) When we pass an object by value to a function
	3) When we return an obecjt by value from a function
*/
#include <iostream>
using namespace std;

class X
{
	public:
		X(int x) : x(x){}
		~X(){ cout << "DTOR" << endl;}
		void display(){cout << x << endl;}
	private:
		int x;
};


template <typename T>
class SmartPtr
{
	public:
		SmartPtr(T* ptr) : pBody(ptr) 
		{
			pCount = new int(1);
		}

		//Overriding the copy constructor to do a shallow copy and increment our
		//custom reference counter.
		SmartPtr(const SmartPtr& old) : pCount(old.pCount), pBody(old.pBody)
		{
			//pCount = old.pCount;
			//pBody = old.pBody;
			*pCount += 1;
			pBody; 
		}
		~SmartPtr()
		{ 
			*pCount -= 1;
			if(*pCount == 0) 
			{
				delete pCount; 
				delete pBody;
			}
		}
		T* operator->(){ return pBody;}

		SmartPtr& operator=(const SmartPtr& rhs)
		{
			/*
			//We're now basically destructing *this as we're about to reassign it
			*pCount -= 1;
			if(*pCount == 0) 
			{
				delete pCount; 
				delete pBody;
			}*/
			this->~SmartPtr(); // call the destructor as we're reassigning
			pCount = rhs.pCount; //get the pcount reference from the one we're copying
			pBody = rhs.pBody;
			*pCount += 1;	//Increment the reference count
			return *this;	//We have to return this
			
		}
	private:
		int* pCount; // reference counter to keep track of how many things are pointing to pBody
		T* pBody;

};

int main()
{

	SmartPtr<X> h1(new X(100));
	SmartPtr<X> h2(new X(200));
	h1->display(); //Override the -> operator to return the body, h1-> is basically h1.pBody

	SmartPtr<X> h3(h1); // copy CTOR
	h2 = h1;	//h2.operator=(h1)
	
}

