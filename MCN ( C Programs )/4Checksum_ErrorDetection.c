#include<stdio.h>
#include<math.h>
 
int sender(int arr[10],int n)
{
    int checksum,sum=0,i;
    printf("\nSENDER SIDE\n");
    for(i=0;i<n;i++)
    sum+=arr[i];
    printf("SUM IS: %d",sum);
    checksum=~sum;    //1's complement of sum
    printf("\nCHECKSUM IS:%d",checksum);
    return checksum;
}
 
void receiver(int arr[10],int n,int sch,int recieved[10])
{
    int checksum,sum=0,i;
    printf("\n\nRECEIVER SIDE\n");
    for(i=0;i<n;i++)
        sum+=recieved[i];
    printf("SUM IS:%d",sum);
    sum=sum+sch;
    checksum=~sum;    //1's complement of sum
    printf("\nCHECKSUM IS:%d",checksum);
    if(checksum!=0)
    {
    	printf("\nError present in the message.");
	}
	else
	{
		printf("\nNo error in the message since checksum in 0.");
	}
}
 
int main()
{
    int n,sch,rch;
    printf("\nENTER SIZE OF THE BLOCK:");
    scanf("%d",&n);
    int arr[n];
    printf("ENTER THE ELEMENTS OF THE ARRAY TO CALCULATE CHECKSUM (ONE BLOCK ON EACH LINE):\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sch=sender(arr,n);
    int recieved[n];
    printf("\n\nEnter recieved data:\n");
	for(int i=0;i<n;i++)
    {
    	scanf("%d",&recieved[i]);
	}
    receiver(arr,n,sch,recieved);
}
