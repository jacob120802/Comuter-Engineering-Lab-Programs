#include <stdio.h>
int fibonacci(int n)
{
	if(n == 0 || n == 1)
		return n;
	else
		return(fibonacci(n - 1) + fibonacci(n  - 2));
}
int main()
{
	int a=0, n, i;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Fibonacci series terms are: ");
	for(i = 1; i<= n; i++)
	{
		printf("\n%d", fibonacci(a));
		a++;
	}
	return 0;
}