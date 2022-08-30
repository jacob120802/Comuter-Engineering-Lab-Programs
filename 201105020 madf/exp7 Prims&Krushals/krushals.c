#include<stdio.h>
int visited[10]={0};
void kruskal(int w[10][10],int n)
{
 	int min,sum=0,i,j;
 	int ne=0;	//to keep track of no. of edges in MST, should be n-1;
	int u,v;	//purpose to check if its not a self loop.
	int a,b;	//for source and Destination of the edge.
 	while(ne<n-1)
 	{
  		min=999;
  		for(i=1;i<=n;i++)
   			for(j=1;j<=n;j++)
    				if(w[i][j]<min)
    				{
    	 				min=w[i][j];
     					u=a=i;
     					v=b=j;
    				}
  		while(visited[u])
   			u=visited[u];
  		while(visited[v])
   			v=visited[v];
  		if(u!=v)	//shouldn't be a self loop
  		{
  	 		ne++;
   			sum+=min;
   			printf("\nEdge %d from ( %d to %d ) --> Cost: %d",ne,a,b,min);
   			visited[v]=u;	//marks the destination accordingly.
  		}
  		w[a][b]=w[b][a]=999;
 	}
 	printf("\n\n Minimum Cost : %d",sum);
}
int main()
{
 	int w[10][10],n,i,j;
 	printf("\nProgram to implement Kruskal's Algorithm : \n");
 	printf("\nEnter no. of vertices : ");
 	scanf("%d",&n);
 	printf("Enter the cost adjacency matrix : \n");
 	for(i=1;i<=n;i++)
  		for(j=1;j<=n;j++)
   			scanf("%d",&w[i][j]);
 	for(i=1;i<=n;i++)
  		for(j=1;j<=n;j++)
   			if(w[i][j]==0)
    				w[i][j]=999;
 	kruskal(w,n);
}