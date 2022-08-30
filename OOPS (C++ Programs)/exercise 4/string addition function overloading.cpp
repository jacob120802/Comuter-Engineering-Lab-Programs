#include<iostream>
#include<cstring>
using namespace std;
class String
{
	int len;
	char arr[30];
	public:
		String()
		{
			len = 0;
			strcpy(arr,"\0");
		}
		String(char a[30])
		{
			len = strlen(a);
			strcpy(arr,a);
		}
		friend void operator << (ostream &x, String &y)
		{
			x << y.arr;
		}
		friend void operator >> (istream &x, String &y)
		{
			x >> y.arr;
		}
		String operator + (String &x)
		{
			String s;
			s.len = len + x.len;
			strcpy(s.arr,arr);
			strcat(s.arr," ");
			strcat(s.arr,x.arr);
			return s;
		}
};
int main()
{
	//CREATE UNINITIALIZED STRING OBJECTS
	String s1,s2,s3;
	
	//CREATE OBJECTS WITH STRING CONSTANTS
	String s4("New Delhi");	

	cout << "String 4 is initialized to ";
	cout << s4;
	
	cout << "\nEnter two strings:";
	cin >> s1;
	cin >> s2;
	
	//CONCATENATES TWO STRINGS PROPERLY
	cout << "The concatenated string s3 is:";
	s3 = s1 + s2;
	
	//DISPLAY A DESIRED STRING OBJECT
	cout << s3;
	cout << endl;
}

