#include<stdio.h>
int count = 0;
int main()
{
  int i,fact=1,n;
  printf("Enter a number: ");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
  	count++;
    fact=fact*i; count++;
  }count++;
  printf("Factorial of %d is: %d \nCount: %d",n,fact,count);
  return 0;
}