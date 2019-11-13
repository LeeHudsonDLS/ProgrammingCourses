#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

//Functor. This overrides the () operator
class Query
{
	public:
		Query(int s):salary(s){}
		bool operator()(const pair<string, int>& item)
		{
			if(item.second < salary)
			return true;
			return false;
		}
	private:
		int salary;
};

bool LessThan40K(const pair<string, int>& item)
{
	if(item.second < 40000)
		return true;
	return false;

}

int main()
{
	map<string, int> salary;
	map<string, int>::iterator i;
	salary["Bob"] = 52000;
	salary["Tom"] = 42000;
	salary["Jim"] = 51000;
	salary["Tim"] = 37000;
	salary["Sue"] = 45000;

	//Find the guy with salary < xxk

	Query q(39000);
	
	//Calling the find_if() from the algorithm library
	i = find_if(salary.begin(),salary.end(), q);
	if( i != salary.end())
	{
		const string& key = i->first;
		int& value = i->second;
		cout << key << " : " << value << endl;
	}else{
		cout <<"not found" << endl;
	}
	/*
	for(i = salary.begin(); i != salary.end(); ++i)
	{
		const string& key = i->first;
		int& value = i->second;
		cout << key << " : " << value << endl;
	}*/

	return 0;

}
