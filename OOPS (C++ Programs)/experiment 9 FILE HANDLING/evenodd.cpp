#include <iostream>
#include<fstream>
using namespace std;
int main() 
{
  int arr[10], i,even[10],odd[10],evncnt=0,oddcnt=0;
  cout<<"\nEnter the elements in array: \n";
    for(i=0;i<10;i++)
    {
        cout<<"Enter the number "<<i+1<<": ";
        cin>>arr[i];
    }
    for(i=0;i<10;i++)
    {
            if(arr[i]%2==0)
                even[evncnt++]=arr[i];
            else 
                odd[oddcnt++]=arr[i];
    }
  ofstream oddOut("odd.txt"),evenOut("even.txt");

    for(int i=0;i<evncnt;i++)
        evenOut << even[i] << " ";

    for(int i=0;i<oddcnt;i++)
        oddOut << odd[i] << " ";

    evenOut.close();
    oddOut.close();
  }