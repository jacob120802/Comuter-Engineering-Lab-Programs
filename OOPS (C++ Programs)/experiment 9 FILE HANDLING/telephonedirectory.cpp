#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class contact
{
	public:
		long int number;
		string name;
		void getdata()
		{
			cout<<"Enter name:\n";
			getline(cin,name);
			cout<<"Enter Phone Number:\n";
			cin>>number;
		}
		void display()
		{
			cout<<"Name : "<<name<<"Phone No : "<<number<<endl;
		}
		
};

void search(int n,contact a[])
{
	string s;
	cin.ignore();
	cout<<"Enter name to Search:\n";
	getline(cin,s);
	
	ifstream fin;
	fin.open("Contacts.txt");
	int i;
	for(i=0;i<n;i++)
	{
		fin.read((char*)&a[i],sizeof(a[i]));
		if(a[i].name==s)
		{
			cout<<"Name : "<<a[i].name<<"\t Phone No : "<<a[i].number<<endl;break;
		}
	}
	if(i==n)
	{
		cout<<"Not present\n";
	}
}

void update(int n,contact a[])
{
	string s;
	cin.ignore();
	cout<<"Enter Name to Search & Update Details:\n";
	getline(cin,s);
	
	ifstream fin;
	fin.open("Contacts.txt");
	int i;
	for(i=0;i<n;i++)
	{
		fin.read((char*)&a[i],sizeof(a[i]));
		if(a[i].name==s)
		{
			cout<<"Enter new name to update:\n";
			getline(cin,a[i].name);
			cout<<"Enter new phone number to update:\n";
			cin>>a[i].number;
			break;
		}
	}
	if(i==n)
	{
		cout<<"Not present\n";
	}
	fin.close();
	
	ofstream fout;
	fout.open("Contacts.txt");
	for(i=0;i<n;i++)
	{
		fout.write((char*)&a[i],sizeof(a[i]));
	}
	fout.close();
}
int main()
{
	int n;
	cout<<"Enter number of contacts to create in Phonebook:\n";
	cin>>n;
	
	contact a[n];
	
	ofstream fout;
	fout.open("Contacts.txt");	
	for(int i=0;i<n;i++)
	{
		cin.ignore();
		a[i].getdata();
		fout.write((char*)&a[i],sizeof(a[i]));
	}
	fout.close();
	
	int ch;
	do
	{
		cout<<" 1-Search\n 2-Update Contact\n 3-Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				search(n,a);
				break;
			case 2:
				update(n,a);
				break;
			case 3:
				exit(1);
			default:cout<<"Invalid input.\n";
		}	
	}while(ch);
	return 0;
}