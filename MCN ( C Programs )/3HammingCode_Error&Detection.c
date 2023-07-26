#include<stdio.h>
int main()
{
	int data[10],c,i,rec[10];
	int c1,c2,c3;
	printf("Enter 4 bits input one by one:");
	scanf("%d",&data[0]);
	scanf("%d",&data[1]);
	scanf("%d",&data[2]);
	scanf("%d",&data[4]);
	//Calculate parity bits
	data[6]=data[0]^data[2]^data[4];
	data[5]=data[0]^data[1]^data[4];
	data[3]=data[0]^data[1]^data[2];
	printf("Sent data");
	for(i=0;i<7;i++)
	{
		printf("%d",data[i]);
	}
	printf("Enter recieved data:");
	for(i=0;i<7;i++)
	{
		scanf("%d",&rec[i]);
	}
	//Calculating recieved parity bits
	c1=rec[6]^rec[0]^rec[2]^rec[4];
	c2=rec[5]^rec[0]^data[1]^rec[4];
	c3=rec[3]^rec[0]^rec[1]^rec[2];
	c=c1+c2*2+c3*4;
	if(c==0)
	{
		printf("No error found");
	}
	else{
		if(rec[7-c]==0)
			rec[7-c]=1;
		else
			rec[7-c]=0;
		printf("Corrected message is:");
		for(i=0;i<7;i++)
		{
			printf("%d",rec[i]);
		}
	}
	
	
}
