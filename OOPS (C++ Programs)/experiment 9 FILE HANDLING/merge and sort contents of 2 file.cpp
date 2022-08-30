#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("File_1.txt");
    int element,i,j,temp;
    cout<<"Enter elements of files 1: ";
    for(i=1;i<=5;i++)
    {
        cin>>element;
        fout<<element<<" ";
    }
    fout.close();

    fout.open("File_2.txt");
    cout<<"Enter elements of files 2: ";
    for(i=1;i<=3;i++)
    {
        cin>>element;
        fout<<element<<" ";
    }
    fout.close();

    ifstream fin;
    fin.open("File_1.txt");
    int arr[8];
    i=0;
    while(!fin.eof())
    {
        fin>>arr[i];
        fin.get();
        i++;
    }
    i--;
    fin.close();

    fin.open("File_2.txt");
    while(!fin.eof())
    {
        fin>>arr[i];
        fin.get();
        i++;
    }
    fin.close();

    for(i=0;i<8;i++)
    {
        for(j=i+1;j<8;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    fout.open("File_3.txt");
    cout<<"Sorted Merged Data: ";
    fout<<"Sorted Merged Data: ";
    for(i=0;i<8;i++)
    {
    	fout<<arr[i]<<" ";
		cout<<arr[i]<<" ";
	}
	fout.close();
}
