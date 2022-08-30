#include<iostream>
#define MAX 30
using namespace std;
class media
{
	protected:
		char m_name[10];
		int sr_no;
		int price;
	public:
		virtual void getdata() = 0;
		virtual void display() = 0;	//pure virtual
};
class book:virtual protected media
{
	protected:
		int yr_pub;
		char pub_name[MAX];
	public:
		void getdata()
		{
			strcpy(m_name,"Book");
			cout<<"\nEnter media name:";
			cin>>m_name;
			cout<<"Enter serial number:";
			cin>>sr_no;
			cout<<"Enter price:";
			cin>>price;
			cout<<"Enter year of publication:";
			cin>>yr_pub;
			cout<<"Enter publisher name:";
			cin>>pub_name;
		}
		void display()
		{
			cout<<"\nMedia Name:"<<m_name<<endl;
			cout<<"Serial Number:"<<sr_no<<endl;
			cout<<"Price:"<<price<<endl;
			cout<<"Year of publication:"<<yr_pub<<endl;
			cout<<"Publisher Name:"<<pub_name<<endl;	
		}
			
};
class tape:virtual protected media
{
	protected:
		int tape_capacity;
		char manufacturer_name[MAX];
	public:
		void getdata()
		{
			strcpy(m_name,"Tape");
			cout<<"\nEnter serial number:";
			cin>>sr_no;
			cout<<"Enter price:";
			cin>>price;
			cout<<"Enter tape capacity:";
			cin>>tape_capacity;
			cout<<"Enter Manufacturer name:";
			cin>>manufacturer_name;
		}
		void display()
		{
			cout<<"\nMedia Name:"<<m_name<<endl;
			cout<<"Serial Number:"<<sr_no<<endl;
			cout<<"Price:"<<price<<endl;
			cout<<"Tape Capacity:"<<tape_capacity<<endl;
			cout<<"Manufacturer Name:"<<manufacturer_name<<endl;	
		}		
};
int main()
{	
	//media *mptr;
	int i;
	int books,tapes;
	cout<<"Enter number of books:";
	cin>>books;
	cout<<"Enter number of tapes:";
	cin>>tapes;
	book *b=new book[books];
	tape *t=new tape[tapes];
	cout << "\nEnter Books Details \n";
	for(i=0;i<books;i++)
	{
		b[i].getdata();
	}
	cout << "\n Enter Tape Details\n";
	for(i=0;i<tapes;i++)
	{
		t[i].getdata();
	}
	cout << "\n MEDIA DETAILS";
	cout<<"\n\t|BOOK DETAILS|\n";
	for(i=0;i<books;i++)
	{
		b[i].display();	
	}
	cout<<"\n\t|TAPE DETAILS|\n";
	for(i=0;i<tapes;i++)
	{
		t[i].display();
	}
	return 0;
}
