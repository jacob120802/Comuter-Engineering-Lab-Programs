#include<iostream>
using namespace std;
class code
{
	private:
		int x;
public:
	code()
	{
		cout<<"Default constructor called\n";
		x=0;
		cout<<"Value of x = "<<x<<endl;
	}
	code(int a)
	{
		cout<<"Parameterized constructor called\n";
		x=a;
		cout<<"Value of x = "<<x<<endl;
	}
	code(code&y )
	{
		cout<<"copy constructor called\n";
		x=y.x;
		cout<<"Value of x = "<<x<<endl;
	}
	void display()
	{
		cout<<"Value of x = "<<x<<endl;
	}
	~code()
	{
		cout<<"\nObject Destroyed"<<endl;
	}
};
int main()
{
code a(100);//calls parameterized constructor
code b(a); //calls copy constructor
code d;//calls default constructor
cout<<"\n For object d "; d.display();
cout<<"\n For object a "; a.display();
cout<<"\n For object b "; b.display();
return 0;
} 