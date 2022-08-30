#include<stdio.h>
#include<stdbool.h>
#define MAX 20
int board[MAX]={0};//1-D array to store the column each queen is placed at
int cnt=0;
int abs(int a)	//function to return absolute value
{
	return a<0?-a:a;
}
void print_board(int size)
{
	int i,j;
	printf("\nSolution %d: \n",++cnt);
	for(i=0;i<size;i++)
	{ 
	for (j=0;j<size;j++) 
		if(board[i]==j) 
			printf("Q "); 
		else 
			printf("0 "); 
			printf("\n");
	}
}
//to check if the kth queen can be placed in yth column
bool check_safe(int k,int y,int size)
{
	int i;
	//check if any of the previous queens are placed in yth column i.e., board[i] == y
	//check if any of the previously placed queen is in diagonal with the yth column
	for(i=0;i<k;i++) 
		if(board[i]==y || abs(i-k)==abs(y-board[i])) 
			return false;
	return true;
}
void n_queens(int k,int size)
{
	int i;
	if(k==size)	//all queens are placed
	{
		print_board(size);
		return ;
	}
	for(i=0;i<size;i++)
	{
		if(check_safe(k,i,size))
		{
			board[k]=i;	//placing kth queen at ith column is safe
			n_queens(k+1,size);
		}
	}
}
int main()
{
	int size;
	printf("Enter the size of the chess board: ");
	scanf("%d",&size);
	board[size];
	n_queens(0, size);
	if(cnt==0)
	 printf("There exists no solution\n");
	return 0;
}
