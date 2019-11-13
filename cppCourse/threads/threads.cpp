/*
	Compile with: g++ -o main threads.cpp -l pthread
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <pthread.h>
using namespace std;

//Code for the threads to execute
void* work(void* v)
{
	//Re-cast the message variable as a string, see: *********
	string& message = *(string*) v;
	cout << message << endl;
	return 0;
	
}

int main()
{
	pthread_t t1,t2;
	string message1("Thread 1");
	string message2("Thread 2");

	//Create the threads
	//(void*) means the data is transferred to the kernel with no type. You need
	//to re-cast in the threaded method *************
	pthread_create(&t1, 0, work, (void*) &message1);
	pthread_create(&t2, 0, work, (void*) &message2);
	
	//Prevent the threads being killed at the end of main before they should be
	pthread_join(t1,0);
	pthread_join(t2,0);
}
