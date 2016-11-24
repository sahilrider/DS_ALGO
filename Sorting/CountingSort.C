#include<stdio.h>
#define range 10

void countingsort(int a[],int n)
{
	int output[n];			//output array
	int count[range]={0};		//count array
	int i;
	for(i=0;i<n;i++)						//build the count array
	{
		count[a[i]]++;
	}	
	
	for(i=1;i<range;i++)								//sum the count array 
		count[i]=count[i]+count[i-1];
	
	for(i=0;i<n;i++)										//build output array
	{
		output[count[a[i]]-1]=a[i];
		count[a[i]]--;
	}
	
	for(i=0;i<n;i++)				//copy output array to main array
		a[i]=output[i];
	
}

void main()
{
	int n,a[100],i;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("Enter the elements in range (0,9):\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	countingsort(a,n);
	printf("Sorted Array:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
