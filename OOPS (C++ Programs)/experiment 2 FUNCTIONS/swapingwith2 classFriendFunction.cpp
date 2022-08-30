#include<iostream>
using namespace std;
class B;
class A
{
	private:
		int x;
	public:
		A(int n)
		{
			x=n;
		}
		void show()
		{
			cout<<" Value of x: "<<x;
		}
		friend void swap(A *x,B *y);
};
class B
{
	private:
		int y;
	public:
		B(int n)
		{
		y=n;
		}
		void show()
		{
		cout<<"\n Value of y : "<<y;
		}
		friend void swap(A *x,B *y);
};
void swap(A *n1,B *n2)
{
	int temp;
	temp=n1->x;
	n1->x=n2->y;
	n2->y=temp;
}
int main()
{
	A p(30);
	B c(40);
	cout<<"Before swapping\n";
	p.show();
	c.show();
	swap(&p, &c);
	cout<<"\n\nAfter swapping\n";
	p.show();
	c.show();
	return 0;
}
/*#include <iostream>
using namespace std;

class b;
class a
{
	int x;
	public:
	a(int c)
	{
		x=c;
	}
	friend void swap(a,b);
};
class b
{
	int y;
	public:
	b(int d)
	{
		y=d;
	}
	friend void swap(a,b);
};
void swap(a e,b f)
{
	int temp;
	temp=e.x;
	e.x=f.y;
	f.y=temp;
	cout<<"after swapping value of class a="<<e.x<<endl;
	cout<<"after swapping value of class b="<<f.y<<endl;
}
int main() {
	a e(5);
	b f(3);
	swap(e,f);
	return 0;
}*/