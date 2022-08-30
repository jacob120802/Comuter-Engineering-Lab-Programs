#include<iostream>
#include<iomanip>
using namespace std;
class centimeters
{
	float cm;
	public:
		centimeters(float c)
		{
			cm = c;
		}
		void display()
		{
			cout << "The distance in cm is:";
			cout.setf(ios::fixed,ios::floatfield);
			cout.precision(3);
			cout << cm << endl;
		}
		float returnc()
		{
			return cm;
		}
};
class meters
{
	float m;
	public:
		meters()
		{
			m = 0.0;
		}
		meters(centimeters c)
		{
			m = c.returnc()/100.0;
			
		}
		void display()
		{
			cout << "The distance in m is:";
			cout.setf(ios::fixed,ios::floatfield);
			cout.precision(3);
			cout << m << endl;
		}
};
int main()
{
	float c;
	cout << "Enter distance in cm:";
	cin >> c;
	centimeters cm1 = centimeters(c);
	cm1.display();

	meters m1;
	m1 = cm1;
	m1.display();	
	return 0;
}
