#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
struct node
{
	char info;
	struct node *link;	
}*top=NULL;
void push(char c)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=c;
	tmp->link=top;
	top=tmp;		
}
char pop()
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	char c;
	tmp=top;
	c=tmp->info;
	top=top->link;
	return c;
}
void infix_to_postfix();
int eval_post();
int instack_priority(char symbol);
int symbol_priority(char symbol);
int white_space(char symbol);
char infix[MAX],postfix[MAX];
int main()
{
	int value;
	printf("Enter infix expression:");
	gets(infix);
	infix_to_postfix();
	printf("Postfix expression: %s\n",postfix);
	value=eval_post();
	printf("Evaluation of this expression is: %d\n",value);
	return 0;
}
void infix_to_postfix()
{
	int i,p=0;
	char next;
	char symbol;
		for(i=0;i<strlen(infix);i++)
		{
			symbol=infix[i];
			if(!white_space(symbol))
			{
				switch(symbol)
				{
					case '(':
						push(symbol);
						break;
					case ')':
						while((next=pop())!='(')
						postfix[p++]=next;
						break;
					case '+':
					case '-':
					case '*':
					case '/':
					case '%':
					case '^':
						while((top!=NULL)&&instack_priority(top->info)>=symbol_priority(symbol))
						postfix[p++]=pop();
						push(symbol);
						break;
					default:
							postfix[p++]=symbol;
					}
			}
		}
	while(!isEmpty())
	postfix[p++]=pop();
	postfix[p]='\0';
}

int isEmpty()
{
	if (top==NULL)
	return 1;
	else
	return 0;	
}
int instack_priority(char symbol)
{
	switch(symbol)
	{
		case '(': return 0;
		case '+':
		case '-':
					return 1;
		case '*':
		case '/':
		case '%':
					return 2;
		case '^':
					return 3;
	}	
}
int symbol_priority(char symbol)
{
	switch(symbol){
		case '(': return 0;
		case '+':
		case '-':
					return 1;
		case '*':
		case '/':
		case '%':
					return 2;
		case '^':
					return 4;
	}	
}
int white_space(char symbol)
{
	if(symbol==BLANK||symbol==TAB)
	return 1;
	else
	return 0;	
}
int eval_post()
{
	int a,b,temp,result;
	int i;
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]<='9'&&postfix[i]>='0')
			push(postfix[i]-'0');
		else{
			a=pop();
			b=pop();
				switch(postfix[i]){
					case '+':
							temp=b+a;break;
					case '-':
						temp=b-a;break;
					case '*':
						temp=b*a;break;
					case '/':
						temp=b/a;break;
					case '%':
						temp=b%a;break;
					case '^':
						temp=pow(b,a);
					}
					push(temp);
			}	
	}
	result=pop();
	return result;	
}
	