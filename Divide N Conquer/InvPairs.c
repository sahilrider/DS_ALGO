#include<stdio.h>

int merge(int a[],int temp[],int l,int mid,int h)
{
	int i,j,k,res=0;
	i=l; j=mid; k=l;
	while((i<mid)&&(j<=h))
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
		{
			temp[k++]=a[j++];
			res+=mid-i;
		}
	}
	
	//copy remaining from left subarray
	while(i<mid)
		temp[k++]=a[i++];
	
	//copy remaining from right subarray
	while(j<=h)
		temp[k++]=a[j++];
	
	//copy temp to a[]
	for(i=l;i<=h;i++)
		a[i]=temp[i];
	//printf("%d\n",res);
	return res;
}

int mergesort(int a[],int temp[],int l,int h)
{
	int mid,res=0;
	if (l<h)
	{
		mid=(l+h)/2;
		res=mergesort(a,temp,l,mid);		//left
		res+=mergesort(a,temp,mid+1,h);		//right
		
		res+=merge(a,temp,l,mid+1,h);		//merging
	}
	return res;
}

int main()
{
	int n,a[50],temp[50],i,res;
	printf("Enter size:");
	scanf("%d",&n);
	printf("Enter elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	res=mergesort(a,temp,0,n-1);
	printf("Inversion Pairs: %d \n",res);
	return 0;
}
