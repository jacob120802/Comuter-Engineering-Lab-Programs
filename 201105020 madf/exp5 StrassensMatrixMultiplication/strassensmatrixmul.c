#include <stdio.h>
#define MAX 2
int A[MAX][MAX],B[MAX][MAX],C[MAX][MAX];
void Strassen(int A[2][2],int B[2][2],int C[2][2])
{
int P,Q,R,S,T,U,V;									
    P = (A[1][1]+A[2][2])*(B[1][1]+B[2][2]);			
    Q = (A[2][1]+A[2][2])*B[1][1];					
    R = A[1][1]*(B[1][2]-B[2][2]);						
    S = A[2][2]*(B[2][1]-B[1][1]);						
    T = (A[1][1]+A[1][2])*B[2][2];						
    U = (A[2][1]-A[1][1])*(B[1][1]+B[1][2]);			
    V = (A[1][2]-A[2][2])*(B[2][1]+B[2][2]);				
    C[1][1] = P + S - T + V;						
    C[1][2] =  R + T;							
    C[2][1] = Q + S;							
    C[2][2] = P + R - Q + U;					
}
int main()
{
    int n = 2,i,j;
    printf("Enter the elements of Matrix A (2 X 2):\n");
    for(i=1; i<=n; i++)
	{
        for(j=1; j<=n; j++)
		{
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the elements of Matrix B (2 X 2):\n");
    for(i=1; i<=n; i++)
	{
        for(j=1; j<=n; j++)
		{
            scanf("%d",&B[i][j]);
        }
    }
    Strassen(A,B,C);
    printf("The Matrix obtained by Strassen's Matrix Multiplication (A x B) is:\n");
    for(i=1; i<=n; i++)
	{
        for(j=1; j<=n; j++)
		{
            printf("%d	",C[i][j]);
		}
        printf("\n");
    }
    return 0;
}   
