#include<iostream>
using namespace std;
class number
{
	private:
		int n;
	public:
		number()
        {
            n=0;    
        }
        number(int a)
        {
        	n=a;    
        }
        void display()
        {
            cout<<n<<endl;         
        }       
        friend number operator +(int &a,number &b);
        number operator *(number &a)
        {
            number temp;
            temp.n=n*a.n;
            return temp;    
        }
        number operator -(int &a)
        {
            number temp;
            temp.n=n-a;
            return temp;    
        }                                    
};
number operator +(int &a,number &b)
{
	number temp;
	temp.n=a+b.n;
	return temp;    
}
int main()
{
	number x;
	number y(10);
	int m=5;
	cout<<"Value of x is:";
	x.display();
	cout<<"Value of y is:";
	y.display();
	x=m+y;
	cout<<"x=5+y , x=";
	x.display();
	cout<<"x=x*y , x=";
	x=x*y;
	x.display();
	cout<<"x=y-5 , x=";
	x=y-m;
	x.display();
	return 0;     
}