/*
	This class creates objects on the heap. We need to override the copy constructor to
*/
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

class String
{
	public:
		String(const char* t)
		{
			text = new char[strlen(t)+1];
			strcpy(text,t);
		}

		//Overriding the copy constructor
		String(const String& old)
		{
			text = new char[strlen(old.text)+1];
			strcpy(text,old.text);
		}
		
		//Overriding the = operator
		String& operator=(const String& rhs)
		{
			if(this == &rhs) return *this;
			delete[] text;
			text = new char[strlen(rhs.text)+1];
			strcpy(text,rhs.text);
			return *this;
		}

		~String()
		{
			cout << "DTOR" << endl;
			// If you're creating multiple objects on the heap make sure you call all the destructors
			// hence the [].
			delete[] text;
		}

	private:
		char* text;
};

void f(String w){
}

String g(){
	String temp("green");
	return temp;

}


int main()
{
	String myString("Red");
	//f(myString);
	myString = g();
	myString = myString;
}
