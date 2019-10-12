#include<stdio.h>
#include<conio.h>
#define SIZE 50

int queue[SIZE], front = -1, rear = -1;

void insert(int value)
{
	if(rear == SIZE-1)
		printf("\nQueue is Full!!! Insertion is not possible!!!");
	else
	{
  		if(front == -1)
   			front = 0;
 			rear++;
 			queue[rear] = value;
	}
}

void insertk(int pos,int val)
{
	if(rear==SIZE-1)
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
	for(i=1;i<6;i++)
		insert(i);
	display();
	
	printf("Enter the position and value:");
	scanf("%d%d",&pos,&val);
	
	insertk(pos,val);
	display();	
	
	return 0;
}




