 #include<stdio.h>
 #include<malloc.h>
 
 void merge(int a[],int l,int m,int r)
 {
 	int i,j,k;
 	int n1=m-l+1;   //length of left subarray
 	int n2=r-m;		//l of right subarray
 	int la[n1],ra[n2]; 		//both subarrays
 	
 	//copying elements in subarray
 	for(i=0;i<n1;i++)
 		la[i]=a[l+i];
 	for(j=0;j<n2;j++)
 		ra[j]=a[m+1+j];
 		
 	//pointers to both subarray and main array
 	i=0;	j=0;	k=l;
 	while(i<n1 && j<n2)
 	{
 		if(la[i]<ra[j])
 		{
 			a[k++]=la[i];
 			i++;
		}
		else
		{
			a[k++]=ra[j];
			j++;
		} 
	}
	while(i<n1)
	{
		a[k++]=la[i++];
	} 
	while(j<n2)
	{
		a[k++]=ra[j++];
	}
 	
 	
 }
 
 void mergesort(int a[],int l,int r)
 {
 	
 	if(l<r)
 	{
 		
 		int m=(l+r)/2;
 		
 		mergesort(a,l,m);
 		mergesort(a,m+1,r);
 		
 		merge(a,l,m,r);
	}
 }
 
 int main()
 {
 	int size,i;
 	scanf("%d",&size);
 	int a[size];
 	printf("\nEnter the elements:\n");
 	for(i=0;i<size;i++)
 		scanf("%d",&a[i]);
 	mergesort(a,0,size-1);
 	printf("\nSorted Array:\n");
 	for(i=0;i<size;i++)
 		printf("%d ",a[i]);
 }
