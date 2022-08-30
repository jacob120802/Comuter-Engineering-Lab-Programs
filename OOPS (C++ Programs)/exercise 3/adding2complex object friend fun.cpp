#include<iostream>
using namespace std;
class complex
{
	private:
		int real,imag;
	public:
		void input()
		{
			cout<<"Enter real and imag part= ";
			cin>>real>>imag;
		} 
		friend complex sum(complex &,complex &);
		void display();
};
void complex::display()
{
	cout<<"Sum of above 2 complex num = "<<real<<"+i"<<imag;
}
complex sum(complex &a,complex &b)
{
	complex t;
	t.real=a.real+b.real;
	t.imag=a.imag+b.imag;
	return t;
}
int main()
{
	complex a,b,c;
	a.input();
	cout << "For Second Complex numberC2:" << endl;
	b.input();
	cout << "Resultant Complex number C3:" << endl;
	c=sum(a,b);
	c.display();
	return 0;
}
          
