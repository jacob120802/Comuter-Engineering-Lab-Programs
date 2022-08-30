#include <stdio.h>
void merge(int a[],int low,int mid,int high)
{
	int h, i, j, k, temp[50];
    h = low;
	i = low; 
	j =	mid+1; 
	while((h<=mid) && (j<=high))
	{
		if (a[h]<=a[j])
		{
			temp[i]=a[h];
			h=h+1;
		}
		else
		{
			temp[i]=a[j];
			j=j+1;
		}
		i=i+1;
	}
	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			temp[i]=a[k];
			i=i+1;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			temp[i]=a[k];
			i=i+1;
		}
	}
	for(k=low;k<=high;k++)
	{
		a[k]=temp[k];
	}
}
void mergeSort(int a[],int low,int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main()
{
    int i, n, a[50];
    printf("No. of elements in array: ");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
         scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n - 1);
    printf("Sorted array after merge sort:\n");
    for(i = 0;i < n; i++)
    {
         printf("%d ",a[i]);
    }
   return 0;
}
