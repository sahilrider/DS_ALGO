 #include<stdio.h>
 
void ins_sort(float a[],int n)
{
	int i,j;
	float key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	
}
 void bucketsort(float a[],int n)
 {
 	float bucket[n][n];
 	int i,j,k[n];
 	for(i=0;i<n;i++)
 		k[i]=0;
 	for(i=0;i<n;i++)		//filling buckets
 	{
 		j=(int)(a[i]*n);	//index in bucket
 		bucket[j][k[j]]=a[i];
 		k[j]++;
	}
	for(i=0;i<n;i++)		//sort each bucket
	{
		ins_sort(bucket[i],k[i]);
	}
	//collecting in main array
	int ctr=0;
	for(i=0;i<n;i++)
		for(j=0;j<k[i];j++)
			a[ctr++]=bucket[i][j];
 }
 void main()
 {
 	/*float a[]={0.897, 0.565, 0.665, 0.1234, 0.664, 0.3434};
 	int n=6,i;*/
 	int n,i;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	float a[n];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%f",&a[i]);
 	bucketsort(a,n);
 	for(i=0;i<n;i++)
 		printf("%.4f ",a[i]);
 }
