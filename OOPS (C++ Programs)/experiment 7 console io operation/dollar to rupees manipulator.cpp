#include<iostream>
#include<iomanip>

using namespace std;

ostream & dollar(ostream & op)
{
int i;
float rupees;
op<<"$=";
rupees=float(i)*74.52;
op<<setiosflags(ios::showpos);
op<<rupees;
op<<resetiosflags(ios::showpos);
op<<" rs";
return op;
}

int main()
{
	int i;
	for(i=1;i<=2;i++)
	{
	cout<<i<<dollar<<endl;	
	}
	return 0;
}
