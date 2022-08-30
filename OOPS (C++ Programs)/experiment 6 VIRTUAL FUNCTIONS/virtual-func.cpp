#include<iostream>
using namespace std;
class base
{
	public:
		void display()
		{
			cout<<"\nBase class display :";
		}
		virtual void show()
		{
			cout<<"\nBase class show : ";
		}
};
class derived : public base
{
	public:
		void display()
		{
			cout<<"\nDerived class display : ";
		}
		void show()
		{
			cout<<"\nDerived class show : ";
		}
};
int main()
{
	base b;
	derived d;
	
	base *bptr;
	cout<<"\n bptr points to Base\n";
	bptr=&b;
	
	bptr->display();  //calls base class display
	bptr->show();	  //calls base class show
	
	cout<<"\n\n-------------------------------\n";
	
	cout<<"\n bptr points to Derived\n";
	bptr=&d;
	
	bptr->display();  //calls base class display (function overriding)
	bptr->show();     //calls derived class show (using virtual function)
	
	return 0;
}
