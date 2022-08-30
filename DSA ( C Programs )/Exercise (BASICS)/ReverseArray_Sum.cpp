#include <stdio.h>
int findSum(int A[], int N)
{
	if(N <= 0)
		return 0;
	return(findSum(A, N - 1) + A[N -1]);
}
void reverse(int a[], int n)
{
	if(n == 0)
		return;
	else
		printf("%d ", a[n - 1]);
		reverse(a, n - 1);
}
int main()
{
	int i, n;
	printf("Enter no. of elements in array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter orginal array: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Reversed array is: ");
	reverse(arr, size);
	printf("\nSize/Length of array: %d", size);
	printf("\nSum of array = %d", findSum(arr, size));
	return 0;
}
