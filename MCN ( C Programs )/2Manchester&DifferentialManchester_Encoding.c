#include<stdio.h>
#include<string.h>
void manchester(char* ip,int len)
{
	char output[2*len+1];
	for(int i=0;i<len;i++)
	{
		if(ip[i]=='0')
		{
			output[2*i]='1';
			output[2*i+1]='0';
		}
		else
		{
			output[2*i]='0';
			output[2*i+1]='1';
		}
	}
	output[2*len]='\0';
	printf("Manchester:\n");
	printf("%s",output);
}
void differential_manchester(char* ip,int len)
{
	char prev_bit='0';
	char output[2*len+1];
	for(int i=0;i<len;i++)
	{
		if(ip[i]=='0')
		{
			output[2*i]=prev_bit;
			output[2*i+1]=(prev_bit=='0'?'1':'0');
		}
		else
		{
			output[2*i]=(prev_bit=='0'?'1':'0');
			output[2*i+1]=prev_bit;
		}
		prev_bit=output[2*i+1];
	}
	output[2*len]='\0';
	printf("\nDifferential Manchester:\n");
	printf("%s",output);
}
int main()
{
	char input[50];
	printf("Enter input string:");
	scanf("%s",input);
	int len=strlen(input);
	manchester(input,len);
	differential_manchester(input,len);
	
}
