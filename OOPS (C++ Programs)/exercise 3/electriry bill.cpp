#include<iostream> 
#include<conio.h> 
using namespace std;
class electric
{
	int no_unit; 
	float charge,scharge; 
	char name[20]; 
	public:
		void input()
        {
                cout<<"\nEnter Name: ";
                cin>>name;
                cout<<"No. Of Units Consumed: ";
                cin>>no_unit;
        }
        void print_bill()
		{
			if(no_unit<=100)     
				charge=(0.60*no_unit); 
			else if(no_unit>100&&no_unit<=300)   
			{      
				charge=(100*0.60);      
				charge+=((no_unit-100)*0.80);    
			} 
			else if(no_unit>=300)   
			{     
				charge=(100*0.60);     	
				charge+=(200*0.80);     
				charge+=((no_unit-300)*0.90);   
			} 
			if(charge<50)     
				charge=50; 
			if(charge>300)  
			{    
				scharge=(0.15*charge);      
				charge+=scharge;  
			} 
			cout<<"\n"; cout<<name<<"  -\tBill= Rs"<<charge; 
		}	
};
int main() 
{ 
	electric e[10];
    int i,cnt;
    cout<<"Enter no. of Customers: ";
    cin>>cnt;
    for(i=0; i<cnt; i++)
        e[i].input();
    cout<<"\n  ELECTRICITY BILL LIST";
    for(i=0; i<cnt; i++)
        e[i].print_bill();
	return 0; 
}