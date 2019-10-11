#include <stdio.h>
 
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
int search(int a[],int n,int key)
{
	ins_sort(a,n);
	
	int low,high,mid;
	low=0;
	high=n-1;
	while(low<high)
	{
		mid=low+(high-low)*( (key-a[low])/(a[high]-a[low]) );
		if(a[mid]==key)
		{
			return 1;
		}
		else if(a[mid]>key)
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;	
}
int main(void)
{
	int n,i,j,res,key;
	
	printf("Enter the size of the array:");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("Enter the element to be searched:");
	scanf("%d",&key);
 
	res=search(a,n,key);
	if(res==1)
		printf("Found\n");
	else
		printf("Not Found\n");

	return 0;
}
