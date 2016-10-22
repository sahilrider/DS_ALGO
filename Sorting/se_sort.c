#include<stdio.h>

void sel_sort(int a[],int n)
{
	int i,j,min,mini;
	for(i=0;i<n-1;i++)
	{
		min=a[i]; mini=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				mini=j;
			}
		}
		a[mini]=a[i];
		a[i]=min;
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
	sel_sort(a,n);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
