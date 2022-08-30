#include <stdio.h>
#include <string.h>
int f[50];
void KMPFailureFunction(char P[])
{
    int i = 1,j = 0,m = strlen(P);           
    f[0] = 0;                                 
    while(i<m)
	{                                
        if (P[j] == P[i])
		{                     
            f[i] = j + 1;                     
            i++;                              
            j++;                              
        } 
        else if(j > 0)
		{                      
            j = f[j-1];                     
        }
        else
		{                                  
            f[i] = 0;                          
            i++;                             
        }
    }
}
int KMPMatch(char T[],char P[])
{
    int n = strlen(T),m = strlen(P);            
    int i=0,j = 0;                             
    KMPFailureFunction(P);                      
    while(i<n)
	{                                
        if (P[j] == T[i])
		{                    
            if (j == m - 1)
			{                    
               
                return i - m + 1;
            }
            i++;                               
            j++;                              
        }
        else if (j > 0)
		{                     
            j = f[j-1];                         
        }
        else
		{
            i++;                                
        }
    }
    return -1;
}
int main()
{
    int index;
    char T[50],P[50];
    printf("Enter the string T: ");
    scanf("%s",T);
    printf("Enter the string P: ");
    scanf("%s",P);
    index = KMPMatch(T,P);
    printf("\n");
    if (index == -1)
	{
        printf("There is no substring of %s matching %s\n",T,P);
    }
    else
	{
        printf("Pattern %s is found at index %d in String %s",P,index+1,T);
    }
    printf("\n");
    return 0;
}
