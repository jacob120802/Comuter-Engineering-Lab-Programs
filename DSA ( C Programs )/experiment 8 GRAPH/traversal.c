/*WAP to traverse a directed graph using BFS and DFS*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define initial 1
#define waiting 2
#define visited 3
int n;
int adjacency_matrix[MAX][MAX],state[MAX];
void create_graph();
void display();
void Traversal(int );
int front = -1,rear = -1;
int queue_array[MAX];
void bfs(int x);
void insert(int item);
int del();
int is_queue_empty();
int stack_arr[MAX];
int top = -1;
void dfs(int x);
void push(int item);
int pop();
int main()
{
	int choice;
	create_graph();
	printf("\n----------------------------------------------\n");
	while(1)
	{
		printf("1. Breadth First Search\n");
		printf("2. Depth First Search\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);	
		switch(choice)
		{
			case 1: Traversal(1);
				printf("\n----------------------------------------------\n");
				break;
			case 2: Traversal(2);
				printf("\n----------------------------------------------\n");
				break;
			case 3: display();
				printf("\n----------------------------------------------\n");
				break;
			case 4: return 0;
			default: printf("Invalid choice");
				printf("\n----------------------------------------------\n");
		}
	}
}
void create_graph()
{
	int max_edges,origin,dest,i;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	max_edges = n*(n-1);
	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d(-1,-1 to quit):",i);
		scanf("%d%d",&origin,&dest);
		if (origin == -1 && dest == -1)
			break;
		else if (origin >= n || origin < 0 || dest >= n || dest < 0)
		{
			printf("Invalid vertex\n");
			i--;	
		}	
		else
			adjacency_matrix[origin][dest] = 1;
	}	
}
void Traversal(int choice)
{
	int i;
	for(i=0;i<n;i++)
		state[i] = initial;	
	printf("Enter the starting index:");
	scanf("%d",&i);
	if (choice == 2)
		dfs(i);
	else
		bfs(i);
	for(i=0;i<n;i++)
	{
		if (state[i] == initial && choice == 2)
			dfs(i);
		else if (state[i] == initial)
			bfs(i);
	}
}
void display()
{
	int i,j;
	printf("The elements in the adjacency matrix are:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d  ",adjacency_matrix[i][j]);
		}
		if (i!=n-1)
			printf("\n");
	}
}
void bfs(int x)
{
	int i;
	insert(x);
	state[x] = waiting;
	while(!is_queue_empty())
	{
		x = del();
		printf("%d  ",x);
		state[x] = visited;
		for(i=0;i<n;i++)
		{
			if (adjacency_matrix[x][i] == 1 && state[i] == initial)
			{
				insert(i);
				state[i]= waiting;
			}
		}
	}	
}
void insert(int item)
{
	if (rear == MAX - 1) 
	{
		printf("Queue Overflow\n");
		return;
	}
	if (front == -1)
		front = 0;
	rear++;
	queue_array[rear] = item;
}
int del()
{
	int item;
	if (is_queue_empty())
	{
		return -1;		
	}
	item = queue_array[front];
	front++;
	return item;
}

void dfs(int x)
{
	int i;
	push(x);
	while(top!=-1)
	{
		x = pop();
		if (state[x] == initial)
		{
			printf("%d  ",x);
			state[x] = visited;
		}
		for(i=n-1;i>=0;i--)
		{
			if (adjacency_matrix[x][i] == 1 && state[i] == initial)
				push(i);
		}
	}
}
void push(int item)
{
	if (top == MAX - 1)
	{
		printf("Stack Overflow\n");
		return;
	}
	top = top + 1;
	stack_arr[top] = item;
}
int pop()
{
	int item;
	if (top == -1)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	item = stack_arr[top];
	top--;
	return item;
}
int is_queue_empty()
{
	if (front == -1 || (front == rear + 1 ))
		return 1;
	return 0;
}
