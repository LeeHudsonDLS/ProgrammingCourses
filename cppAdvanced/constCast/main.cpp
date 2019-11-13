////////////////////////////////////////////////////////////
//
//		Const Casts
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

void print(char * str)
{
    cout << str << endl;
}

int main()
{
    const char *c1 = "const text";
    print(const_cast<char *> (c1));

    volatile char *c2 = const_cast<volatile char*>("volatile text");
    print(const_cast<char *> (c2));

    volatile const char *c3 = const_cast<volatile const char*>("volatile const text");
    print(const_cast<char *> (c3));
}
