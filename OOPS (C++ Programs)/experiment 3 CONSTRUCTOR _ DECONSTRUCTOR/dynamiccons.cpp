#include <iostream>
#include <string.h>
using namespace std;
class Name
{
	char *n;
	int len;

public:
	Name(char studentname[]) // dynamic constructor
	{
		len = strlen(studentname);
		n = new char[len + 1]; // 1) dynamically allocated in cons
		strcpy(n, studentname);
	}
	void display()
	{
		cout << "The name of the student is " << n;
	}
};

int main()
{
	int len;
	char studentname[30];
	cout << "Enter student name:";
	cin >> studentname;
	Name n1(studentname);
	n1.display();
}
