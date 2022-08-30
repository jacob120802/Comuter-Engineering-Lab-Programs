#include <stdio.h>  
int binarySearch(int a[], int beg, int end, int val)    
{    
    int mid;    
    if(end >= beg)     
    {        
		mid = (beg + end)/2;    
        if(a[mid] == val)    
        {                 
            return mid+1;    
        }    
        else if(a[mid] < val)     
        {  
            return binarySearch(a, mid+1, end, val);    
        }     
        else     
        {  
            return binarySearch(a, beg, mid-1, val);    
        }          
    }    
    return -1;     
}   
int main() 
{  
	int a[1000],i,n,val;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    printf("Enter elements in array (in ascending order): ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter value to find position for: ");
	scanf("%d", &val);
	int res = binarySearch(a, 0, n-1, val);   
	if (res == -1)
	{
		printf("Element is not present in array");
	}  
	else 
	{
		printf("Element is present at %d position of array", res);
	}   
	return 0;  
}  