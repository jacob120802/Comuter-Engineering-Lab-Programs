#include <iostream>
using namespace std;
class student
{
  private:
        int   rollno;
        char  name[50], branch[50];
        float subject1, subject2, subject3, total, avg;
  public:
    void readDetails()
	{
      cout << "Enter Roll number: ";
      cin >> rollno;
      cout << "Enter Name: ";
      cin >> name;
      cout << "Enter Branch: ";
      cin >> branch;
      cout << "Enter Marks of 3 Subjects: ";
   	  cin >> subject1 >> subject2 >> subject3;
   	  total = subject1 + subject2 + subject3;
   	  avg = total/3;
    }
    void printDetails();
};
void student::printDetails()
{
	cout << "RollNo = " << rollno;
      cout << ",\tName = " << name;
      cout << ",\tBranch = " << branch;
   	  cout << ",\tPercentage = " << avg;  
}
int main()
{
    student std[50];    
    int n, i;
    cout << "Enter total number of students: ";
    cin >> n;
    for(i=0; i<n; i++)
	{
        cout << "Enter details of student " << i+1 << ":\n";
        std[i].readDetails();
    }
    for(i=0; i<n; i++)
	{
        cout << "\nDetails of student " << i+1 << ":\n";
        std[i].printDetails();
    }
    return 0;
}
