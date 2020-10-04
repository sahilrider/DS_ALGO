#include<stdio.h>
int queue[100], front = 0, rear = -1,n;
void insert(int value)
{
	if(rear == (n-1))
		printf("\nQueue is Full!!! Insertion is not possible!!!");
	else
	    queue[++rear] = value;
}

void insertk(int pos,int val)
{
                if(rear==(n-1))
		printf("Queue is FULL\n");
                else
{
		int i;
		for(i=rear;i>=pos-1;i--)
			queue[i+1]=queue[i];
		queue[pos-1]=val;
		rear++;	
}
}

void display()
{
 	if(rear == -1)
 		printf("\nQueue is Empty!!!");
	else
	{
  		int i;
  		printf("\nQueue elements are:\n");
  		for(i=front; i<=rear; i++)
   		printf("%d\t",queue[i]);
	}
	printf("\n");
}

int main()
{
	int i,pos,val;
        printf("enter the number of elements:\n");
        scanf("%d",&n);
        printf("enter the queue elements\n");
	for(i=0;i<n;i++)
        {
	scanf("%d",&queue[i]);
        insert(queue[i]);
        }
	display();
	printf("Enter the position and value:");
	scanf("%d%d",&pos,&val);
	insertk(pos,val);
	display();	
	return 0;
}




