#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void build_max_heap(int a[],int size)
{
	int i;
	for(i=size/2;i>=1;i--)
		heapify(a,i,size);
}

void heapify(int a[],int i,int heapsize)
{
	int ptr,l,r;
	ptr=a[i];
	l=a[2*i];
	r=a[2*i+1];
	int largei=i;
	if(ptr<l && 2*i<=heapsize)
		largei=2*i;
	if(ptr<r && l<r && 2*i+1<=heapsize)
		largei=2*i+1;
	if(largei!=i)
	{
		swap(&a[i],&a[largei]);
		heapify(a,largei,heapsize);
	}
}

void heapsort(int a[],int n)
{
	while(n>0)
	{
		build_max_heap(a,n);
		swap(&a[1],&a[n]);
		n--;
		heapify(a,1,n);
	}
	
}

void main()
{
	int n,i;
	printf("Enter the size of array:");
	scanf("%d",&n);	
	int a[n+2];
	printf("\nEnter the elements:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	heapsort(a,n);
	printf("Sorted Array:");
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	
}
