
#include <iostream>
#include <string>

using namespace std;

template <typename T = int, int N = 3>
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


int main()
{
	Array<int> a(15);
	Array<double,246> b(27.96);
	a.Print();
	b.Print();
}

