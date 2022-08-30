//Multiple catch statements
#include<iostream>
using namespace std;
void test(int x)
{
	try
	{
		if(x==1)  throw x;			//throw int
		else if(x==0) throw 'x';	//throw char
		else if(x==-1) throw 1.0;	//throw double
		cout<<"\nEnd of try block:\n";
	}
	catch(char c)
	{
		cout<<"\nCaught a character\n";
	}
	catch(int m)
	{
		cout<<"\nCaught a integer\n";
	}
	catch(double d)
	{
		cout<<"\nCaught a double\n";
	}
	cout<<"\nEnd of catch block:\n";
}

int main()
{
	cout<<"\nTesting multiple catches:\n";
	
	cout<<"\n\nX == 1";
	test(1);
	
	cout<<"\n\nX == 0";
	test(0);
	
	cout<<"\n\nX == -1";
	test(-1);
	
	cout<<"\n\nX == 2";
	test(2);
	
	return 0;
}
	
	
	
	
	
