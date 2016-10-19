#include<stdio.h>
#include<malloc.h>

typedef struct node //typedef so that you dont have to write struct node everywhere
{
	int num;
	struct node *next;
}node;

struct node *head=NULL;
void display();
//void ins_beg(struct node *);
void createll();
//void ins_end(int item);
int main()
{
/*	int n=1;
	while(n!=0)
	{
		printf("1.Insert at beginning\n");
		printf("2.Display\n");
		printf("3.Create List\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: ins_beg(head); break;
			case 2: display(head); break;
			case 3: createll(); break;
		}
		
	}*/
	createll();
	display();
	return 0;
}

/*struct node ins_beg(struct node *head)
{
	struct node *nn;
	int item;
	printf("Insert the value\n");
	scanf("%d",&item);
	nn=(struct node *)malloc(sizeof(struct node));
	nn->num=item;
	nn->next=head;
	printf("%d",nn->num);
	head=nn;
	return;
}

struct node ins_end(int item)
{
	struct node *temp,*new;
	temp=head;
	while(temp->next !=NULL)
		temp=temp->next;
	new=(struct node *)malloc(sizeof(struct node));
	new->num=item;
	new->next=NULL;
	temp->next=new;
}
*/
void display()//dont need to pass head here since you defined head globally
{
	if(head==NULL)
		printf("Empty\n");
	else
	{
		node *ptr = head;
	
		while(ptr!=NULL)
		{
			printf("%d ",ptr->num); 
			ptr=ptr->next;//you wrote ptr->num here, which was a typo I guess. Should be ptr->next due to obvious reasons
		}
	}	
	return;
}

void createll()
{
	int i,n;
	node *tail; // keeps track of the last element
	tail=head; //atm head is the last element
	printf("Enter the size:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
			node *new;
			new=(node*)malloc(sizeof(node)); //create a new node in every iteration
			
			printf("Enter the data:\n");
			scanf("%d",&new->num); //i think you wanted to store this value in the node
			new->next = NULL;
			if(head==NULL)
			{
				head=new; //obvious change due to above changes
				tail=head; //still head is the last element
			}
			else
			{
				tail->next=new; //linking the previous last element to new last element
				tail=new; //making the new element as the last element
			}
	}
}
