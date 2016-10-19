#include <stdio.h>

int main()
{
    int stack[100],top=-1,i,n;
    long int q,c;
    scanf("%d",&q);
    if(q>=1 && q<=100000)
    {
    	for(i=0;i<q;i++)
		{
			scanf("%d",&n);
			if(n==1)
			{
				if(top==-1)
					printf("No Food\n");
				else
				{
					printf("%d\n",stack[top]);
					top--;
				}
			}
			else if(n==2)
			{
				scanf("%d",&c);
				if(c>=1 && c<=10000000)
				{
					top++;
					stack[top]=c;
				}
			}
		}
	}
}
