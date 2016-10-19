#include<stdio.h>

void ins_sort(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	
}

void main()
{
	int n,i;
	printf("Enter the no. of elements:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	ins_sort(a,n);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
