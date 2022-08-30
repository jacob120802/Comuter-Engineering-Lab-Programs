#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int main()
{
	string s1("Testing Iterators");

	//string::forward_iterator i1 = s1.rend();
	
	string::reverse_iterator i1 = s1.rbegin();
	while(i1 != s1.rend())
	{
		cout<<*i1;
		++i1;
	}

	getch();
	return 0;
}
