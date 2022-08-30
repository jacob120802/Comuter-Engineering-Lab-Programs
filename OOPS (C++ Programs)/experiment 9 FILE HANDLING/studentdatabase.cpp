#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void add()
{
    string name,branch,ad;
    int roll;
    cin.ignore();
    cout<<"Enter Name of student:\n";
    getline(cin,name);
    ofstream out;
    out.open(name);
    out<<name<<"\n";
    cout<<"Address:\n";
    getline(cin,ad);
    out<<ad<<"\n";
    cout<<"Branch:\n";
    getline(cin,branch);
    out<<branch<<"\n";
    cout<<"RollNo:\n";
    cin>>roll;
    out<<roll;
    out.close();
}
void update()
{
    string s,name,ad,branch;
    int roll;
    cin.ignore();
    cout<<"Enter Name of Student:\n";
    getline(cin,name);
    ofstream out;
    out.open(name);
    cout<<"Enter Updated Details:\n";
    out<<name<<"\n";
    cout<<"Address:\n";
    getline(cin,ad);
    out<<ad<<"\n";
    cout<<"Branch:\n";
    getline(cin,branch);
    out<<branch<<"\n";
    cout<<"RollNo:\n";
    cin>>roll;
    out<<roll;
    out.close();
}
void Search()
{
    string s,name,ad,branch;
    int roll;
    ifstream in;
    cin.ignore();
    cout<<"Enter Name of Student:\n";
    getline(cin,s);
    in.open(s);
    if(!in.is_open())
	  {	
		  cout<<"not present"<<endl;
		  return;
	  }
    getline(in,name);
    getline(in,ad);
    getline(in,branch);
    in>>roll;
    cout<<"\nStudent Details:\n\nName : "<<name<<"\nRollNo : "<<roll;
    cout<<"\nBranch : "<<branch<<" \nAddress : "<<ad<<endl;
    in.close();
}
int main()
{
    int ch;
    do
    {
        cout<<"\n 1-Add to Record\n 2-Search Details\n 3-Update Record\n 4-Exit \n";
        cin>>ch;
        switch(ch)
        {
            case 1:
				add();
				break;
            case 2:
				Search();
				break;
            case 3:
				update();
				break;
            case 4:
				exit(1);
            default:cout<<"Invalid input!\n";
        }
    }while(ch);
    return 0;
}
