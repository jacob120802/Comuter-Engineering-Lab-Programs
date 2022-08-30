#include<iostream>
using namespace std;
int n=0;
class destroy
{
    int num;
public:
    destroy()
	{
        num=0;
        n++;
    }

    void getdata()
	{
        cout<<"Enter a number: ";
        cin>>num;
    }
    void display()
	{
        cout<<"Number you stored in object "<<n<<" is : "<<num<<endl;

    }
    ~destroy()
	{
        cout<<"Object "<<n<<" got destroyed"<<endl;
        n--;
    }
};
int main()
{
    cout<<"In main"<<endl;
    destroy d1;
    d1.getdata();
    d1.display();
    {
        cout<<"In block1"<<endl;
        destroy d2;
        d2.getdata();
        d2.display();
        {
            cout<<"In block2"<<endl;
            destroy d3;
            d3.getdata();
            d3.display();
            {
                cout<<"In block3"<<endl;
                destroy d4;
                d4.getdata();
                d4.display();
                {
                    cout<<"In block4"<<endl;
                    destroy d5;
                    d5.getdata();
                    d5.display();
                }
            }
        }
    }
    return 0;
}