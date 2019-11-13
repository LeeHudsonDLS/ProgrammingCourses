#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> cities;
	
	//Creating an iterator which is a member of the vector class
	vector<string>::iterator i;

	cities.push_back("London");
	cities.push_back("Brisbane");
	cities.push_back("Moscow");
	cities.push_back("Paris");
	cities.push_back("Tokyo");

	for(i = cities.begin(); i != cities.end(); ++i)
	{	
		cout << *i << endl;
	}
}
