//Standard Library queue adapter class 
#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue <double> q;	// double type queue "q" created (initially empty)

	//push elements onto queue
	q.push(1.1);				// 1.1  2.2  3.3
	q.push(2.2);
	q.push(3.3);

	cout<<"\n\nPopping elements from queue : ";
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}