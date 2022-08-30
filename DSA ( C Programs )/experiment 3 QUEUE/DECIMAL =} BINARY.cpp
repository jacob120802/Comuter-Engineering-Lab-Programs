#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *link;	
}*front=NULL,*rear=NULL;
int isEmpty();
void insert(int item);
int del();
void dectobin(int num);
void display(int arr[],int count);
int main()
{
	int num;
	printf("Enter a decimal number to be converted to binary: ");
	scanf("%d",&num);
	dectobin(num);	
	return 0;
}

int isEmpty()
{
	if(front==NULL)
	return 1;
	else
	return 0;	
}

void insert(int item)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
		if(tmp==NULL)
		{
			printf("Queue Overflow!\n");
			return ;	
		}
	tmp->info=item;
	tmp->link=NULL;
		if(front==NULL)
		front=tmp;
		else
		rear->link=tmp;
	rear=tmp;
}

int del()
{
	struct node *tmp;
	int item;
		if(isEmpty())
		{
			printf("Queue Underflow!\n");
			exit(1);	
		}	
	tmp=front;
	item=tmp->info;
	front=tmp->link;
	return item;	
}
void dectobin(int num)
{
	int i;
	int count=0;
		for(i=0;num>0;i++)
		{
			insert(num%2);
			num=num/2;
		}
	struct node *p;
	p=front;
		while(p!=NULL)
		{
			count++;
			p=p->link;
		}		
	int arr[count];
		for(i=0;i<count;i++)
		{
			arr[i]=del();
		}
	display(arr,count);	
}
void display(int arr[],int count)
{
	int i;
	printf("The binary equivalent is: ");
		for(i=count-1;i>=0;i--)
		{
			printf("%d",arr[i]);
		}
}
