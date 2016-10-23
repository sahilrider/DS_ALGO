#include<stdio.h>
#include<malloc.h>
typedef struct node //typedef so that you dont have to write struct node everywhere
{
	int co,exp;
	struct node *next;
}node;

node *h1=NULL,*h2=NULL,*h3=NULL;



/*Function to bubble sort*/
node *desc(node *head)
{
	int temp;
	node *t1,*t2;
	t1=head;
	while(t1->next!=NULL)
	{
		t2=head;
		while(t2->next!=NULL)
		{
			if(t2->exp < t2->next->exp)
			{
				temp=t2->exp; 
				t2->exp=t2->next->exp;
				t2->next->exp=temp;
			}
			t2=t2->next;
		}
		t1=t1->next;
	}
	return head;
}

void arrange()
{
	h3=desc(h3);
	node *temp,*t2;
	temp=h3;
	while(temp->next!=NULL)
	{
		if(temp->exp==temp->next->exp)
		{
			temp->co=temp->co + temp->next->co;
			t2=temp->next;
			temp->next=temp->next->next;
			free(t2);
		}
		temp=temp->next;
	}
}
node *ins(node *head)
{
	int ctr=1;
	node *temp,*new;
	while(ctr)
{	new=(node*)malloc(sizeof(node));
	printf("Enter the coeff & exp:");
	scanf("%d",&new->co);
	scanf("%d",&new->exp);
	printf("\n%d %d \n",new->co,new->exp);
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		temp=head;
		while(temp->next !=NULL)
			temp=temp->next;	
		temp->next=new;
	}
	printf("Do you want to continue:\n");
	scanf("%d",&ctr);
}
	return head;
}

node *display(node *head)
{
	if(head==NULL)
		printf("Empty\n");
	else
	{
		node *ptr = head;
	
		while(ptr!=NULL)
		{
			printf("%dx^%d + ",ptr->co,ptr->exp); 
			ptr=ptr->next;
		}
	}	
	printf("\n");
	return head;
}

 
void mul(node *hd1,node *hd2)
{
	node *t1,*t2,*temp,*newn;
	t1=hd1; t2=hd2;
	if(t1==NULL || t2==NULL)
	{
		printf("0");
	}
	else
	{
		while(t1!=NULL)
		{
			t2=hd2;
			while(t2!=NULL)
			{
				newn=(node*)malloc(sizeof(node));
				newn->co=t1->co * t2->co;
				newn->exp=t1->exp + t2->exp;
				newn->next=NULL;
				if(h3==NULL)
				{
					h3=newn;
				}
				else
				{
					temp=h3;
					while(temp->next!=NULL)
						temp=temp->next;
					temp->next=newn;
				}
				t2=t2->next;
			}
			t1=t1->next;
		}
	}
	arrange();
}	
	

void main()
{
	int ctr;
	printf("Enter the first polynomial:\n");
	h1=ins(h1);
	h1=display(h1);
	printf("Enter the second polynomial:\n");
	h2=ins(h2);
	h2=display(h2);
	mul(h1,h2);
	printf("Multiplied Polynomial\n");
	h3=display(h3);
}


