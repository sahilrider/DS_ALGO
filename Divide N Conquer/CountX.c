#include<stdio.h>
int main()
{
	int n,a[50],i,j,f,l,x,k1,k2,mid;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter X:");
	scanf("%d",&x);
	f=0;
	l=n-1;
	mid=(f+l)/2;
	while(f<=l)
	{
		//printf("%d %d %d\n",f,l,mid);
		if(a[mid]==x && (mid==0 || x>a[mid-1]))
		{
			
			k1=mid;
			//printf("%d\n",k1);
			break;
		}
		else if(x>a[mid])
			f=mid+1;
		else
			l=mid-1;
		mid=(f+l)/2;
	}
	f=0;
	l=n-1;
	mid=(f+l)/2;
	while(f<=l)
	{
		//printf("%d %d %d\n",f,l,mid);
		if(a[mid]==x && (mid==n-1 || x<a[mid+1]))
		{
			
			k2=mid;
			//printf("%d",k2);
			break;
		}
		else if(x<a[mid])
			l=mid-1;
		else
			f=mid+1;
		mid=(f+l)/2;
	}
	printf("Ans=%d",k2-k1+1);
	return 0;
}

