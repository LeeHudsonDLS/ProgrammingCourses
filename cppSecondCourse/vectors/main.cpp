#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
    list<int> v1;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    /*
    for(vector<int>::iterator i = v1.begin(); i != v1.end(); ++i){
        cout << *i << endl;
    }*/

    for(auto i = v1.begin(); i != v1.end(); ++i){
        cout << *i << endl;
    }

}