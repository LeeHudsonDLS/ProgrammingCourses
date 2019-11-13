#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

template <typename T>

//Generic template for method
T Max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}

//specialised version of max method. This will be called if we pass
// const char* as parameters over the generic template
const char* Max(const char* a, const char* b)
{
	return b;
}




int main()
{
	cout << Max(5, 8) << endl;
	cout << Max(5.1, 8.3) << endl;

	//This doesn't work as we're passing a const char*, as it's a pointer it will
	//look at the address not value. Cast to string
	cout << Max("Red", "Blue") << endl;
	//cout << Max<string>("Red", "Blue") << endl;
	//cout << Max((string)"Red", (string)"Blue") << endl;	 
	return 0;
}


