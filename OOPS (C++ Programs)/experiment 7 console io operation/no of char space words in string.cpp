#include <iostream>
using namespace std;
int main()
{
	char c;
	int spaces=0;
	int characters=0;
	int lines=0;
	int words=0;
	cout<<"Enter a paragraph.(In NextLine Press # and Enter to terminate):\n";
	while(c!='#')
	{
		c=cin.get();
		if(c=='\n')
			lines+=1;
		if(c==' ')
			spaces+=1;
		if (c==' '||c=='\n')
			words+=1;
		else
		characters+=1;
	}
	cout.width(25);
	cout.setf(ios::left,ios::adjustfield);
	cout<<"1. Number of lines";
	cout.width(10);
	cout.setf(ios::right,ios::adjustfield);
	cout<<lines<<endl;
	
	cout.width(25);
	cout.setf(ios::left,ios::adjustfield);
	cout<<"2. Number of spaces";
	cout.width(10);
	cout.setf(ios::right,ios::adjustfield);
	cout<<spaces<<endl;
	
	cout.width(25);
	cout.setf(ios::left,ios::adjustfield);
	cout<<"3. Number of characters";
	cout.width(10);
	cout.setf(ios::right,ios::adjustfield);
	cout<<characters-1<<endl;
	
	cout.width(25);
	cout.setf(ios::left,ios::adjustfield);
	cout<<"4. Number of words";
	cout.width(10);
	cout.setf(ios::right,ios::adjustfield);
	cout<<words<<endl;
}