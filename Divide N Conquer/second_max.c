#include<stdio.h>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

typedef struct pair
{
	int m1,m2;
};

struct pair maxpair(int a[],int l, int h)
{
	/*int i;
	for(i=l;i<=h;i++)
		printf("%d ",a[i]);
	printf('\n');
	struct pair ans;
	if(sizeof(a)==1)	
	{	ans.m1=a[l]; ans.m2=0;	}
	if(sizeof(a)==2)	
	{	ans.m1=max(a[l],a[h]); ans.m2=min(a[l],a[h]);	}*/
	struct pair ans;
	ans.m1=max(a[l],a[h]); ans.m2=min(a[l],a[h]);
	//printf("%d %d\n",ans.m1,ans.m2);
	return ans;
}
struct pair maxppair(struct pair p1,struct pair p2)
{
	struct pair ans;
	ans.m1=max(p1.m1,p2.m1);
	ans.m2=0;
	if(ans.m1==p1.m1)
	{
		if(p1.m2>p2.m1)
			ans.m2=p1.m2;
		else
			ans.m2=p2.m1;
	}
	else
	{
		if(p2.m2>p1.m1)
			ans.m2=p2.m2;
		else
			ans.m2=p1.m1;
	}
	//printf("%d %d\n",ans.m1,ans.m2);
	return ans;
}
struct pair find2max(int a[],int l,int h)
{
	int mid;
	struct pair t1,t2;
	if(h-l<2)
	{
		return maxpair(a,l,h);
	}
	mid=(l+h)/2;
	return maxppair(find2max(a,l,mid),find2max(a,mid+1,h));
}
int main()
{
	int n,a[50],i;
	struct pair ans;
	printf("Enter size:");
	scanf("%d",&n);
	printf("Enter elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	ans=find2max(a,0,n-1);
	printf("%d\n",ans.m2);
	return 0;
}
