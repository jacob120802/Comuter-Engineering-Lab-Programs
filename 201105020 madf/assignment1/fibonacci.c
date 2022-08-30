#include<stdio.h>
int count = 0;
int main()    
{    
	 int n1=0,n2=1,n3,i,num;    
	 printf("Enter the no. of elements in sereis: ");    
	 scanf("%d",&num);    
	 printf("\nFibonacci Series: %d %d",n1,n2);   
	 for(i=2;i<num;++i)   
	 {    
		  count++;
		  n3=n1+n2; count++;    
		  printf(" %d",n3); count++;   
		  n1=n2; count++;   
		  n2=n3; count++;   
	 } count++;
	 printf("\nCount: %d", count); 
	  return 0;  
}  