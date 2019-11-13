#include <iostream>
using namespace std;

class Time
{
	//Overriding the + operator and calling it "friend" so it can access
	//private variables
	friend Time operator+(const Time& lhs, const Time& rhs);

	public:
		Time(int h, int m): hrs(h), min(m){}
		Time():hrs(0),min(0){}

		//Override += operator
		Time& operator+=(const Time& rhs);
		
		//Display the time
		void display();

		//Cast an int to a time 
		Time(int m) : hrs(m/60), min(m%60){}

		//Cast a time to an int
		operator int();	
				
	private:
		int hrs,min;


};

//Overriding += operator. Works with a "this" as it's a member function,
//returns a reference to itself after modifying it's variables accordingly
Time& Time::operator+=(const Time& rhs)
{
	hrs += rhs.hrs;
	min += rhs.min;
	if(min >= 60)
	{
		hrs ++;
		min -=60;
	} 
	return *this;
}

void Time::display()
{
	cout << hrs << " : " << min << endl;
}

//Overrides the int() operator, int timeInt = int(t3);
Time::operator int()
{
	return hrs*60 + min;
}


//Free function, This could be a member function but being "Friend" means
//it can touch privates
Time operator+(const Time& lhs, const Time& rhs)
{	
	Time result;
	result.hrs = lhs.hrs + rhs.hrs;
	result.min = lhs.min + rhs.min;
	return result;
}

int main()
{
	Time t1(3,45);
	Time t2(4,20);
	Time t3(120);
	Time t;
	int timeInt = int(t3);
	t = t1+t2;
	t1 += t2;
	t1.display();
	t3.display();
	cout << timeInt << endl;
}
