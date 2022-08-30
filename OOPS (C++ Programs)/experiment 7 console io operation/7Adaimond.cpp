#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char a[] = "object";
    int n = strlen(a);
    cout.fill('*');

    for (int i = 0; i < n; i++)
    {
        cout.write(a, n-i);
        cout.width(2*i + 1);
        for (int j=n-i-1;j>=0;j--)
        	cout << a[j]; 
    	cout<<endl;
    }

    for (int i = n-2; i>=0; i--)
    {
        cout.write(a, n-i);
        cout.width(2*i + 1);
        for (int j=n-i-1;j>=0;j--)
        	cout << a[j]; 
    	cout<<endl;
    }
    return 0;
}