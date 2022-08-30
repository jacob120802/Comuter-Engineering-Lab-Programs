#include<stdio.h>  
int count = 0;
int main()
{    
	int n,i,flag=0;    
	printf("Enter the number to check if prime:");    
	scanf("%d",&n);  
	count++;
	if (n == 0 || n == 1)
	{
		flag = 1;
	}   
	else
	{
		for(i=2;i<=n/2;i++)    
		{    
		count++;
		count++;
			if(n%i==0)    
			{    
				printf("Number is not prime"); count++;    
				flag=1; count++;   
				break;    
			}    
		}count++;
	}
	count++;    
	if(flag==0)    
	{
		printf("Number is prime");count++;  
	}   
	printf("\nCount: %d", count);
	return 0;  
 }