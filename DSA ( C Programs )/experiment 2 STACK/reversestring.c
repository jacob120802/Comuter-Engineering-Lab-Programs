#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100
struct Stack{
    char ele;
    struct Stack *next;
};
struct Stack* next_node(char element){
    struct Stack *node=(struct Stack *)malloc(sizeof(struct Stack));
    node->ele=element;
    node->next=NULL;
    return node;
}
int isEmpty(struct Stack *node){
    return node==NULL;
}
void push(struct Stack **node, char element){
    struct Stack *temp=next_node(element);
    temp->next=*node;
    *node=temp;
}
char pop(struct Stack** node) {
  if (isEmpty(*node)) {
    return 0;                
  }
  struct Stack* temp = *node;
  *node = (*node)->next;
  char retval = temp->ele;   
  free(temp);
  return retval;             
}
void rev(char str[]) {
  int i;
  int n = strlen(str);
  struct Stack* s = NULL;   
  for (i = 0; i < n; i++)
    push(&s, str[i]);
  for (i = 0; i < n; i++)
    str[i] = pop(&s);
  printf("The reversed string is: %s\n", str);
}
int main()
{
    char string[M], op[1];
    do{
        printf("Enter the string to be reversed: ");
        scanf("%s", string);
        rev(string);
        printf("Do you want to go again?(Y/N): ");
        scanf("%s", op);
    }while(op[0]=='Y');
    return 0;
}