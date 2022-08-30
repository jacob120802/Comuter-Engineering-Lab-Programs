#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int r[MAX];
int a[MAX];
int top;
void initialize();
int isEmpty();
int isFull();
int revtop=-1;

int peek();
void push(int x);
int pop();
void display();
int reverse(int t);

int main()
{
    int choice, x,k;
    initialize();
    while(1)
    {
        printf("1. Push an element on the top.\n");
        printf("2. Pop an element from the top.\n");
        printf("3. Display the top element.\n");
        printf("4. Display all stack elements.\n");
        printf("5.Reverse elements of the stack.\n");
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
        	while(top>=0)
        	{
        		r[++revtop]=a[top];
        		a[top--]=0;
			}
			top=0;
        	k=reverse(revtop);
        	a[top]=k;
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
    top = -1;
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top == MAX-1)
        return 1;
    else
        return 0;
}
void push(int x)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    ///else
    top = top + 1;
    a[top] = x;
}
int pop()
{
    int x;
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    ///else
    x = a[top];
    top = top - 1;
    return x;
}
int peek()  ///returns the top value
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    ///else
    return a[top];
}
void display()
{
    int i;
    printf("top = %d\n", top);
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    ///else
    printf("Stack is : \n\n");
    for(i = top; i>=0; i--)
        printf(" %d\n", a[i]);
    printf("\n");
}
int reverse(int t)
{
	if (t==0)
	{
		return r[t];
	}
	int x = reverse(t-1);
	a[top] = x;
	top++;
	return r[t];
}
