#include<stdio.h>
#include<stdlib.h>
struct node
{
	int rollno;
	char name[20];
	int marks[3];
	int total;
	float avg;
	struct node *link;
}*start=NULL, *start2=NULL;

void append();
void display(struct node*);
void findls();
void swap();
void split();
void merge();
void del(struct node*);
void sort();
void addatpos(struct node*, int);
void minmax(struct node *start);
int main()
{
	int i,n;
	printf("Enter the no. of the student\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		append();
	printf("\n\nList\n");
	display(start);
	printf("\nDisplay minimum and maximum of the linked list.\n");
    minmax(start);
	printf("\n\nNew List\n");
	findls();
	printf("\n\nSwapped list\n");
	swap();getch();
	split();
	printf("\n\nList 1\n");
	display(start);
	printf("\n\nList 2\n");
	display(start2);getch();
	printf("\n\nSorted List after merging\n");
	merge();
	sort();getch();
	return 0;
}

void append()
{
	int i;
	struct node *p=start, *t=(struct node*) malloc(sizeof(struct node));
	printf("\nEnter Roll No.: ");
	scanf("%d",&t->rollno);
	printf("Enter Name: ");getchar();
	gets(t->name);
	printf("Enter marks\n");
	t->total=0;
	for(i=0;i<3;i++)
	{
		printf("Subject %d: ",i+1);
		scanf("%d",&t->marks[i]);
		t->total+=t->marks[i];
	}
	t->avg=t->total/3.0;
	t->link=NULL;
	if(start==NULL)
	{
		start=t;
		return;
	}
	while(p->link!=NULL)
		p=p->link;
	p->link=t;
}

void display(struct node* s)
{
	struct node *p=s;
	if(s==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	printf("\nRollno\t  Name\t Sub1\tSub2\tSub3\tTotal\tAverage\n");
	while(p!=NULL)
	{
		printf("%4d %9s %5d %6d %7d %8d %9.2f\n",p->rollno, p->name,p->marks[0],p->marks[1],p->marks[2],p->total,p->avg);
		p=p->link;
	}
}

void findls()
{
	int t1=-1,t2=10000;
	struct node *p=start, *last, *min, *max;
	while(p!=NULL)
	{
		if(p->total > t1)
		{
			t1=p->total;
			max=p;
		}
		if(p->total < t2)
		{
			t2=p->total;
			min=p;
		}
		last=p;
		p=p->link;
	}
	if(min!=start)
	{
		del(min);
		min->link=start;
		start=min;
	}
	if(max!=last)
	{
		del(max);
		last->link=max;
		max->link=NULL;
	}
	display(start);
}

void del(struct node* d)
{
	struct node* p=start;
	while(p->link!=NULL)
	{
		if(p->link==d)
		{
			p->link=p->link->link;
			break;
		}
		p=p->link;
	}
}

void swap()
{
	struct node *prev=NULL, *next, *cur=start;
	if(start!=NULL && start->link==NULL)
		return;
	start=start->link;
	while(cur!=NULL && cur->link!=NULL)
	{
		next=cur->link;
		cur->link=next->link;
		next->link=cur;
		if(prev!=NULL)
			prev->link=next;
		prev=cur;
		cur=cur->link;
	}
	display(start);
}

void split()
{
	int rno;
	struct node *p=start;
	printf("\n\nEnter Roll No. from where you want to split the list: ");
	scanf("%d",&rno);
	if(start->rollno==rno)
	{
		printf("\nList cannot be splitted\n");
		return;
	}
	while(p->link!=NULL)
	{
		if(p->link->rollno==rno)
		{
			start2=p->link;
			p->link=NULL;
			break;
		}
		p=p->link;
	}
}

void merge()
{
	struct node *p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=start2;
}

void sort()
{
	int i=1;
	struct node *p=start, *q, *t;
	for(;p->link!=NULL;i++)
	{
		t=p;
		for(q=p->link;q!=NULL;q=q->link)
		{
			if(t->rollno > q->rollno)
				t=q;
		}
		if(t==p)
			p=p->link;
		else
		{
			del(t);
			addatpos(t,i);
		}
	}
	display(start);
}

void addatpos(struct node *t, int pos)
{
	int i;
	struct node *p;
	if(pos==1)
	{
		t->link=start;
		start=t;
		return;
	}
	for(i=2, p=start; i<pos && p!=NULL; i++, p=p->link);
	t->link=p->link;
	p->link=t;
}
void minmax(struct node *start)
{
float min,max;
struct node *p;	
	if(start==NULL)
	{
		printf("List is empty.\n");
		return ;
	}
p=start;
min=start->avg;
	//To find minimum total in the LL.
	
	while(p!=NULL)
	{
	if(min>p->avg)
	min=p->avg;
	p=p->link;
	}
	
	//To find maximum total in the LL
p=start;
max=start->avg;
	
	while(p!=NULL)
	{
	if(max<p->avg)
	max=p->avg;
	p=p->link;	
	}
	
	printf("The minimum average score of student is %f\n",min);
	printf("The maximum average mark of student is %f\n",max);
}
