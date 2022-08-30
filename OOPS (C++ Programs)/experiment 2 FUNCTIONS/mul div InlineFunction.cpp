#include<iostream>
using namespace std;
inline float mul(float a, float b)
{
	return(a*b);
}
inline float div(float c, float d)
{
	return(c/d);
}
int main()
{
	float x, y;
	cout<<"Enter the value x & y: ";
	cin>>x>>y;
	cout<<"\n Multiplication= "<<mul(x,y);
	cout<<"\n Division= ";
	cout<<div(x,y);
	return 0;
}