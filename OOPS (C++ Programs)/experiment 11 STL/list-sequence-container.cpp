//List sequence Container
#include<iostream>
#include<list>  //linear linked list
using namespace std;
void display(list <int> &);	// display function prototype
int main()
{
	list <int> list1;		//empty list1 of zero length
	list <int> list2;		//empty list2 
	list <int> list3;

	cout<<"\n\nsize of list1 = "<<list1.size();
	
	list1.push_front(2);	
	list1.push_front(1);
	list1.push_back(3);
	list1.push_back(4);  //1234
	cout<<"\n\nList1 elements after push_front() and push_back() :";
	display(list1);

	//Remove an element from front end
	list1.pop_front();		// same way pop_back()
	cout<<"\n\nAfter removing front element of list1 : ";
	display(list1); //234

	//insert an element(1) at the begining of list1
	list1.insert(list1.begin(),1);
	cout<<"\n\nAfter inserting an element at begining of list1 : ";
	display(list1); //1234

	// pushing elements in list2
	list2.push_front(5);	
	list2.push_front(6);
	list2.push_back(9);
	list2.push_back(8);
	list2.push_back(7);  // 65987
	cout<<"\n\nList2 elements after push_front() and push_back() :";
	display(list2);

	//sorting list2 elements
	list2.sort();
	cout<<"\n\nList2 elements after sorting :";
	display(list2);  //56789

	//splice(insert) the elements of list2 at the end of list1
	list1.splice(list1.end(),list2);	// similarly splice could be at begin() also 
	cout<<"\n\nList1 elements after splicing :";
	display(list1);  //123456789

	//merging list1 contents into list3
	list3.merge(list1);
	cout<<"\n\nList3 elements after merging :";
	display(list3);

	//reverse a list
	list3.reverse();
	cout<<"\n\nList3 elements after reversing :";
	display(list3);

	list3.push_back(9);
	list3.push_back(9);
	cout<<"\n\nUpdated list3 elements :";
	display(list3);

	//Removing duplicates from list3 elements
	list3.unique();
	cout<<"\n\nAfter removing duplicates from list3 elements are :";
	display(list3);

	//remove all 9's from list3
	list3.remove(9);
	cout<<"\n\nAfter removing all 9's from list3 elements :";
	display(list3);

	//using swap() function
	list2.swap(list3);
	cout<<"\n\nAfter swapping list2 : ";
	display(list2);
	cout<<"\n\nAfter swapping list3 : ";
	display(list3);

	//Using assign() function
	list3.assign(list2.begin(),list2.end());
	cout<<"\n\nAfter assiging list2 elements to lsit3 :";
	display(list3);

	return 0;
}
void display(list <int> & v)
{
	list<int> :: iterator p;
	for(p = v.begin(); p!=v.end(); ++p)
		cout<<" "<<*p;
}
