#include<iostream>
using namespace std;
class Customer
{
	int acno;	
	char name[25];
	float balance;
	int transaction;
	public:
		void input(int acc);
		int deposit(int acc);
		int withdraw(int acc);
		int getbalance(int acc);
};
void Customer::input(int acc)
{
	acno=acc;
	cout<<"A/C number generated for the customer: "<<acno<<endl;
	cout<<"Name of Account Holder: ";getchar();
	gets(name);
	ip:
		cout<<"Enter the amount to be deposited: ";
		cin>>balance;
		if(balance<500)
		{
			cout<<"\nMinimum balance of Rs 500 mandatory\n\n";
			goto ip;
		}
	transaction=0;
	cout<<endl;
}
int Customer::deposit(int acc)
{
	if(acno==acc)
	{
		float amt;
		cout<<"\nHow much money do you want to Deposit: ";
		cin>>amt;
		balance+=amt;
		transaction++;
		cout<<"\t\tRS "<<amt<<" DEPOSITED SUCESFULLY!\n";
		return 1;
	}
	return 0;
}
int Customer::withdraw(int acc)
{
	if(acno==acc)
	{
		float amt;
		with:
			cout<<"\nHow much money do you want to withdraw: ";
			cin>>amt;
			if(balance-amt<500)
			{
				cout<<"\n\t\tWITHDRAWAL DECLINED!\nCurrent Account Balance will become less than mandotory minimum balance of Rs 500\n\n";
				goto with;
			}
		balance-=amt;
		transaction++;
		cout<<"\t\tRS "<<amt<<" WITHDRAWAL SUCESSFUL!\n";
		return 1;
	}
	return 0;
}
int Customer::getbalance(int acc)
{
	if(acno==acc)
	{
		cout<<"\nHello, "<<name;
		cout<<"\nBalance in your A/C is RS "<<balance;
		cout<<"\nNo. of Transactions: "<<transaction;
		return 1;
	}
	return 0;
}
int main()
{
	Customer* x;
	int i, n, ch, ac, acno=10001, flag;
	cout<<"Enter the no. of customers: ";
	cin>>n;
	x=new Customer[n];
	cout<<"\nEnter the details of Customers \n\n";
	for(i=0;i<n;i++)
	{
		x[i].input(acno);
		acno++;
	}
	do
	{
		
		cout<<"\t\tMenu\n\n";
		cout<<"Enter 1 to Deposit\n";
		cout<<"Enter 2 to Withdraw\n";
		cout<<"Enter 3 to Check Balance\n";
		cout<<"Enter 4 to Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<">>>Deposit\n\n";
				cout<<"Enter the A/C Number: ";
				cin>>ac;
				for(i=0;i<n;i++)
				{
					flag=x[i].deposit(ac);
					if(flag==1)
						break;
				}
				if(flag==0)
				{
					cout<<"\t\tINVALID ACCOUNT!\n";
				}
				break;
			case 2:
				cout<<">>>Withdraw\n\n";
				cout<<"Enter the A/C Number: ";
				cin>>ac;
				for(i=0;i<n;i++)
				{
					flag=x[i].withdraw(ac);
					if(flag==1)
						break;
				}
				if(flag==0)
				{
					cout<<"\t\tINVALID ACCOUNT!\n";
				}
				break;
			case 3:
				cout<<">>>Balance\n\n";
				cout<<"Enter the A/C Number: ";
				cin>>ac;
				for(i=0;i<n;i++)
				{
					flag=x[i].getbalance(ac);
					if(flag==1)
						break;
				}
				if(flag==0)
				{
					cout<<"\t\tINVALID ACCOUNT\n";
				}
				break;
			case 4:
				break;
			default:
				printf("INVALID CHOICE!\n");
		}
	}while(ch!=4);
	delete[] x;
	return 0;
}
