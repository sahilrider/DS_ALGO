#include<stdio.h>
void main()
{
	int i,j,k,a[3][3],b[3][3],c[3][3],sum;
	printf("enter the elements of the first matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("enter the elements of the second matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	
	printf("the first matrix is\n");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf(" %d",a[i][j]);
		}
	}
	
	printf("\nthe second matrix is\n");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf(" %d",b[i][j]);
		}
	}
	
	//Multiplication logic
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			sum=0;
			for(k=0;k<3;k++)
			{
				sum+=a[i][k]*b[k][j];
			}
			c[i][j]=sum;
		}
	}
	
	printf("\n the multiplication matrix is\n");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf(" %d",c[i][j]);
		}
	}
}
