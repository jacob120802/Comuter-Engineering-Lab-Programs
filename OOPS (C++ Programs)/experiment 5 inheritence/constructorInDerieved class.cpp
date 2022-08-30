#include<iostream>
using namespace std;
class alpha
{
	int x;
	public:
		alpha(int i)
		{
			x=i;
			cout<<"\nAlpha class Initialized";
		}
		void show_x()
		{
			cout<<"\nx = "<<x;
		}
};
class beta
{
	float y;
	public:
		beta(float j)
		{
			y=j;
			cout<<"Beta class Initialized";
		}
		void show_y()
		{
			cout<<"\ny = "<<y;
		}
};
class gamma:public beta, public alpha
{
	int m,n;
	public:
		gamma(int a, float b, int c, int d):alpha(a), beta(b)//initialization list
		{
			m=c;
			n=d;
			cout<<"\nGamma class Initialized";
		}
		void show_mn()
		{
			cout<<"\n m = "<<m;
			cout<<"\n n = "<<n;
		}
};
int main()
{
	gamma g(10, 10.5, 11, 12);
	g.show_x();
	g.show_y();
	g.show_mn();
	return 0;
}