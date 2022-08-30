#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int main()
{
	string s1("good morning,");
	string s2("good morning goa");
    string s=s1+s2; cout<<s;
	int r = s1.compare(s2);
	cout<<"\nresult : "<<r;
	cout<<"\n\n----------------------------------";
	if(s1==s2)
		cout<<"\nsame";
	else if(s1>s2)
		cout<<"\ns1 greater:";
	else
		cout<<"\ns2 greater:";
	cout<<"\n\n----------------------------------";
	int p = s1.compare(0,11,s2,0,15);
	cout<<" \n p = "<<p;
	cout<<"\n\n----------------------------------";
	cout<<"\n substring of s1 = "<<s1.substr(0,4);

	string f1("first");
	string f2("second");

	f1.swap(f2);

	cout<<"\n f1 = "<<f1<<" f2 = "<<f2;
	cout<<"\n\n----------------------------------";
	string s3("se computer");

	//string s4;
	cout<<"\n size() = "<<s3.size();
	cout<<"\n length() = "<<s3.length();
	cout<<"\n max_size() = "<<s3.max_size();
	cout<<"\n capacity() = "<<s3.capacity();
	cout<<"\n empty() = "<<s3.empty();
	cout<<"\n\n----------------------------------";

	cout<<"\n find(e) = "<<s3.find("e");
	cout<<"\n rfind(e) = "<<s3.rfind("e");

	cout<<"\n\n----------------------------------";
	int q = s3.find_first_of("e");
	cout<<" \nfind_first_of = "<<q;


	cout<<"\n\n----------------------------------";
	int q1 = s3.find_last_of("e");
	cout<<" \nfind_last_of = "<<q1;

	cout<<"\n\n----------------------------------";
	int q2 = s3.find_first_not_of("uter");
	cout<<" \nfind_first_not_of = "<<q2;

	cout<<"\n\n----------------------------------";

	s3.replace(0,2,"TE");
	cout<<"\nafter replacement : "<<s3;

	cout<<"\n\n----------------------------------";
	string t1("beginning end");
	string t2("middle");

	t1.insert(13,"hi",0,string::npos);
	cout<<"\nafter inserting :"<<t1;

	cout<<"\n\n----------------------------------";

	string r1("logic");
	char *ptr = 0;

	int len = r1.length();

	ptr = new char [len+1];

	r1.copy(ptr,len);
	ptr[len]='\0';

	cout<<"\n copied ptr = "<<ptr;
	cout<<"\n c_str() = "<<r1.c_str();

	
	getch();
	return 0;
}
