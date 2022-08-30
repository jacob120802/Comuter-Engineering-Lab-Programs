#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main()
{
	float arr[4];
	int n=4,i=0;
	ofstream fout;
	ifstream fin;
	cout << "Enter the elements:" << endl;
	for(i=0;i<n;i++)
		cin >> arr[i];
	fout.open("File.txt");
	fout.write((char *)&arr,sizeof(arr));	//Writing arr[] to File.txt using write() function
	fout.close();
	
	for(i=0;i<n;i++)
		arr[i] = 0;
	
	fin.open("File.txt");
	fin.read((char *)&arr,sizeof(arr));		//Reading from File.txt using read() function
	fin.close();
	cout << "The elements in the array arr are:" << endl;
	cout << "[ ";
	for(i=0;i<n;i++)
	{
		cout << setprecision(3) << arr[i] << " ";
	}
	cout << "]" << endl;
	
	return 0;
}
