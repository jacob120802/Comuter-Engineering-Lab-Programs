#include <iostream>
using namespace std;
template <class T>
class vector
{
	    T *v;
	    int size;
	public:
	    vector()
	    {
	        size = 0;
	        v = new T[size + 1];
	    }
	    vector(int n)
	    {
	        size = n;
	        v = new T[size + 1]; //Vector is dynamic array
	    }
	    void get_elements()
	    {
	        for (int i = 0; i < size; i++)
	        {
	            cin >> v[i];
	        }
	    }
	    void modifybyindex()
	    {
	        int ind;
	        cout << "Enter index to modify: ";
	        cin >> ind;
	        cout << "\nEnter value: ";
	        cin >> v[ind];
	    }
	    void display()
	    {
	        for (int i = 0; i < size; i++)
	        {
	            cout << v[i] << " ";
	        }
	        cout << endl;
	    }
};

int main()
{
    vector <int> v1;
    vector <float> v2;
    int n;
    cout << "Enter total elements: ";
    cin >> n;
    v1 = (n);
    cout << "Enter elements:" << endl;
    v1.get_elements();
    v1.display();
    
    v1.modifybyindex();
    v1.display();
     v2 = (n);
     cout << "Enter elements:" << endl;
    v2.get_elements();
    v2.display();
    
    v2.modifybyindex();
    v2.display();
    return 0;
}