#include<iostream>  
using namespace std;    
void swap(int &x, int &y)  
{  
	int temp;  
	temp = x;  
	x = y;  
	y = temp;  
}  
int main()   
{    
	int a,b;
	cout << "Enter two numbers A & B: ";
    cin >> a >> b;
    cout << "\nValue of A before swapping: " << a <<endl;
    cout << "Value of B before swapping: " << b <<endl;
    swap(a,b);
    cout << "\nValue of A after swapping: " << a <<endl;
    cout << "Value of B after swapping: " << b <<endl;
 return 0;  
}    