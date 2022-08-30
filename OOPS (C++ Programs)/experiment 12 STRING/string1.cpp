#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1="Good morning ";
	string s2("Good morning goa");
	string s3=s1+s2;
	cout<<"s1: "<<s1<<"\ts2: "<<s2<<"\n";
	cout<<"s1 + s2 = s3\n"<<"s3: "<<s3;
	
	cout<<"\n\n-----------------------------------\n";
	
	int m = s1.compare( s2 );
	cout<<"\nResult of comparision between strings s1 and s2: "<<m<<endl;
	if(s1==s2)
		cout<<"s1 is the same as s2\n";
	else if(s1>s2)
		cout<<"s1 greater than s2\n";
	else
		cout<<"s2 is greater than s1\n";
		
	cout<<"\n-------------------------------------\n";
	
	cout<<"\nSubstring of s1:"<<s1.substr(6, 3)<<endl;
	int g=s1.find("nin");
	cout<<"First occurance of Substring 'nin' found at index "<<g<<" in s1\n";
	int k=s3.rfind('n');
	cout<<"Last occurrence of character 'n' in s3 is at index:"<<k<<endl;
	
	cout<<"\n-------------------------------------\n";
	
	cout<<"\nCurrently,\ns2:"<<s2<<"\ts3:"<<s3<<endl;
	s2.swap(s3);
	cout<<"\nAfter swapping,\ns2:"<<s2<<"\ts3:"<<s3<<endl;
	return 0;
}
