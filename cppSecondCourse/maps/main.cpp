#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

/*
 * Creating class overloading () operator. Can be treated like a function
 *
 */
class Query{
public:
    Query(int salary): salary(salary){}
    bool operator() (const pair<string, int>& i){
        return get<1>(i) < salary;
    }
private:
    int salary;
};

bool lessThan24k(const pair<string, int>& i){
    return get<1>(i) < 24000;
}


int main() {
    int s = 25000;
    map<string,int> salary;

    salary["John"]=45000;
    salary["Mary"]=55000;
    salary["Peter"]=21000;
    salary["Ali"]=28000;
    salary["Zahir"]=53000;

    //Using functor
    //Query q(24000);

    // Using lambda
    auto qq =[&s](const pair<string, int>& i){
        return get<1>(i) < s;
    };
    map<string,int>::iterator i;

    i = find_if(salary.begin(),salary.end(),qq);
    //i = find_if(salary.begin(),salary.end(),q);
    //i = find_if(salary.begin(),salary.end(),lessThan24k);

    if(i != salary.end()){
        cout << get<0>(*i) << endl;
    }else{
        cout << "Not found" << endl;
    }


    /*
    for(auto entry : salary){
        cout << get<0>(entry) << "," << get<1>(entry) << endl;
    }*/

}