#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};
int max=0;
struct node *getNode(int x);
void display(struct node *p, int level);
void maxwidth(struct node *root);
void display_level(struct node*, struct node* ,int);
int height(struct node*);
struct node *insertNode(struct node *root, int x);
struct node *search(struct node *p, int x);
struct node *deleteNode(struct node *root, int x);
void level_display(struct node *root, int x, int l)
{
	if(root != NULL){
		if(x == l){
			printf("%d ", root->info);
			return;
		}
		else{
			level_display(root->lchild, x, (l+1));
			level_display(root->rchild, x, (l+1));
		}
	}
	return;
}
struct node *Max(struct node *p);
void preorderTraversal(struct node *root);
void inorderTraversal(struct node *root);
void postorderTraversal(struct node *root);
void levelorderTraversal(struct node *root);
struct node *queue[MAX];
int front=-1,rear=-1;
void insert_queue(struct node *item);
struct node *delete_queue();
int queue_empty();
struct node *stack[MAX];
int top=-1;
void push_stack(struct node *item);
struct node *pop_stack();
int stack_empty();
int main( )
{
	struct node *root=NULL, *p;
	int choice,x;
	while(1)
	{
		printf("\n");
		printf("1.Display Tree:\n");
		printf("2.Search\n");
		printf("3.Insert a new node:\n");
		printf("4.Delete a node: \n");
		printf("5.Print n level elements: \n");
		printf("6.Find level having max width: \n");
		printf("7.Preorder Traversal\n");
		printf("8.Inorder Traversal\n");
		printf("9.Postorder Traversal\n");
		printf("10.Level order traversal\n");
		printf("11.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
        if(choice == 11)
        	break;
		switch(choice)
		{
		case 1:
			printf("\n");
		    display(root, 0);
		    printf("\n");
		    break;
		case 2: 
			printf("Enter the key to be searched : ");
			scanf("%d",&x);
			p = search(root, x);
			if(p==NULL)
				printf("Key not found!!!\n");
			else
				printf("Key found.\n");
			break;
		case 3:
			printf("Enter the key to be inserted : ");
			scanf("%d",&x);
			root = insertNode(root, x);
			break;
		case 4:
			printf("Enter the key to be deleted : ");
			scanf("%d",&x);
			root = deleteNode(root, x);
			break;
		case 5:
		    printf("Enter the level : ");
			scanf("%d", &x);		
			level_display(root, x, 0);	
			printf("\n");
			break;
		case 6:
		    maxwidth(root);
		    break;
		case 7:
			preorderTraversal(root);
			break;
		case 8:
			inorderTraversal(root);
			break;
		case 9:
			postorderTraversal(root);
			break;
		case 10:
			levelorderTraversal(root);
			break;
		case 11:
			exit(1);
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}
struct node *getNode(int x)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->info = x;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}
void display(struct node *p, int level)
{
	int i;
	if(p == NULL)
		return;
	else
	{
		display(p->rchild, level+1);
		printf("\n\n");
		for(i = 0; i<level; i++)
			printf("\t");
		printf("%d", p->info);
		display(p->lchild, level+1);
	}
}
struct node *insertNode(struct node *root, int x)
{       
	struct node *temp,*par,*p;
	p = root;
	par = NULL;
	
	while( p!=NULL)
	{
		par = p;
		if(x < p->info)
			p = p->lchild;	
		else if( x > p->info )
			p = p->rchild;
		else
		{
			printf("Duplicate key:%d already present in the tree\n", x);
			return root;
		}
	}
	temp=getNode(x);
	if(par==NULL)
		root=temp;
	else if( x < par->info )
		par->lchild = temp;
	else
		par->rchild = temp;
	return root;
}
struct node *search(struct node *p, int x)
{
	while(p!=NULL)
	{
		if(x < p->info)
			p = p->lchild; 
		else if(x > p->info)
			p = p->rchild; 
		else	
			return p;
	}
	return NULL;
}
struct node *deleteNode(struct node *root, int x)
{
	struct node *par,*p, *child, *succ, *parsucc;
	p = root;
	par = NULL;
	while( p!=NULL)
	{
		if( x == p->info)
			break;
		par = p;
		if(x < p->info)
			p = p->lchild;	
		else 
			p = p->rchild;
	}
	if(p==NULL)
	{
		printf("%d not present in the tree\n", x);
		return root;
	}
	if(p->lchild!=NULL && p->rchild!=NULL)
	{
		parsucc = p;
		succ = p->rchild;
		while(succ->lchild!=NULL)
		{
			parsucc = succ;
			succ = succ->lchild;
		}
		p->info = succ->info;
		p = succ;
		par = parsucc;
	}	
	if(p->lchild != NULL) 
		child = p->lchild;
	else                
		child = p->rchild;

	if(par == NULL)   
		root = child;
	else if(p == par->lchild)
		par->lchild = child;
	else       
		par->rchild=child;
	free(p);
	return root;
}
void maxwidth(struct node *root)
{
	struct node *p=root;
	if(p==NULL)
	{
		printf("\nTree is empty!!\n");
	}
	int h=height(root), width, level, i;
	for(i=1; i<=h; i++)
	{
		width=level_width(p,i);
		if(max<width)
		{
			max=width;
			level=i;
		}
	}
	printf("\nThe max width of binary tree is: %d, at level: %d\n", max, level-1);
	return;
}
int level_width(struct node *p, int l)
{
	if (p==NULL)
		return 0;
	if(l==1)
		return 1;
	else if (l>1)
		return level_width(p->lchild, l-1) + level_width(p->rchild, l-1);
}
int height(struct node* p)
{
	int left, right;
	if(p==NULL)
		return 0;
	left= height(p->lchild);
	right= height(p->rchild);
	if (left>right)
		return (1+left);
	else return(1+right);
}
void preorderTraversal(struct node *root)
{
	struct node *p = root;
	if( p==NULL )
	{
		printf("Tree is empty\n");
		return;
	}
	push_stack(p);
	while( !stack_empty() )
	{
		p = pop_stack();
		printf("%d  ",p->info);
		if(p->rchild!=NULL)
			push_stack(p->rchild);
		if(p->lchild!=NULL) 
			push_stack(p->lchild);
	}
	printf("\n");
}
void inorderTraversal(struct node *root)
{
	struct node *p=root;
	
	if( p==NULL )
	{
		printf("Tree is empty\n");
		return;
	}
	while(1)
	{
      while(p->lchild!=NULL )
		{
			push_stack(p);
			p = p->lchild;
		}
			
		while( p->rchild==NULL )
		{
			printf("%d  ",p->info);
			if(stack_empty())
				return;
			p = pop_stack();
		}
		printf("%d  ",p->info);
		p = p->rchild;
	}
	printf("\n");
}
void postorderTraversal(struct node *root)
{
	struct node *p = root;
	struct node *q;
	if( p==NULL )
	{
		printf("Tree is empty\n");
		return;
	}
	q = root;
	while(1)
	{
		while(p->lchild!=NULL)
		{
			push_stack(p);
			p=p->lchild;
		}
		while( p->rchild==NULL || p->rchild==q )
		{
			printf("%d  ",p->info);		
			q = p;
			if( stack_empty() )
				return;
			p = pop_stack();
		}
		push_stack(p);
		p = p->rchild;
	}
	printf("\n");
}
void levelorderTraversal(struct node *root)
{
	struct node *p = root;
	if( p==NULL )
	{
		printf("Tree is empty\n");
		return;
	}
	insert_queue(p);
	while( !queue_empty() ) 
	{
		p=delete_queue();
		printf("%d ",p->info);
		if(p->lchild!=NULL)
			insert_queue(p->lchild);
		if(p->rchild!=NULL)
			insert_queue(p->rchild);
	} 
	printf("\n");
}
void insert_queue(struct node *item)
{
	if(rear==MAX-1)
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1)  
		front=0;
	rear=rear+1;
	queue[rear]=item ;
}
struct node *delete_queue()
{
	struct node *item;
	if(front==-1 || front==rear+1)
	{
		printf("Queue Underflow\n");
		return 0;
	}
	item=queue[front];
	front=front+1;
	return item;
}
int queue_empty()
{
	if(front==-1 || front==rear+1)
		return 1;
	else
		return 0;
}
void push_stack(struct node *item)
{
	if(top==(MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	top=top+1;
	stack[top]=item;
}
struct node *pop_stack()
{
	struct node *item;
	if(top==-1)
	{
		printf("Stack Underflow....\n");
		exit(1);
	}
	item=stack[top];
	top=top-1;
	return item;
}
int stack_empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}