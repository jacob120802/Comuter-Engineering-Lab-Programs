#include<iostream>
using namespace std;
class integer
{
	private:
		int i;
	public:
        integer(int n)  
        {
            i=n;     
        }
        void operator ++()  
        {
			cout<<"Prefix Addition: "<<++i<<endl;
		}
		void operator ++(int) 
		{
            cout<<"Postfix Addition: "<<i++<<endl;     
        }
        void operator --() 
        {
            cout<<"Prefix Subtraction: "<<--i<<endl;     
        }
        void operator --(int) 
        {
            cout<<"Postfix Subtraction: "<<i--<<endl;   
        }
        void display()
        {
            cout<<"New Value="<<i<<"\n";       
        }
};
int main ()
{
	int n;
	cout<<"Enter a value: ";
	cin>>n;           
	integer i1(n);
	cout<<"\nInitial Value: "<<n<<endl; // initial value display
	//unary increment prefix
	++i1;
	i1.display();
	//unary increment postfix
	i1++;
	i1.display();
	//unary decrement prefix
	--i1;
	i1.display();
	//unary decrement postfix
	i1--;
	i1.display();
	return 0;
}