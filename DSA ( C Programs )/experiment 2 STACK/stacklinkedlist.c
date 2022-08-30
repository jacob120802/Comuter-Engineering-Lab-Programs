#include<stdio.h>
#include<stdlib.h>
struct node {
	int info;
	struct node *link;
};
struct node2{
	int info2;
	struct node2 *link2;
}*top2=NULL;
struct node *top;
void initialize();
int isEmpty();
int size();
int peek();
void push(int x);
int pop();
void display();
void reverse();
void push2(int item);
void reverse();
int main()
{
    int choice, x;
    initialize();
    while(1)
    {
        printf("1. Push an element on the top.\n");
        printf("2. Pop an element from the top.\n");
        printf("3. Display the top element.\n");
        printf("4. Display all stack elements.\n");
        printf("5. Reverse the stack elements. \n");
        printf("6. Quit.\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice == 6)
            break;
        switch(choice)
        {
        case 1:
            printf("Enter the element to be pushed : ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            x = pop();
            printf("Popped element is : %d\n",x);
            break;
        case 3:
            printf("Element at the top is : %d\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
        	reverse();
        	break;
        default:
            printf("Wrong Choice!!\n");
            break;
        }
        printf("\n");
    }
    return 0;
}
void initialize()
{
    top = NULL;
}
void push(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
    	printf("No Memory: Stack Overflow!!\n");
    	exit(1);
    }
    temp->info = x;
    temp->link = top;
    top = temp;
}
void push2(int item)
{
	struct node2 *temp2;
	temp2=(struct node2*)malloc(sizeof(struct node2));
	if(temp2==NULL)
	{
		printf("No Memory: Stack Overflow!!\n");
		exit(1);
	}
	temp2->info2=item;
	temp2->link2=top2;
	top2=temp2;
}
int pop()
{
    struct node *temp;
    int x;
    if(isEmpty())
	{
    	printf("Stack Underflow!!!\n");
    	exit(1);
    }
    temp = top;
    x = top->info;
    top = top->link;
    free(temp);
    return x;
}
int peek() 
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return top->info;
}
int isEmpty()
{
    if(top == NULL)
        return 1;
    else
        return 0;
}

void display()
{
    struct node *p;
    p = top;
    if(isEmpty())
	{
    	printf("Stack is empty\n");
    	return;
    }
    printf("Stack is:\n\n");
    while(p!=NULL)
	{
    	printf("%d\n", p->info);
    	p = p->link;
    }
    printf("\n");
}
void reverse()
{
int data;
struct node *temp;
struct node2 *temp2;
temp=top;
while(temp!=NULL)
{
data=temp->info;
push2(data);
temp=temp->link;
}
temp=top; //reset p to top
temp2=top2;
while(temp2!=NULL)
{
data=temp2->info2;
temp->info=data;
temp=temp->link;
temp2=temp2->link2;
}
}

