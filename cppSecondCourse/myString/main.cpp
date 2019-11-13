#include <iostream>
#include <cstring>

class String{
public:
    //Copy constructor
    String(const String& s){
        text = new char[strlen(s.text)+1];
        strcpy(text,s.text);
    }

    String(const char* s=""){
        text = new char[strlen(s)+1];
        strcpy(text,s);
    }
    //Operates on "this" and rhs
    String& operator=(const String& rhs){
        if(this == &rhs) return *this;
        delete text;
        text = new char[strlen(rhs.text)+1];
        strcpy(text,rhs.text);

    }
    ~String(){
        delete[] text;
    }
private:
    char* text;
};

String g(){
    String temp("temp");
    return temp;
}

void f(String s){

}

int main() {
    String s1("ABCDEF");
    String s2;
    // Bad as not being passed as reference. Can cause the destructor to be call
    // more than once
    f(s1);

    //Need to overload operator=
    String s3=g();

}