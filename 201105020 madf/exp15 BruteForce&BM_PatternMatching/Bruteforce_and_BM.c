#include <stdio.h>
#include <string.h>
#define MAX 100
char T[MAX],P[MAX];
int BruteForceMatch(char T[],char P[])
{
    int n = strlen(T),m  = strlen(P),j;            
    for(int i=0;i<=n-m;i++)
	{                        
        j = 0;                                     
        while(j < m && T[i+j] == P[j])
		{            
            j++;                                   
        }
        if (j == m)
		{                     
            return i;
        }
    }
    return -1;
}
int min(int x,int y)
{
    return x < y ? x : y;
}
int last(char c,int i)
{
    for(int j=i-1;j>=0;j--)
	{                       
        if (c == T[j])
		{                       
            return j;           
        }
    }
    return MAX;
}
int BMMatch(char T[],char P[])
{
    int n = strlen(T),m = strlen(P);                
    int i = m-1,j = m-1;                           
    do
	{                                             
        if (P[j] == T[i])
		{                          
            if (j == 0)
			{                         
                return i;           
            }
            else
			{                                   
                i--;                         
                j--;                               
            }
        }
        else
		{
            i = i + m - min(j,1+last(T[i],i));      
            j = m -1;                               
        }
    }while(i < n-1);
    return -1;
}
int main()
{
    int choice,index;
    printf("Enter the string T: ");
    scanf("%s",&T);
    printf("Enter the string P: ");
    scanf("%s",&P);
    while(1)
	{
        printf("\n1. Brute Force Algorithm\n");
        printf("2. BM Pattern Matching Algorithm\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
		{
            case 1:
                    index = BruteForceMatch(T,P);
                    if (index == -1)
					{
                        printf("There is no substring of %s matching %s\n",T,P);
                    }
                    else
					{
                        printf("Pattern %s is found at index %d in String %s\n",P,index+1,T);
                    }
                    break;
            case 2: 
                    index = BMMatch(T,P);
                    if (index == -1)
					{
                        printf("There is no substring of %s matching %s\n",T,P);
                    }
                    else
					{
                        printf("Pattern %s is found at index %d in String %s\n",P,index+1,T);
                    }
                    break;
            case 3: return 0;
            default:printf("Invalid choice\n");
                    break;        
        }
    }
    return 0;
}