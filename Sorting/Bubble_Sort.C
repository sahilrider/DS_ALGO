#include<stdio.h>
int i,k,n,temp,A[1000];
void bubblesort(int A[],int n)
{

	for(k=0;k<n-1;k++)
	{
		int flag=0;
		for(i=0;i<n-(k+1);i++)
		{
			if(A[i]>A[i+1])
			{
				temp=A[i+1];
				A[i+1]=A[i];
				A[i]=temp;
				flag=1;
			}
		}
		if(flag==0)
		break;
	}
}
int main()
{
	
        printf("enter the number of element:\n");
        	scanf("%d",&n);
        printf("enter the elements:\n");
         	for(i=0;i<n;i++)
			scanf("%d",&A[i]);
        bubblesort(A,n);
	printf("The sorted elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",A[i]);
	}
}
