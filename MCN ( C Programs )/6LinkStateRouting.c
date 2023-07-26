#include<stdio.h>
#define MAX 100
int main()
{
	int costmat[MAX][MAX];
	int last[MAX];
	int dist[MAX];
	int flag[MAX];
	int count,i,j,k,v,w,min;
	int src;
	printf("Enter number of routers:");
	scanf("%d",&count);
	printf("Enter cost matrix:\n");
	for(i=0;i<count;i++)
	{
		for(j=0;j<count;j++)
		{
			scanf("%d",&costmat[i][j]);
			if(costmat[i][j]<0)
			{
				costmat[i][j]=1000;
			}
		}
	}
	printf("Enter source router:");
	scanf("%d",&src);
	for(i=0;i<count;i++)
	{
		last[i]=src;
		dist[i]=costmat[src][i];
		flag[i]=0;
	}
	flag[src] = 1;
	for(i=0;i<count;i++)
	{
		min=99999;
		for(j=0;j<count;j++)
		{
			if (!flag[j])
				if(dist[j]<min)
				{
					min=dist[j];
					v=j;
				}
		}
		flag[v]=1;
		for(j=0;j<count;j++)
		{
			if (!flag[j])
			{
				if(min+costmat[v][j]<dist[j])
				{
					dist[j]=min+costmat[v][j];
					last[j]=v;
				}
			}
		}
	}
	for(i=0;i<count;i++)
	{
		printf("\n%d->%d Path=%d\n",src,i,i);
		w=i;
		while(w!=src)
		{
			printf("\n<--%d",last[w]);
			w=last[w];
		}
		printf("Shortest path cost:%d",dist[i]);
	}
	
}
