#include <iostream>
#define MAX 20
using namespace std;
int i,j;
template <class T>
class MAT
{
	T arr[MAX][MAX];
	int row;
	int col;
	public:
		void getdata()
		{
			cout << "Enter the number of rows and columns in the matrix:";
			cin >> row >> col;
			cout << "Enter the elements in the matrix:" << endl;
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
					cin >> arr[i][j];
			}
		}	
		void display()
		{
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
					cout << arr[i][j] << "  ";
				cout << endl;
			}
			cout << "----------------------------------------------------------------------------" << endl;
		}
		
		MAT operator *(int k)
		{
			MAT m;
			m.row = row;
			m.col = col;
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
					m.arr[i][j] = arr[i][j]*k;
			}
			return m;
		}
		
		friend int check(MAT m1, MAT m2,char sign)
		{
			if (sign == '+' || sign == '-')
			{
				if ((m1.row == m2.row) && (m1.col == m2.col))
					return 1;
				return -1;
			}
			if (sign == '*')
			{
				if (m1.col == m2.row)
					return 1;
				return -1;
			}
		}

		MAT operator + (MAT x)
		{
			MAT m;
			m.row = row;
			m.col = col;
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
					m.arr[i][j] = arr[i][j] + x.arr[i][j];
			}
			return m;
		}
		MAT operator - (MAT x)
		{
			MAT m;
			m.row = row;
			m.col = col;
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
					m.arr[i][j] = arr[i][j] - x.arr[i][j];
			}
			return m;
		}
		MAT operator *(MAT x)
		{
			MAT m;
			m.row = row;
			m.col = x.col;
			int sum,k;
			for(i=0;i<row;i++)
    		{
        		for(j=0;j<x.col;j++)
        		{
            		sum = 0;
            		for(k=0;k<col;k++)
            		{
                		sum = sum + arr[i][k]*x.arr[k][j];   
            		}
            		m.arr[i][j] = sum;
        		}
    		}
			return m;
		}
};


int main()
{
	MAT <int>m1;
	MAT <int>m2;
	MAT <int>m3;
	int k,addsub_check,mul_check;
	m1.getdata();
	m2.getdata();
	
	cout << "The elements in matrix 1 are:" << endl;
	m1.display();
	cout << "The elements in matrix 2 are:" << endl;
	m2.display();
	cout << "		MULTIPLYING A MATRIX BY A SCALAR	    " << endl;
	cout << "Enter a scalar to be multiplied to matrix 1:";
	cin >> k;
	m3 = m1*k;
	m3.display();
	cout << "			ADDING TWO MATRICES			" << endl;
	addsub_check = check(m1,m2,'+');
	if (addsub_check == 1)
	{
		m3 = m1 + m2;
		cout << "The result of m1 + m2 is:" << endl;
		m3.display();
	}
	else
	{
		cout << "Matrix 1 and 2 can't be added" << endl;
		cout << "----------------------------------------------------------------------------" << endl;
	}
	
	cout << "		    SUBTRACTING TWO MATRICES			" << endl;
	addsub_check = check(m1,m2,'-');
	if (addsub_check == 1)
	{
		m3 = m1 - m2;
		cout << "The result of m1 - m2 is:" << endl;
		m3.display();
	}
	else
	{
		cout << "Matrix 1 and 2 can't be subtracted" << endl;
		cout << "----------------------------------------------------------------------------" << endl;
	}
	
	cout << "		   MULTIPLYING TWO MATRICES			" << endl;
	mul_check = check(m1,m2,'*');
	if (mul_check == 1)
	{
		m3 = m1 * m2;
		cout << "The result of m1 * m2 is:" << endl;
		m3.display();
	}
	else
		cout << "Matrix 1 and 2 can't be multiplied" << endl;
	
	return 0;
}
