//wrie a program to know if double linked list is pallindrome or not
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* previous;
};
void isPallindrome(struct Node** Head)
{
    int length =1,i;
    struct Node* last = (struct Node*)malloc(sizeof(struct Node));
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    first = *Head;
    last = *Head;
    /*Finding length of list*/
    while(last->next!=NULL)
    {
        length++;
        last = last->next;
    }
    /*now 'last' points to the last item in the list*/
    for(i=0;i<length/2;i++)             //loop to check respective items
    {
        if(first->data!=last->data)     //palindrome condition failed
        {
            printf("It is not a palindrome");
            return;
        }
        first = first->next;        //move one item forward
        last = last->previous;      //move one item backward
    }
    printf("It is palindrome");     //list is palidrome
}
void insert(struct Node** Head,int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->previous = NULL;
    struct Node* t = *Head;
    if(*Head == NULL)       //First element in the list (or) head is null
    {
        *Head = temp;
        return;
    }
    /*travese till end*/
    while(t->next!=NULL)
        t = t->next;
    t->next = temp;         //next pointer points to last item
    temp->previous = t;     //previous pointer of last item points to previous item
}
int main()
{
	char string1[20];
    int length,data,i;
    struct Node* head = NULL;
    printf("Enter a string: ");
    scanf("%s",string1);
    length = strlen(string1);
    for(i = 0; i< length; i++)
	{
      insert(&head, string1[i]);
    }
    isPallindrome(&head);
    return 0;
}