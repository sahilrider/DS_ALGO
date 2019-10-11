#include <stdio.h>
#include <conio.h>
struct node
	{
		int data;
		struct node *ptr;
	};
typedef struct node NODE;
NODE *head=NULL;
void create()
	{
		char c;
		NODE *current;
		do
			{
				
				
				
				NODE *new_node;
				int d;
				new_node = (NODE *)malloc(sizeof(NODE));
				printf("Enter the data \n");
				scanf("%d", &d);
				new_node->data=d;
				if(head==NULL)
					{
						head=new_node;
						new_node->ptr=head;
						current=new_node;
					}
				else
					{
						current->ptr=new_node;
						new_node->ptr = head;
						current=new_node;
					}
				printf("Do you want to add more data \n");
				scanf("%c", &c);				
				scanf("%c", &c);
				}
		while(c!='n');
		
	}
void display()
	{
		NODE *new_ptr;
		new_ptr=head;
		if(head==NULL)
			printf("NO DATA\n");
		else
			{
				printf("Linked List :- ");
				printf("%d -> ",new_ptr->data);
				new_ptr=new_ptr->ptr;
				while(new_ptr!=head)
					{
						printf("%d -> ",new_ptr->data);
						new_ptr=new_ptr->ptr;
					}
				printf("NULL \n");
			}
	}
void insert_begin()
	{
		NODE *new_node, *new_ptr;
		new_node = (NODE *)malloc(sizeof(NODE));
		printf("Enter the data you want to add in the begining \n");
		int d;
		scanf("%d",&d);
		new_node->data = d;
		if(head==NULL)
		{
			head = new_node;
			new_node->ptr = head;
		}
		else
			{
				new_node->ptr=head;
				new_ptr = head;
				while(new_ptr->ptr!=head)
					{
						new_ptr=new_ptr->ptr;
						printf("%d ",new_ptr->data);
					}
					head = new_node;
					new_ptr->ptr = head;
			}
	}
void insert_end()
	{
		int d;
		NODE *new_node, *new_ptr;
		new_ptr=head;
		new_ptr=new_ptr->ptr;
		printf("Enter the data you want to add at the end");
		scanf("%d",&d);
		new_node->data=d;
		while(new_ptr!=head)
			{
				new_ptr=new_ptr->ptr;
			}
		new_ptr->ptr=new_node;
		new_node->ptr=head;
	}
int main()
	{
		create();
		display();
		insert_begin();
		display();
		insert_end();
		display();
	}
