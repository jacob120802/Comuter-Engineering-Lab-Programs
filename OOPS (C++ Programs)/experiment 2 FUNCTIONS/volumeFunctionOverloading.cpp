#include<iostream>
using namespace std;
const float pi=3.14;
float vol(float l) //Cube
{
	return l*l*l;
}
float vol(float r,float h) //Cylinder
{
	return (pi*r*r*h);
}
float vol(float l,float b,float h)//rectangular box
{
	return (l*b*h);
}
int main()
{
	float l,r,b,h,t;
	cout<<"Enter the Length of Cube: \n";
	cin>>l;
	t=vol(l);
	cout<<"Volume of Cube: "<<t;
	cout<<"\n\nEnter the Radius & Hieght of Cylinder: \n";
	cin>>r>>h;
	t=vol(r,h);
	cout<<"Volume of Cylinder: "<<t;
	cout<<"\n\nEnter the Length,Breadth & Hieght of Rectangle: \n";
	cin>>l>>b>>h;
	t=vol(l,b,h);
	cout<<"Volume of Rectangle: "<<t;
	return 0;
}