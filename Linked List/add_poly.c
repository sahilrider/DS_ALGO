#include<stdio.h>
#include<malloc.h>
typedef struct node //typedef so that you dont have to write struct node everywhere
{
	int co,exp;
	struct node *next;
}node;

node *h1=NULL,*h2=NULL,*h3=NULL;

node *display(node*);
node *ins(node*);
node *add(node*,node*);
void main()
{
	int ctr;
	printf("Enter the first polynomial:\n");
	h1=ins(h1);
	h1=display(h1);
	printf("Enter the second polynomial:\n");
	h2=ins(h2);
	h2=display(h2);
	h3=add(h1,h2);
	h3=display(h3);
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

node *add(node *hd1,node *hd2)
{
	node *t1,*t2,*t3,*temp;
	t1=hd1; t2=hd2; 
	
 while(t1!=NULL || t2!=NULL)
 {
	t3=(node*)malloc(sizeof(node));
	if(t1->exp==t2->exp)
	{
		t3->co=t1->co+t2->co;
		t3->exp=t1->exp;
		t3->next=NULL;
		t1=t1->next;
		t2=t2->next;
	}
	else if(t1->exp>t2->exp)
	{
		t3->co=t1->co;
		t3->exp=t1->exp;
		t3->next=NULL;
		t1=t1->next;
	}
	else
	{
		t3->co=t2->co;
		t3->exp=t2->exp;
		t3->next=NULL;
		t2=t2->next;
	}

	if(h3==NULL)
	{
		h3=t3;
	}
	else
	{
		temp=h3;
		while(temp->next !=NULL)
			temp=temp->next;	
		temp->next=t3;
	}
 }
	return h3;
}	
	

