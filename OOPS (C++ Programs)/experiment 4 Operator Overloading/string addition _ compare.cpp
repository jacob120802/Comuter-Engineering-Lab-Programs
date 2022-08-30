#include<iostream>
#include<string.h>
using namespace std;
class st
{
    char *s;
    int len;
    public:
    void display()
	{
        cout<<s;
    }
    st()
	{
        len=0;
        s=new char[len+1];
    }
    st(const char*str)
	{
        len=strlen(str);
        s=new char[len+1];
        strcpy(s,str);
    }
    st operator +(st &stg)
	{
        st temp;
        temp.len=len+stg.len;
        temp.s=new char[temp.len+1];
        strcpy(temp.s,s);
        strcat(temp.s,stg.s);
        return temp;
    }
    int operator >=(st &stg)
	{
        if(len>stg.len)
            return 1;
        else
            return 0;
    }
};
int main()
{
    st s1, s2, s3;
    s2="Computer";
    s3="Engineering";
    s1=s2+s3;
    s1.display();
    cout<<endl;
    if(s2>=s3)
	{
        s3.display();
    }
    else    
        s2.display();
    return 0;
}