#include <iostream>
using namespace std;

// const causes reference to only have read access to the variable
void swap(int &a, const int &b){
    int temp;
    temp = a;
    a = b;

    //Won't work due to being const
    //b = temp;
}


int main() {
    int x = 100;
    int y = 200;
    int z = 300;
    int *test = &x;
    int* px = &x;
    int*& ppx = px;

    // Creates alias for x
    int& xx =x;
    int& xxx = xx;
    x++;
    xx++;
    xxx++;
    cout << *ppx << endl;
    cout << y << endl;
    cout << z << endl;
}