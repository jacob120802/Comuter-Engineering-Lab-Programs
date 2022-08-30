//function template(generic function for different data type)
#include<iostream>
using namespace std;
template<class T>     // template declaration for fun swap()
void swap1(T & x, T & y)
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}
int main()
{
	int a,b;
	cout<<"\nEnter int elements to swap\n";
	cin>>a>>b;
	swap1(a,b);
	cout<<"\nInt Elements after swapping :"<<a<<" "<<b;
	
	float c,d;
	cout<<"\n\nEnter float elements to swap\n";
	cin>>c>>d;
	swap1(c,d);
	cout<<"\nFloat Elements after swapping : "<<c<<" "<<d;
	
	char e,f;
	cout<<"\n\nEnter char elements to swap\n";
	cin>>e>>f;
	swap1(e,f);
	cout<<"\nchar Elements after swapping : "<<e<<" "<<f;
	return 0;
}
