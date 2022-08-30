#include<iostream>
using namespace std;
class vector
{
    int*v;
    int size;
    public:
    vector()
	{
        size=0;
        v=new int[size+1];
    }
    vector(int n)
	{
        size=n;
        v=new int[size+1];
    }
    void get_elements()
	{
        for(int i=0;i<size;i++)
		{
            cin>>v[i];
        }
    }
    void display()
	{
        for(int i=0;i<size;i++)
		{
            cout<<v[i]<<" ";
            
        }
        cout<<endl;
    }
    friend void operator *(int n, vector &a)
	{
        for(int i=0;i<a.size;i++)
		{
            a.v[i]=n*a.v[i];
        }
    }
    vector operator +(vector &a)
	{
        vector temp;
        temp.size=size;
        for(int i=0;i<a.size;i++)
		{
            temp.v[i]=v[i]+a.v[i];
        }
        return temp;
    }
};
int main()
{
    vector v1, v2, v3;
    int n, s;
    cout<<"Enter size of vector: ";
    cin>>n;
    v1=(n);
    cout<<"\nEnter elements of vector 1:"<<endl;
    v1.get_elements();
    cout<<"Enter the scalar value to multiply with vector 1: ";
    cin>>s;
    s*v1;
    cout<<"\nAfter multiplication by "<<s<<" the elements of vector 1 are:"<<endl;
    v1.display();
    v2=(n);
    cout<<"\nEnter elements of vector 2:"<<endl;
    v2.get_elements();
    v3=v1+v2;
    cout<<"\nElements of resultant vector after addition of vector 1 and 2 are: "<<endl;
    v3.display();
    cout<<"\n";
    return 0;
}