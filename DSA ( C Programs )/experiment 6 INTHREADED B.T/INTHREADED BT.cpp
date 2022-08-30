#include<stdio.h>
#include<stdlib.h>
struct node *in_succ(struct node *root);
struct node *insert(struct node *root,int ikey);
struct node *del(struct node *root,int dkey);
struct node *case_a(struct node *root,struct node *par,struct node *ptr);
struct node *case_b(struct node *root,struct node *par,struct node *ptr);
struct node *case_c(struct node *root,struct node *par,struct node *ptr);
struct node *in_succ(struct node *ptr);
struct node *in_pred(struct node *ptr);
void inorder(struct node *root);
void preorder( struct node *root);
void display(struct node *p,int level);
typedef enum
{
	fal,tru
}boolean;

struct node
{
	struct node *left;
	boolean lthread;
	int info;	
	boolean rthread;
	struct node *right;
};

int main()
{
int choice,data;
struct node *root=NULL;
	do{
	printf("\n1.Insert a node\n");
	printf("2.Delete a node\n");
	printf("3.Display\n");
	printf("4.Inorder Traversal\n");
    printf("5.Preorder Traversal\n");
	printf("6.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice){
	case 1:printf("Enter the node to be inserted:");
	scanf("%d",&data);
	root=insert(root,data);
	break;
	
	case 2:printf("Enter the node to be deleted:");
	scanf("%d",&data);
	root=del(root,data);
	break;
	case 3:
		display(root,0);
		break;
	case 4:
        inorder(root);
        break;

    case 5:
        preorder(root);
        break;
    
	case 6:exit(1);
	
	default:printf("Please enter a valid choice.\n");	
	}
	}while(choice!=6);
}
struct node *insert(struct node *root,int ikey)
{
struct node *tmp,*par,*ptr;
int found=0;
ptr=root;
par=NULL;
	while(ptr!=NULL)
	{
		if(ikey==ptr->info)
		{
		found=1;
		break;	
		}
		par=ptr;
		if(ikey<ptr->info)
		{
			if(ptr->lthread==fal)
			ptr=ptr->left;
			else
			break;	
		}
		else
		{
			if(ptr->rthread==fal)
			ptr=ptr->right;
			else
			break;
		}
	}	
	if(found)
	printf("Duplicate Key!\n");
	else{
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=ikey;
	tmp->lthread=tru;
	tmp->rthread=tru;
		if(par==NULL)
		{
		root=tmp;
		tmp->left=NULL;
		tmp->right=NULL;
		}
		else if(ikey<par->info)
		{
		tmp->left=par->left;
		tmp->right=par;
		par->lthread=fal;
		par->left=tmp;
		}
		else
		{
		tmp->left=par;
		tmp->right=par->right;
		par->rthread=fal;
		par->right=tmp;
		}	
	}
return root;
}

struct node *del(struct node *root,int dkey)
{
struct node *par,*ptr;
par=NULL;
ptr=root;
int found;
	while(ptr!=NULL)
	{
		if(dkey==ptr->info)
		{
		found=1;
		break;	
		}
		par=ptr;
		if(dkey<ptr->info)
		{
			if(ptr->lthread==fal)
			ptr=ptr->left;
			else
			break;
		}
		else
		{
			if(ptr->rthread==fal)
			ptr=ptr->right;
			else
			break;
		}	
	}
if(found==0)
printf("\n%d key not present in tree",dkey);

	else if(ptr->lthread==fal && ptr->rthread==fal) //case of 2 children
	root=case_c(root,par,ptr);
	else if(ptr->lthread==fal) //1 child
	root=case_b(root,par,ptr);
	else if(ptr->rthread==fal)
	root=case_b(root,par,ptr);
	else  //no children
	root=case_a(root,par,ptr);
return root;	
}

struct node *case_a(struct node *root,struct node *par,struct node *ptr)
{
if(par==NULL)
root=NULL;
else if(ptr==par->left)
{
par->lthread=tru;
par->left=ptr->left;
}
else
{
par->rthread=tru;
par->right=ptr->right;	
}
free(ptr);
return root;
}

struct node *case_b(struct node *root,struct node *par,struct node *ptr)
{
struct node *child,*s,*p;
if(ptr->lthread==fal)
child=ptr->left;
else
child=ptr->right;
if(par==NULL)
root=child;
else if(ptr==par->left)	
par->left=child;
else
par->right=child;
s=in_succ(ptr);
p=in_pred(ptr);
if(ptr->lthread==fal)
p->right=s;
else{
	if(ptr->rthread==fal)
	s->left=p;
}
free(ptr);
return root;
}

struct node *case_c(struct node *root,struct node *par,struct node *ptr)
{
struct node *succ,*parsucc;
parsucc=ptr;
succ=ptr->right;
	while(succ->left!=NULL)
	{
	parsucc=succ;
	succ=succ->left;
	}
	ptr->info=succ->info;
	if(succ->lthread==tru && succ->rthread==tru)
	root=case_a(root,parsucc,succ);
	else
	root=case_b(root,parsucc,succ);
	return root;	
}

struct node *in_succ(struct node *ptr)
{
	if(ptr->lthread==tru)
	return ptr->right;
	else
	{
		ptr=ptr->right;
		while(ptr->lthread==fal)
		ptr=ptr->left;	
	return ptr;	
	}
}

struct node *in_pred(struct node *ptr)
{
	if(ptr->lthread==tru)
		return ptr->left;
	else{
		ptr=ptr->left;
		while(ptr->rthread==fal)
		ptr=ptr->right;
		return ptr;
	}
}

void display(struct node *p, int level)
{
 int i;
 if(p == NULL)
  return;
 else
 {
 	if(p->rthread==fal)
  display(p->right, level+1);
  printf("\n\n");
  for(i = 0; i<level; i++)
   printf("\t");
  printf("%d", p->info);
  if(p->lthread==fal)
  display(p->left, level+1);
 }
 
}
void inorder( struct node *root)
{
        struct node *ptr;
        if(root == NULL )
        {
                printf("Tree is empty");
                return;
        }

        ptr=root;
        /*Find the leftmost node */
        while(ptr->lthread==false)
                ptr=ptr->left;

        while( ptr!=NULL )
        {
                printf("%d ",ptr->info);
                ptr=in_succ(ptr);
        }
}

void preorder(struct node *root )
{
        struct node *ptr;
        if(root==NULL)
        {
                printf("Tree is empty");
                return;
        }
        ptr=root;

        while(ptr!=NULL)
        {
                printf("%d ",ptr->info);
                if(ptr->lthread==false)
                        ptr=ptr->left;
                else if(ptr->rthread==false)
                        ptr=ptr->right;
                else
                {
                        while(ptr!=NULL && ptr->rthread==true)
                                ptr=ptr->right;
                        if(ptr!=NULL)
                                ptr=ptr->right;
                }
        }
}
