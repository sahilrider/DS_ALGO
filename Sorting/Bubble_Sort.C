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
	int i;
	int A[]={2,6,9,3,5,1};
	bubblesort(A,6);
	for(i=0;i<6;i++)
	{
		printf("%d",A[i]);
	}
}
