#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	cout<<"Enter a string:";
	getline(cin, s1);
	string::iterator iter=s1.begin();
	cout<<"\nThe string:\n";
	while(iter!=s1.end())
	{
		cout<<*iter;
		iter++;
	}
	cout<<"\n\nString in reverse:\n";
	string::reverse_iterator r_iter=s1.rbegin();
	while(r_iter!=s1.rend())
	{
		cout<<*r_iter;
		r_iter++;
	}
	return 0;
}
