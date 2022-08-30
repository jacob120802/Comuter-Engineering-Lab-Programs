#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *createList(struct node *start);
void display(struct node *start, FILE *fp);
void countNodes(struct node *start, FILE *fp);
void search(struct node *start,int data, FILE *fp);
struct node *insertInBeginning(struct node *start,int data);
struct node *insertAtEnd(struct node *start,int data);
struct node *insertAfter(struct node *start,int data,int item, FILE *fp);
struct node *insertBefore(struct node *start,int data,int item, FILE *fp );
struct node *insertAtPosition(struct node *start,int data,int pos, FILE *fp);
struct node *deleteNode(struct node *start,int data, FILE *fp);
struct node *reverseList(struct node *start);
int main()
{
	FILE *fp;
	char filename[100];	
	printf("Enter a filename :");
  	gets(filename);
  	fp = fopen(filename,"w+");
	if(fp==NULL)
	{
		printf("File does not exist\n");
	}
  	struct node *start=NULL;
	int choice,data,item,pos;
	while(1)
	{
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Count\n");
		printf("4.Search\n");
		printf("5.Add to empty list / Add at beginning\n");
		printf("6.Add at end\n");
		printf("7.Add after node\n");
		printf("8.Add before node\n");
		printf("9.Add at position\n");
		printf("10.Delete\n");
		printf("11.Reverse\n");
		printf("12.Quit\n\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			start=createList(start);
			break;
		 case 2:
			display(start, fp);
			break;
		 case 3:
			countNodes(start, fp);
			break;
		 case 4:
			printf("Enter the element to be searched : ");
			scanf("%d",&data);
			search(start,data,fp);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=insertInBeginning(start,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=insertAtEnd(start,data);
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			start=insertAfter(start,data,item,fp);
			break;
		 case 8:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert : ");
			scanf("%d",&item);
			start=insertBefore(start,data,item,fp);
			break;
		 case 9:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the position at which to insert : ");
			scanf("%d",&pos);
			start=insertAtPosition(start,data,pos,fp);
			break;
		 case 10:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			start=deleteNode(start, data, fp);	
			break;
		 case 11:
			start=reverseList(start);
			break;
		 case 12:
			 exit(1);
		 default:
			 printf("Wrong choice\n");
		}
	}
	fclose(fp);
	return 0;
}
struct node *createList(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;

	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=insertInBeginning(start,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=insertAtEnd(start,data);	
	}
	return start;
}
void display(struct node *start, FILE *fp)
{
	struct node *p;
	if(start==NULL)
	{
		fprintf(fp,"List is empty\n");
		return;
	}
	p=start;
	fprintf(fp,"List is :\n");
	while(p!=NULL)
	{
		fprintf(fp,"%d ",p->info);
		p=p->link;
	}
	fprintf(fp,"\n\n");
}
void countNodes(struct node *start, FILE *fp)
{
	struct node *p;
	int cnt=0;
	p=start;
	while(p!=NULL)
	{
		p=p->link;
		cnt++;
	}
	fprintf(fp,"Number of elements are %d\n",cnt);
}
void search(struct node *start,int item, FILE *fp)
{
	struct node *p=start;
	int pos=1;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			fprintf(fp, "Item %d found at position %d\n",item,pos);
			return;
		}
		p=p->link;
		pos++;
	}
	fprintf(fp, "Item %d not found in list\n",item);
}
struct node *insertInBeginning(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}
struct node *insertAtEnd(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}
struct node *insertAfter(struct node *start,int data,int item, FILE *fp)
{
	struct node *tmp,*p;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	fprintf(fp, "%d not present in the list\n",item);
	return start;
}
struct node *insertBefore(struct node *start,int data,int item, FILE *fp)
{
	struct node *tmp,*p;
	if(start==NULL )
	{
		fprintf(fp, "List is empty\n");
		return start;
	}	
	/*If data to be inserted before first node*/
	if(item==start->info)
	{
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->link=start;
		start=tmp;
		return start;
	}	
	p=start;
	while(p->link!=NULL) 
	{
		if(p->link->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	fprintf(fp, "%d not present in the list\n",item);
	return start;
}
struct node *insertAtPosition(struct node *start,int data,int pos, FILE *fp)
{
	struct node *tmp,*p;
	int i;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	if(pos==1)
	{
		tmp->link=start; 
		start=tmp;
		return start;
	}
	p=start;
	for(i=1; i<pos-1 && p!=NULL; i++)
		p=p->link;
	if(p==NULL)
		fprintf(fp, "There are less than %d elements\n",pos);
	else
	{
		tmp->link=p->link;
		p->link=tmp;
	}	
	return start;
}
struct node *deleteNode(struct node *start,int data, FILE *fp)
{
	struct node *tmp,*p;
	if(start==NULL)
	{
		fprintf(fp, "List is empty\n");
		return start;
	}
	/*Deletion of first node*/
	if(start->info==data)
	{
		tmp=start;
		start=start->link;  
		free(tmp);
		return start;
	}
	/*Deletion in between or at the end*/
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==data)   
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return start;
		}
		p=p->link;
	}
	fprintf(fp, "Element %d not found\n",data);
	return start;
}
struct node *reverseList(struct node *start)
{
	struct node *prev, *ptr, *next;
	prev=NULL;
   	ptr=start;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	return start;
}