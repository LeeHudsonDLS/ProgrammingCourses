#include <iostream>
#include <tr1/memory>
#include <stdexcept>

using namespace std;

class X
{
	public:
		X(int x): x(x){}
		~X(){cout << "DTOR: "<< x << endl;}	
	private:
		int x;
};




int main()
{
	try
	{
		//This is on the stack
		X x1(100);

		//The object *ptr is on the heap
		X* ptr =  new X(200);

		//*x3 is on the heap, x3 is on the stack but x3 is a smart pointer
		tr1::shared_ptr<X>x3(new X(300));
		
		throw exception();
		
		//This doesn't get called so we have a memory leak
		delete ptr;
	}catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	/*
	tr1::shared_ptr<string>str(new string("hello world"));
	cout<<*str<<endl;*/
	return 0;
}