//'Hello world test'

#include <iostream>
#include <stdio.h>
#include "TestClass.cpp"







int main(){
	//std::cout << "Hello world" << std::endl;
	int numberOfClasses = 100;
	TestClass myTestClass;
	TestClass myClasses[numberOfClasses];
	for(int i =0; i < sizeof(myClasses)/sizeof(myClasses[0]); i++){
		myClasses[i].set_values(i+1,i+2);
		printf ("Array element %d area : %d \n",i,myClasses[i].area());
	}

	myTestClass.set_values(3,4);
	printf("area is:%d \n",myTestClass.area());

	return 0;
}
