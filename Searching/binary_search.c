#include<stdio.h>

void sort(int n,int *a)

{
    
	for(int i=0;i<n;i++)

	        for(int j=0;j<n-i-1;j++)
	
        	if( *(a+j)>*(a+j+1) )
            
			{
                
				int temp=*(a+j);
                
				*(a+j)=*(a+j+1);
                
				*(a+j+1)=temp;
            
			}

}

int  binarysearch(int start,int end,int a[],int num)

{
    
	if(start<=end)

    	{
        
		int mid=(start+end)/2;

	        if( a[mid]==num )

	            return mid;
        
		else if( a[mid]<num )
	
            return binarysearch(mid+1,end,a,num);

	        else
	
            return binarysearch(start,mid-1,a,num);
	}
	else

	        return -1;

}

int main()

{
    
	int n;

    	printf("Enter number of elements:");

    	scanf("%d",&n);

	printf("Enter elements:");

	int a[n];
    
	for(int i=0;i<n;i++)
       
		scanf("%d",&a[i]);
   	
	sort(n,&a);
    
	printf("Enter element to be searched:");
    
	int num;
    
	scanf("%d",&num);
    
	int res=binarysearch(0,n-1,&a,num);
    
	printf("Sorted elements are:");
    
	for(int i=0;i<n;i++)
        
		printf("%d\t",a[i]);
    
	if(res==-1)
        
		printf("\n%d element is not found",num);
    
	else
        
		printf("\n%d element is found at position %d",num,res+1);
    
	return 0;

}