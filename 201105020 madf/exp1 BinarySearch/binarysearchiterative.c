#include <stdio.h>
int count = 0; 
int main()
{
	int i, low, high, mid, n, key, array[100];
	printf("Enter number of elements in array: ");
	scanf("%d",&n);
	printf("Enter elements in array (in ascending order): ");
	for(i = 0; i < n; i++)
		scanf("%d",&array[i]);
	printf("Enter value to find location for: ");
	scanf("%d", &key);
	low = 0;
	high = n - 1;
	mid = (low+high)/2;
	while (low <= high) 
	{
		if(array[mid] < key)
			low = mid + 1;
		else if (array[mid] == key) 
		{
			printf("Element %d found at location %d", key, mid+1);
			break;
		}
		else
			high = mid - 1;
		mid = (low + high)/2;
	}
	if(low > high)
		printf("Not found! Element %d isn't present in the array", key);
	return 0;
}