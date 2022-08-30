#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *top = NULL;
/* create a new node */
struct node* createNode (int data) 
{
    struct node *ptr = (struct node *) malloc(sizeof (struct node));
    ptr->data = data;
    ptr->next = NULL;
}
/* push the given data into the stack */
void push(int data) 
{
    struct node *temp, *ptr = createNode(data);
    if (top == NULL) 
	{
        top = ptr;
        return;
    }
    temp = top;
    ptr->next = temp;
    top = ptr;
}
/* pop the top element from the stack */
int pop() 
{
    int data;
    struct node *temp;
    if (top == NULL)
        return -1;
    data = top->data;
    temp = top;
    top = temp->next;
    free (temp);
    return (data);
  }
int main() 
{
    char str[100];
    int i, flag = 0, data = 0;
    /* get the input from the user */
    printf("Enter ur expression:");
    fgets(str, 100, stdin);
    for (i = 0; i < strlen(str); i++) 
	{
        /* i/p char is an open brace -push it into stack */
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') 
		{
            push(str[i]);
            continue;
        }
        if (str[i] == ')' || str[i] == '}' || str[i] == ']') 
		{
        	/* i/p char is a close brace - pop top from stack */
        	data = pop();
            if ((str[i] == ')' && data != '(') || data == -1 || (str[i] == '}' && data != '{') || (str[i] == ']' && data != '[')) 
			{
                /* mismatch/missing symbols */
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1 || top != NULL)
    printf("Not a balanced expression\n");
    else
    printf("Balanced Expression\n");
    return 0;
}
