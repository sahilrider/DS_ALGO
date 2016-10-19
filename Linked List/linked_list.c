#include<stdio.h>
#include<malloc.h>

typedef struct node //typedef so that you dont have to write struct node everywhere
{
	int num;
	struct node *next;
}node;

struct node *head=NULL;
void display();
void ins_beg();
void createll();
void ins_end();
void del_start();
void del_last();
void del_any();
void disp_rev();

int main()
{
	int n=1;
	while(n!=0)
	{
		printf("1.Insert at End\n");
		printf("2.Display\n");
		printf("3.Create List\n");
		printf("4. Insert at beginning\n");
		printf("5.Delete first\n");
		printf("6.Delete last\n");
		printf("7.Delete any\n");
		printf("8.Display Reverse\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: ins_end(); break;
			case 2: display(); break;
			case 3: createll(); break;
			case 4: ins_beg(); break;
			case 5: del_start(); break;
			case 6: del_last(); break;
			case 7:del_any(); break;
			case 8: disp_rev(); break;
		}
		
	}
	
	return 0;
}

void ins_beg()
{
	node *new;
	int item;
	printf("Insert the value\n");
	scanf("%d",&item);
	new=(node*)malloc(sizeof(node));	
	new->num=item;
	new->next=head;
	head=new;
}

void ins_end()
{
	node *temp,*new;
	temp=head;
	while(temp->next !=NULL)
		temp=temp->next;
	new=(node*)malloc(sizeof(node));
	printf("Enter the data:");
	scanf("%d",&new->num);
	new->next=NULL;
	temp->next=new;
}

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
	printf("\n");
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

void del_start()
{
	node *temp;
	temp=head;
	head=head->next;
	free(temp);
}

void del_last()
{
	node *t1,*t2;
	t2=head;
	while(t2->next!=NULL)
	{
		t1=t2;
		t2=t2->next;
	}
	t1->next=NULL;
	free(t2);
}

void del_any()
{
	int item;
	printf("Enter item to be deleted:\n");
	scanf("%d",&item);
	node *t1,*t2;
	t2=head;
	while(t2->num!=item)
	{
		t1=t2;
		t2=t2->next;
	}
	t1->next=t2->next;
	free(t2);
}

void disp_rev()
{
	node *temp,*tail;
	
	tail=NULL;
	while(tail!=head)
	{
		temp=head;
		while(temp->next!=tail)
			temp=temp->next;
		printf("%d\t",temp->num);
		tail=temp;
	}
	printf("\n");
}
