#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n=0, a=0;
struct customer
{
	long int acc_no;
	float balance;
	char name[50];
	int transactions;
};
void input(struct customer *c, int n)
{
	int i, j, k, d, result, x;
	getchar();
	while(i<n)
	{
		printf("\nEnter details of Customer %d:\n",i+1);
	    	x = 0;
        	for (k=0; k<8; k++)
       		{
       		    d = rand() % 10;
       		    d *= pow(10, k);
       		    x += d;
       		}
    	(c+i)->acc_no = x;
    	(c+i)->balance = 0;
    	(c+i)->transactions = 0;
		printf("Name of Account Holder: ");
		gets((c+i)->name);
		printf("A/C number generated for customer '%s': %d\n", (c+i)->name, (c+i)->acc_no);
		printf("\t\tACCOUNT CREATED!\n");
		i++;
	}
}
int search_acc(struct customer *c, int n)
{
	int acno, i;
	printf("Enter the A/C number for validation: ");
	scanf("%d", &acno);
	for(i=0;i<n;i++)
	{
		if((c+i)->acc_no == acno)
		return i;
	}
	if(i==n)
	return -1;
}
void deposit(struct customer *c, int n)
{
	int i;
	float money;
	i = search_acc(c,n);
	if(i==-1)
		printf("\t\tINVALID ACCOUNT!\n");
	else
	{
		printf("How much money do you want to Deposit:\n");
		scanf("%f", &money);
		if(money < 0)
		{
			printf("INVALID DEPOSIT!\n");
		}
		else
		{
			(c+i)->balance = (c+i)->balance + money;
			printf("\t\tRs %.2f DEPOSITED SUCESFULLY!\nYour current Balance is Rs %.2f\n", money, (c+i)->balance);
			(c+i)->transactions++;
		}
    }
}
void withdraw(struct customer *c, int n)
{
	int i;
	float money;
	i = search_acc(c,n);
	if(i==-1)
		printf("\t\tINVALID ACCOUNT!\n");
	else
	{
		printf("How much money do you want to withdraw:\n");
		scanf("%f", &money);
		if(money < 0)
		{
			printf("\t\tINVALID WITHDRAWAL!\n");
		}
		else if(((c+i)->balance - money) < 500)
		{
			printf("\t\tWITHDRAWAL DECLINED!\nCurrent Account Balance will become less than minimum balance of Rs 500\n");
		}
		else
		{
			(c+i)->balance = (c+i)->balance - money;
		printf("\t\tRs %.2f WITHDRAWAL SUCESSFUL!\nYour current Balance is RS %.2f\n", money, (c+i)->balance);
		(c+i)->transactions++;
		}
	}
}
void check_balance(struct customer *c, int n)
{
	int i;
	i = search_acc(c,n);
	if(i==-1)
		printf("\t\tINVALID ACCOUNT\n");
	else
	{
		printf("Hello, %s: ",(c+i)->name);
		printf("Your Balance for A/C number %d is Rs %.2f\n",(c+i)->acc_no, (c+i)->balance);
		printf("No. of Transactions = %d\n",(c+i)->transactions);
	}
}
int main()
{
	printf("\n************Welcome**********\n\n");
	int ch, n, o, k, index;
	printf("Enter the no. of accounts you want to create: ");
	scanf("%d",&n);
	struct customer* c = (struct customer*) malloc(n * sizeof(struct customer));
	input(c,n);
	do
	{
        new:
        printf("Enter 1 to Sign In\nEnter 2 To Create more Accounts\nEnter 3 To Logout\n");
        scanf("%d",&o);
        if(o==1 || o==2)
		{
            if(o==1)
			{
                index=search_acc(c,n);
            }
            else
			{
                printf("How many more accounts you want to create?\n");
                scanf("%d", &k);
                n=n+k;
                a++;
                c =(struct customer*) realloc(c, n* sizeof(struct customer));
                input(c,n);
                goto new;
            }
        }
        else{
            continue;
        }
        if(index == -1){
            printf("\n\nAccount doesn't exist!\n\n");
            }
        else{
            int ch;
                printf("Your Account has been validated\n");
                printf("\n***WELCOME %s***\n",(c->name));
			do
			{
				printf("\n\n Enter your choice\n 1: Deposit\n 2: Withdrawal\n 3: Check Balance\n 4: Exit\n");
				scanf("%d", &ch);
				switch(ch)
				{
					case 1:	deposit(c, n);
						break;
					case 2:	withdraw(c,n);
						break;
					case 3:	check_balance(c, n);
						break;
					case 4:printf("EXIT\n");
						break;
					default:printf("INVALID CHOICE!\n");
				}
			}while(ch!=4);
		}
	}while(o!=3);
	printf("\n\n************THANKYOU**********\n\n");	
	return 0;
}
