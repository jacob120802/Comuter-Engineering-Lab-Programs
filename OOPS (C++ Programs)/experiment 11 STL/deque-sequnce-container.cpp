//Dequeu Sequence Container
#include<iostream>
#include<deque>
using namespace std;
void display(deque <double> &);	// display function prototype
int main()
{
	deque <double> d;

	//insert elements in d
	d.push_front(2.2);
	d.push_front(3.5); 
	d.push_back(1.1);  // 3.5 2.2 1.1

	cout<<"\n\nDeque elements after insertion are as follows :";
	display(d);

	//pop_front() to remove front element
	d.pop_front();		// d.pop_back();

	cout<<"\n\nDeque elements after pop_front() are as follows :";
	display(d);

	//using [] subsricpt operator to modify elements
	d[1]=3.3;	// 1.1 gets overwritten by 3.3

	cout<<"\n\nDeque elements after subscript insertion using [] are as follows :";
	display(d);

	return 0;
}
void display(deque <double> & d1)
{
	for(int i=0;i<d1.size();i++)
	{
		cout<<" "<<d1[i];
	}
}
