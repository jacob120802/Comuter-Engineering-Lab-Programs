#include<stdio.h>
#include<conio.h>
int count;   //to count no of solutions
int w[10];   //items
int m;       //required sum
int x[10];   //items whose sum is d
void subset(int wsf,int k,int s)
{
	int i;
	x[k]=1;
	if(wsf+w[k]==m)
	{
		printf("\n Subset solution %d-\n   (",++count);
		for(i=0;i<=k;i++)
		{
			if(x[i]==1)
			printf(" %d",1);
			else
        	printf(" %d",0);
		}
		printf(" ) ==> (");
		for(i=0;i<=k;i++)
		{
			if(x[i]==1)
			printf(" %d",w[i]);
		}
		printf(" )");
		return;
	}
		if(wsf+w[k]+w[k+1]<=m)
		subset(wsf+w[k],k+1,s-w[k]);
		if((wsf+s-w[k]>=m) && (wsf+w[k+1]<=m))
		{
			x[k]=0;
			subset(wsf,k+1,s-w[k]);
		}
}
int main()
{
	int sum=0;
	int i,n;
	printf("Enter no. of elements in set: ");
	scanf("%d",&n);
	printf("Enter elements in set (in increasing order): ");
	for(i=0;i<n;i++)
	scanf("%d",&w[i]);
	printf("Enter required sum: ");
	scanf("%d",&m);
	printf("\nSOLUTIONS OF SUM  OF SUBSET PROBLEM: ");
	for(i=0;i<n;i++)
		sum=sum+w[i];
	subset(0,0,sum);
	return 0;
}