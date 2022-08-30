#include<iostream>
using namespace std;
class object
{
    int value;
    public:
    object()
	{
        value=0;
    }
    object(int v)
	{
        value=v;
    }
    friend istream & operator >>( istream &s, object &v)
	{
        s>>v.value;
        return s;
    }
    friend ostream & operator <<( ostream &s, object &v)
	{
        s<<v.value;
        return s;
    }
};
int main()
{
    object o1, o2;
    cout<<"\nEnter value stored by object 1: ";
    cin>>o1;
    cout<<"\nEnter value stored by object 2: ";
    cin>>o2;
    cout<<"\nValue stored by object 1: "<<o1<<endl;
    cout<<"Value stored by object 2: "<<o2<<endl;
    return 0;
}