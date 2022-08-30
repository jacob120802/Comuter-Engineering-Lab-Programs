#include<stdio.h>
#define SIZE 100
int search(int a[], int n, int searchValue);

int main()
{
	int i, n, searchValue, a[SIZE], index;

	printf("Enter the number of elements : ");
	scanf("%d", &n);

	printf("Enter the elements: ");
	for(i = 0; i<n; i++)
		scanf("%d",&a[i]);

	printf("Enter the value to be searched: ");
	scanf("%d", &searchValue);

	index = search(a, n, searchValue);

	if(index == -1)
		printf("%d not found in the array\n", searchValue);
	else
		printf("%d found at index %d\n", searchValue, index);
	return 0;
}

int search(int a[], int n, int searchValue)
{
	int i;
	for(i = 0; i<n; i++)
	{
		if(a[i] == searchValue)
			return i;
	}
	return -1;
}