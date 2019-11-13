////////////////////////////////////////////////////////////
//
//      Classes using templates
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#define cout cout << " "
/*
class ArrayOfInts
{
private:
    int array[3];
public:
    ArrayOfInts(int);
    void Print();
};

ArrayOfInts::ArrayOfInts(int x)
{
    for(int i = 0; i < 3; i++)
        array[i] = x;
}

void ArrayOfInts::Print()
{
    for(int i = 0; i < 3; i++)
        cout << array[i] << "\t";
    cout << endl;
}*/

/////
template <typename T, int N>
class Array
{
private:
    T array[N];
public:
    Array(T);
    void Print();
};

template <typename T, int N>
Array<T,N>::Array(T x)
{
    for(int i = 0; i < N; i++)
        array[i] = x;
}

template <typename T, int N>
void Array<T,N>::Print()
{
    for(int i = 0; i < N; i++)
        cout << array[i] << "\t";
    cout << endl;
}

/////


int main()
{
    Array<int,6> a(15);
    Array<int,7> b(15);
    Array<int,8> c(15);
    Array<int,9> d(15);
    Array<double,4> e(27.96);

    a.Print();
    b.Print();
    c.Print();
    d.Print();
    e.Print();

    return 0;
}

