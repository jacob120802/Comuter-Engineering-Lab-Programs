#include<iostream>
#include<string.h>
using namespace std;
class student
{
	protected:
		char *name;
		int rollno, len;
	public:
		void getdetail(char x[], int y)
		{
			len=strlen(x);
			name=new char[len+1];
			strcpy(name,x);
			rollno=y;
		}
		void display()
		{
			cout<<"\n\nName:       "<<name<<endl;
			cout<<"Rollno:     "<<rollno<<endl;
		}
};
class test1: public virtual student
{
	protected:
		int s1, s2, s3;
	public:
		void getdata1()
		{
			cout<<"\n\nEnter the marks scored in 3 subjects (test1):\n";
			cin>>s1>>s2>>s3;
		}
		void display1()
		{
			cout<<"Marks stored in test 1";
			cout<<"\nSubject 1: "<<s1;
			cout<<"\nSubject 2: "<<s2;
			cout<<"\nSubject 3: "<<s3;
		}
		float total1()
		{
			return s1+s2+s3;
		}
};
class test2: public virtual student
{
	protected:
		int s4, s5, s6;
	public:
		void getdata2()
		{
			cout<<"\n\nEnter the marks scored in 3 subjects (test2):\n";
			cin>>s4>>s5>>s6;
		}
		void display2()
		{
			cout<<"\nMarks stored in test 2";
			cout<<"\nSubject 1: "<<s4;
			cout<<"\nSubject 2: "<<s5;
			cout<<"\nSubject 3: "<<s6;
		}
		float total2()
		{
			return s4+s5+s6;
		}
};
class result: public test1, public test2
{
	float per;
	public:
		void calper()
		{
			per=(total1()+total2())/6.0;
		}
		void show()
		{
			display();
			display1();
			display2();
			calper();
			cout<<"\nPercentage: "<<per<<"%"<<endl;
			if(per>=75)
				cout<<"\nDistinction!!\n";
			else if(per<75 && per>=60)
				cout<<"\nFirst Class!!\n";
			else if(per<60 && per>=40)
				cout<<"\nSecond Class!!\n";
			else
				cout<<"\nYou Failed!!\n";
		}
};
int main()
{
	result r;
	char x[20];
	int y;
	cout<<"Enter the student name: ";
	cin>>x;
	cout<<"Enter the roll number:  ";
	cin>>y;
	r.getdetail(x,y);
	r.getdata1();
	r.getdata2();
	r.show();
	return 0;
}
