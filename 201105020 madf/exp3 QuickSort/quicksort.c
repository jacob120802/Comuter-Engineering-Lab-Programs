#include<stdio.h>
void interchange(int a[25], int i, int j)
{
	int temp;
	temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partition(int a[25], int first, int last)
{
	int i, j, pivot,temp;
	pivot=first;
    i=first;
    j=last;
    while(i<j)
	{
        while(a[i]<=a[pivot]&&i<last)
        {
         	i++;
		}
        while(a[j]>a[pivot])
        {
         	j--;
		}
        if(i<j)
		{
            interchange(a,i,j);
        }
    }
    interchange(a,pivot,j);
    return j;
}
void quicksort(int a[25],int first,int last)
{
   if(first<last)
   {
      int j = partition(a,first,last);
      quicksort(a,first,j-1);
      quicksort(a,j+1,last);
   }
}
int main()
{
   int i, n, a[25];
   printf("No. of elements in array: ");
   scanf("%d",&n);
   printf("Enter array elements: ");
   for(i=0;i<n;i++)
   {
   	scanf("%d",&a[i]);
   }
   quicksort(a,0,n-1);
   printf("Sorted array after quick sort: ");
   for(i=0;i<n;i++)
   {
   	printf(" %d",a[i]);
   }
   return 0;
}