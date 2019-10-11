#include<stdio.h>
int main()
{
	int n,m,a[50][50],i,j,x,l,u,mid;
	printf("Enter the size of array\n");
	scanf("%d%d",&n,&m);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	printf("Enter X:");
	scanf("%d",&x);
	
	l=0;
	u=m*n-1;
	mid=(l+u)/2;
	while(l<u)
	{
		
		if(x==a[mid/m][mid%m])
		{
			printf("Found at %d %d ",mid/m,mid%m);
			break;
		}
		else if(x>a[mid/m][mid%m])
		{
			l=mid+1;
		}
		else
		{
		u=mid-1;
		}
		mid=(l+u)/2;
	}
	return 0;
}
