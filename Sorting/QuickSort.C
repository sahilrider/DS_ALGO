#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int l,int h)
{
	int pivot=a[h];
	int i,small=l-1;
	for(i=l;i<=h-1;i++)
	{
		if(a[i]<=pivot)
		{
			small++;
			swap(&a[small],&a[i]);
		}
	}
	small++;
	swap(&a[small],&a[h]);
	return(small);
}
void quicksort(int a[],int l,int h)
{
	if(l<h)
	{
		int p=partition(a,l,h);
		quicksort(a,l,p-1);
		quicksort(a,p+1,h);
		
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
	//int n=6,a[]={10,7,8,9,1,5},i;
	quicksort(a,0,n-1);
	printf("Sorted Array:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
