#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
	cout.width(5);
	cout<<"Value";
	cout.width(32);
	cout.fill('*');
	cout<<"Division 1/sqrt(value)"<<endl;
	
	cout.setf(ios::showpoint);
	int i;
	for(i=1;i<=5;i++)
	{
		if(i==1)
			cout.precision(5);
		else
			cout.precision(4);
		cout.setf(ios::internal,ios::adjustfield);
		cout.width(5);
		cout.fill('.');
		cout.setf(ios::showpos);
		if(i==4)
			cout.fill('<');
		else if(i==5)
			cout.fill('>');
		cout<<i;
		
		//cout.setf(ios::right,ios::adjustfield);
		cout.unsetf(ios::showpos);
		cout.width(16);
		cout.fill('*');
		if(i==4)
			cout.fill('>');
		else if(i==5)
			cout.fill('<');
		cout<<1/sqrt(i)<<endl;
		cout<<"\n";
	}
	return 0;
}
