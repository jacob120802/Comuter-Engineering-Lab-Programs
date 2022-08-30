//Understanding exception handling(Divide by zero)
//Rethrowing   (throw)
#include<iostream>
using namespace std;
void divide(double x,double y)  
{
	cout<<"\nInside divide function\n";
	try
	{
		if(y==0.0)
		{
			throw y;//throws var (throwing exception)
		}
		else
		{
			cout<<"\nResult of (x/y) :"<<x/y<<"\n";
		}
	}
	catch(double)
	{
		cout<<"\nCaught double inside divide function\n";
		throw ;		//Rethrowing
	}
}
int main()
{
	double x,y;
	cout<<"\nEnter values of x & y :";
	cin>>x>>y;
	cout<<"\nInside main program";
	try
	{
		divide(x,y);//try eg: (10.5,2.5) and (20.0,0.0)
	}
	catch(double)
	{
		cout<<"\nCaught double inside main program";
	}
	return 0;
}
