#include<stdio.h>


void countingsort(int a[],int n,int exp)
{
	int output[n];			//output array
	int count[10]={0};		//count array
	int i;
	for(i=0;i<n;i++)						//build the count array
	{
		count[(a[i]/exp)%10]++;
	}	
	
	for(i=1;i<10;i++)								//sum the count array 
		count[i]=count[i]+count[i-1];
	
	for(i=n-1;i>=0;i--)										//build output array
	{
		output[ count[ (a[i]/exp)%10] - 1 ]=a[i];
		count[(a[i]/exp)%10]--;
	}
	
	for(i=0;i<n;i++)				//copy output array to main array
		a[i]=output[i];
}


int getmax(int a[],int n)
{
	int max=a[0];
	int i;
	for(i=0;i<n;i++)
		if(max<a[i])
			max=a[i];
	return max;
}

void radixsort(int a[],int n)
{
	int max,exp;
	max=getmax(a,n);
	printf("%d\n",max);
	for(exp=1; (max/exp)>0 ; exp=exp*10)
	{
		countingsort(a,n,exp);
	}
}

void main()
{
	int n,a[100],i;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	radixsort(a,n);
	printf("Sorted Array:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
