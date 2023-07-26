#include<stdio.h>
int main()
{
	int data[30];
	int stuff[30];
	int i,j,count=0;
	int n;
	printf("FLAG: 01111110\n");
	printf("Enter number of data bits:");
	scanf("%d",&n);
	printf("Enter data bits:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	printf("Before stuffing:");
	for(i=0;i<n;i++)
	{
		printf("%d",data[i]);
	}
	for(i=0,j=0;i<n;i++,j++)
	{
		stuff[j]=data[i];
		if(data[i]==1)
		{
			count++;
			if(count==5)
			{
				j=j+1;
				stuff[j]=0;
				count=0;
			}
		}
		else
		{
			count=0;
		}
	}
	printf("\nAfter stuffing:\n");
	for(i=0;i<j;i++)
	{
		printf("%d",stuff[i]);
	}
}
