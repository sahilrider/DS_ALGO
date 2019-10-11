#include <stdio.h>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
int f(int a[],int la,int ha,int b[],int lb,int hb)
{
	int mid1,mid2,ans;
	mid1=(la+ha)/2;
	mid2=(lb+hb)/2;
	if(ha-la+1<=2)
	{
		
		ans=(max(a[la],b[lb])+min(a[ha],b[hb]))/2;
		return ans;
	}
	else
	{
		if(a[mid1]==b[mid2])
			return a[mid1];
		else if(a[mid1]>b[mid2])
			return f(a,la,mid1,b,mid2,hb);
		else
			return f(a,mid1,ha,b,la,mid2);
	}
}
int main(void)
{
	int n,a[50],b[50],i,ans;
	printf("Enter size:");
	scanf("%d",&n);
	printf("Enter elements for first array:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter elements for second array:");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	ans=f(a,0,n-1,b,0,n-1);
	printf("MEDIAN=%d",ans);
	return 0;
}

