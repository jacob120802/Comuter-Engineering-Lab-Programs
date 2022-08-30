#include<stdio.h>   
int count = 0; 
int main()
{  
	int a[10][10],b[10][10],mul[10][10],n,i,j,k;    
	printf("Enter the no. of rows / column in matrix=");    
	scanf("%d",&n);    
	printf("Enter the First matrix elements=\n");    
	for(i=0;i<n;i++)    
	{    
	count++;
		for(j=0;j<n;j++)    
		{    
		count++;
			scanf("%d",&a[i][j]); count++;   
		} count++;   
	} count++;   
	printf("Enter the Second matrix elements=\n");    
	for(i=0;i<n;i++)    
	{    
	count++;
			for(j=0;j<n;j++)    
			{ 
			count++;   
				scanf("%d",&b[i][j]); count++;    
			} count++;   
	} count++;   
	printf("Multiplication of two n*n matrix=\n");    
	for(i=0;i<n;i++)    
	{ 
	count++;   
		for(j=0;j<n;j++)    
		{   
		count++; 
			mul[i][j]=0;  count++;  
			for(k=0;k<n;k++)    
			{    
			count++;
				mul[i][j]+=a[i][k]*b[k][j];  count++;  
			} count++;   
		} count++;   
	} count++;    
	for(i=0;i<n;i++)    
	{  
	count++;  
		for(j=0;j<n;j++)    
		{   
		count++; 
			printf("%d\t",mul[i][j]); count++;   
		} count++;   
		printf("\n"); count++;    
	} count++;  
	printf("Count = %d", count);
	return 0;  
}