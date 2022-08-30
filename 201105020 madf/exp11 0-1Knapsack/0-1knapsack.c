#include<stdio.h>
int weight[20],profit[20],selected[20]={0},table[20][20],capacity;
int max(int a,int b)
{
    if(a>b)
	{
        return a;
    }
    return b;
}
void knapsack(int n)
{
    for(int i=0;i<=capacity;i++)
	{
        table[0][i] = 0;
    }
    for(int i=0;i<=n;i++)
	{
        table[i][0] = 0;
    }
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=capacity;j++)
		{
            if(weight[i] <=j)
			{
                table[i][j] = max(table[i-1][j],table[i-1][j-weight[i]]+profit[i]);
            }
            else
			{
                table[i][j] = table[i-1][j];
            }
        }
    }
    //Now we have to identify the elements.
    int netCap = capacity;
    for(int i=n;i>=1 && netCap !=0;i--)
	{
        if(table[i][netCap] != table[i-1][netCap])
		{
            selected[i] = 1;
            netCap = netCap - weight[i];
        }
        else
		{
            selected[i] = 0;
        }
    }
    int maxProfit = 0;
    printf("\nThe items selectes are:\n");
    for(int i=1;i<=n;i++)
	{
		printf("x[%d] -> ",i);
        if(selected[i])
		{
            printf("%d ",1);
            maxProfit += profit[i];
        }
        else
        {
        	printf("%d ",0);
		}
        printf("\n");
    }
    printf("\nMaximum profit = %d",maxProfit);
}
int main()
{
    int n;
    printf("Enter the number of objects:\t");
    scanf("%d",&n);
    printf("Enter the profit and weight of each of the following item:\n");
    for(int i=1;i<=n;i++)
	{
		printf("Item %d: " ,i);
        scanf("%d",&profit[i]);
        scanf("%d",&weight[i]);
    }
    printf("Enter the maximum capacity of the knapsack:\t");
    scanf("%d",&capacity);
    knapsack(n);
    return 0;
}