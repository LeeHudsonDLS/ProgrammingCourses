////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class String
{
    friend String operator+(const String&, const String&);
public:
    String(const char* s = "")
    {
        text = new char[strlen(s) + 1];
        strcpy(text, s);
    }
    String(const String& old)
    {
        cout << "ref CTOR" << endl;
        text = new char[strlen(old.text) + 1];
        strcpy(text, old.text);
    }
    String(String&& temp)
    {
        cout << "rref CTOR" << endl;
        text = temp.text;
        temp.text = 0;
    }

    String operator=(const String& rhs)
    {
        cout << "ref =" << endl;
        if(this == &rhs) return *this;
        delete [] text;
        text = new char[strlen(rhs.text) + 1];
        strcpy(text, rhs.text);
        return *this;
    }
    String operator=(const String&& rhs)
    {
        cout << "rref =" << endl;
        if(this == &rhs) return *this;
        delete [] text;
        text = rhs.text;
        return *this;
    }
private:
    char* text;
};

String operator+(const String& lhs, const String& rhs)
{
    String result;
    delete[] result.text;
    result.text = new char[strlen(lhs.text) + strlen(rhs.text) + 1];
    strcpy(result.text, lhs.text);
    strcat(result.text, rhs.text);
    return result;
}


int main()
{
    String s1("ABC");
    String s2("DEFGHI");
    String s3(s1 + s2);		// should call String(String&&)
    String s4;
    s4 = s1 + s2;			// should call String(String&&) and
    // should call operator=(String&&)
}


