#include<stdio.h>
int main()
{
	int n,a[50],i,j,f,l,x;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter X:");
	scanf("%d",&x);
	f=0;
	l=n-1;
	while(f<l)
	{
		if(a[f]+a[l]==x)
		{
			break;
		}
		else if(a[f]+a[l]>x)
			l--;
		else
			f++;
	}
	printf("%d %d\n",a[f],a[l]);
	return 0;
}
