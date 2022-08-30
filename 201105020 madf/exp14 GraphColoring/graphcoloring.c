#include<stdio.h>
int n;
int count=0;
int g[50][50];
int x[50]={0};
void nextValue(int m, int k)
{
	 int j;
	 while(1)
	 {
		  x[k]=(x[k]+1)%(m+1);
		  if(x[k]==0)
		  {
		   	return;
		  }
		  for(j=1;j<=n;j++)
		  {
		   	if(g[k][j]==1&&x[k]==x[j])
		    	break;
		  }
		  if(j==(n+1))
		  {
		   	return;
		  }
	 }
}
void GraphColoring(int m, int k)
{
	 while(1)
	 {
		  nextValue(m, k);
		  if(x[k]==0)
		  {
		   	  return;
		  }
		 if(k==n)
		 {
			  printf("Solution %d => ",++count);
			  for(int i=1;i<=n;i++)
			  {
			  	 printf("%d ", x[i]);
			  }
			  printf("\n");
		 }
		 else
		  	  GraphColoring(m, k+1);
	 }
}
int main()
{
	 int i, j, m;
	 printf("Enter the number of nodes: " );
	 scanf("%d", &n);
	 //If edge exists then enter 1 else enter 0 in cost adjency matrix
	 printf("Enter Cost Adjacency Matrix for Graph:\n");
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n;j++)
		  {
		   	scanf("%d", &g[i][j]);
		  }
	 }
	 printf("Enter the number of colors available:");
	 scanf("%d",&m);
	 printf("Possible Solutions to graph coloring problem are-\n");
	 for(int i=1; i<=n; i++)
	 {
	 		x[i] = 0;
	 }
	 GraphColoring(m,1);
	 printf("\nThe total number of solutions is %d", count);
	 return 0;
}