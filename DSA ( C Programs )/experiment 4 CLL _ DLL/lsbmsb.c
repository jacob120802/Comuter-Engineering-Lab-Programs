//create a circular linked list in which info part of each node contains a digit of given number the digits should be stored in reverse order the lsb should be stored in 1st node and msb be stored in last node write a funcion to add 2 consecutive nofrom circular linked list and store it in a double linked list
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int revnum[MAX];
int numarray[MAX];
int count;
int number;
int revnumber=0;

struct dnode{
int info;
struct dnode *next;
struct dnode *prev;	
}*start=NULL;

struct cnode{
int info;
struct cnode *link;	
}*last=NULL;

void create_circular_list();
void addtocempty();
void addtocend();
void cdisplay();
void input();
void create_double_list();
void addtodempty();
void addtodend();
void ddisplay();

void create_circular_list()
{
int i;
int temp;
	for(i=1;i<=count;i++)
	{	
	temp=number%10;
	number=number/10;
	revnum[i]=temp;
	}
	
	addtocempty(revnum[1]);
	
	for(i=2;i<=count;i++)
	{
	addtocend(revnum[i]);
	}	
}

void addtocempty(int data)
{
struct cnode *tmp;
tmp=(struct cnode *)malloc(sizeof(struct cnode));
tmp->info=data;
last=tmp;
last->link=last;	
}

void addtocend(int data)
{
struct cnode *tmp;
tmp=(struct cnode*)malloc(sizeof(struct cnode));
tmp->info=data;
tmp->link=last->link;
last->link=tmp;
last=tmp;
}

void cdisplay()
{
struct cnode *p;
	p=last->link;
	printf("\nCircular linked list which contains the number in reversed order is:\n");
	do{
	printf("%d ",p->info);
	p=p->link;	 
	}while(p!=last->link);
	printf("\n\n");
}

void input()
{
printf("Enter the number:");
scanf("%d",&number);
int i;
int digit;
int tempnum=number;
	while(tempnum!=0)
	{
	tempnum=tempnum/10;
	count=count+1;
	}
}

void create_double_list()
{
int i,numdnode;
struct cnode *c; //for traversal through circular list;
struct dnode *d;

	if(count==1) //if the number contains only 1 digit
	{
	addtodempty(last->info);
	return;
	}
	
	if(count%2==0) //if the number contains even number of digits
	{
		numdnode=count/2;
		addtodempty(last->link->info+last->link->link->info);
		c=last->link->link->link;
		for(i=1;i<numdnode;i++)
		{
		addtodend(c->info+c->link->info);
		c=c->link->link;
		}
	}
	else //if the number contains odd number of digits, add the leftover
		//digit at the end.
	{
	numdnode=(count/2)+1;
		addtodempty(last->link->info+last->link->link->info);
		c=last->link->link->link;
		for(i=1;i<(numdnode-1);i++)
		{
		addtodend(c->info+c->link->info);
		c=c->link->link;
		}
		addtodend(c->info);
	}
	
	/*	
	addtodempty(last->link->info+last->link->link->info);
	c=last->link->link->link;
	for(i=1;i<numdnode;i++)
	{
	addtodend(c->info+c->link->info);
	c=c->link->link;
	}	
	*/
}

void addtodempty(int data)
{
struct dnode *tmp;
tmp=(struct dnode*)malloc(sizeof(struct dnode));
tmp->info=data;
tmp->prev=NULL;
tmp->next=NULL;
start=tmp;	
}

void addtodend(int data)
{
struct dnode *p,*tmp;
tmp=(struct dnode *)malloc(sizeof(struct dnode));
p=start;
	while(p->next!=NULL)
		p=p->next;
tmp->info=data;
tmp->prev=p;
tmp->next=NULL;
p->next=tmp;
}

void ddisplay()
{
struct dnode *p;
p=start;
printf("Doubly linked list which contains sum of consecutive 2 numbers is:\n");
	while(p!=NULL)
	{
	printf("%d ",p->info);
	p=p->next;
	}	
printf("\n");	
}

int main()
{
input(); //input the number
create_circular_list(); //reverse the number and store it in the circular linked list
cdisplay();	//display the reversed number stored in the circular linked list
create_double_list(); //create the doubly linked list which contains sum of consecutive numbers
					 //from the circular linked list.
ddisplay(); //display the doubly linked list.
}