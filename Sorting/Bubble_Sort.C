#include<stdio.h>
void bubblesort(int A[],int n)
{
	int i,k,temp;
	for(k=0;k<n-1;k++)
	{
		int flag=0;
		for(i=0;i<n-k-1;i++)
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
	int i,j;
	printf("Enter no.of inputs\n");
	scanf("%d".&j);
	int A[j];
	printf("Enter data\n");
	for(int k=0;k<j;k++)
	{
	  scanf("%d",&A[i]);
	  printf("Enter next data\n");
	}
	
	bubblesort(A,j);
	for(i=0;i<j;i++)
	{
		printf("%d",A[i]);
	}
}
