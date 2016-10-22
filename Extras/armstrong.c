#include<stdio.h>
#include<math.h>
void main()
{
	int n,n1,sum,rem,ctr=0;
	for(n=1;n<=10000;n++)
	{
		n1=n;
		ctr=0;
		sum=0;
		while(n1!=0)
		{
			n1=n1/10;
			ctr++;
		}
		n1=n;
		while(n1!=0)
		{
			rem=n1%10;
			sum+=pow(rem,ctr);
			n1=n1/10;
		}
		if(sum==n)
			printf("%d\t",n);
	}
}
