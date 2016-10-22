#include<stdio.h>
void main()
{
	int min,max,mid,a[20],n,i,search,ctr=0;
	printf("size");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("search");
	scanf("%d",&search);
		
	min=0;max=n-1;
	while(min<=max)
	{
		mid=(min+max)/2;
		if(search==a[mid])
		{
			ctr++;
			break;
		}
		else if(search<a[mid])
			max=mid-1;
		else if(search>a[mid])
			min=mid+1;
	}
	if(ctr==1)
		printf("Found");
	else
		printf("Not Found");	
}
