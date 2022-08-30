#include<stdio.h>
#include<stdlib.h>
float max_profit(int p[],int w[],int m,int n){
	float wxi=0,pxi=0;
	int i,max,s;
	int pi[30],wi[30];
	for(i=0;i<n;i++){
		pi[i]=p[i];
		wi[i]=w[i];
	}
	while(m>0){
		max=0;
		for(i=0;i<n;i++){
			if(max<pi[i]){
				max=pi[i];
				s=i;
			}
		}
		if(wi[s]<=m){
			
			pxi=(pxi+pi[s])*1.0;
			m=(m-wi[s]);
		}
		else{
			if(m>0 && wi[s]>m){
				pxi=(pxi+((pi[s]*m*1.0)/wi[s]))*1.0;
				m=0;
			}
		}
		pi[s]=0;
	}
	return pxi;
}
float min_weight(int p[],int w[],int m,int n){
	float wxi=0,pxi=0;
	int i,min,s;
	int pi[30],wi[30];
	for(i=0;i<n;i++){
		pi[i]=p[i];
		wi[i]=w[i];
	}
	while(m>0){
		min=999999999;
		for(i=0;i<n;i++){
			if(min>wi[i]){
				min=wi[i];
				s=i;
			}
		}
		if(wi[s]<=m){
	
			pxi=(pxi+pi[s])*1.0;
			m=(m-wi[s]);
		}
		else{
			if(m>0 && wi[s]>m){
				pxi=(pxi+((pi[s]*m*1.0)/wi[s]))*1.0;
				m=0;
			}
		}
		wi[s]=999999999;
	}
	return pxi;
}
float piwi(int p[],int w[],int m,int n){
	float wxi=0,pxi=0,arr[30],max;
	int i,s;
	int pi[30],wi[30];
	for(i=0;i<n;i++){
		pi[i]=p[i];
		wi[i]=w[i];
	}
	for(i=0;i<n;i++){
		arr[i]=((pi[i]*1.0/wi[i]));
	}
	while(m>0){
		max=0;
		for(i=0;i<n;i++){
			if(max<arr[i]){
				max=arr[i];
				s=i;
			}
		}
		if(wi[s]<m){
	
			pxi=(pxi+pi[s])*1.0;
			m=(m-wi[s]);
		}
		else{
			if(m>0 && wi[s]>m){
				pxi=(pxi+((pi[s]*m*1.0)/wi[s]))*1.0;
				m=0;
			}
		}
		arr[s]=0;
	}
	return pxi;
}
float returnMax(float pi,float wi,float piwi){
	float opts;
	if(pi>wi){
		if(pi>piwi){
			opts=pi;
			return opts;
		}
		else{
			opts=piwi;
			return opts;
		}
	}
	else{
		if(wi>opts){
			opts=wi;
			return wi;
		}
		else{
			opts=piwi;
			return opts;
		}
	}
}
int main(){
	int n ,i,w[30],p[30],m,choice;
	printf("Enter the number of elements: ");
    scanf("%d",&n);
	printf("Enter the maximum capacity of bag: ");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
        printf("Enter weight and price of the element %d: ",i+1);
        scanf("%d%d",&w[i],&p[i]);
    }
	float p1,w1,pw,opts;
	while(1)
	{
		printf("\n1. Items with Maximum price\n");
		printf("2. Items in Minimum weight\n");
		printf("3. In Decreasing order of Pi/Wi\n");
		printf("4. Find Optimal soln\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				p1=max_profit(p,w,m,n);
				printf("\n Profit by max pi: %f\n",p1);
				break;
				
			case 2:
				w1=min_weight(p,w,m,n);	
				printf("\n Profit by min wi: %f\n",w1);
				break;
				
			case 3: 
				pw=piwi(p,w,m,n);
				printf("\n Profit by decreasing value of pi/wi: %f\n",pw);
				break;
				
			case 4:
				p1=max_profit(p,w,m,n);
				w1=min_weight(p,w,m,n);
				pw=piwi(p,w,m,n);
				opts=returnMax(p1,w1,pw);
				if(opts==p1){
					printf("\tMaximum Profit = %.2f\n",p1);
					printf("\n Max pi is the optimal solution\n");
				}
				if(opts==w1){
					printf("\tMaximum Profit = %.2f\n",w1);
					printf("\n Min wi is the optimal solution\n");
				}
				if(opts==pw){
					printf("\tMaximum Profit = %.2f\n",pw);
					printf("\n Decresing value of pi/wi is the optimal solution\n");
				}
				break;
				
			case 5:
				exit(1);
				
			default:
				printf("Invalid choice. Try again!!!\n");
				break;
		}
	}
	return 0;
}
