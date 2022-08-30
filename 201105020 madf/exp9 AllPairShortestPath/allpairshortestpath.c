#include<stdio.h>
int min(long a,long b)
{
	return a<b?a:b;
}
int main()
{
	int n,i,j,k;
	printf("Enter the no. of nodes: ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix of the weighted directed graph.:\n");
	int arr[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
		      scanf("%d",&arr[i][j]);
		      if(arr[i][j]==0 && i!=j) 
			  	arr[i][j]=999;
		}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==k || j==k) 
					continue;
				arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
			}
		}	
	}
	printf("\nThe matrix with the shortest distances between all the pairs of vertices:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i][j]==999) 
				printf("INF     ");
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}