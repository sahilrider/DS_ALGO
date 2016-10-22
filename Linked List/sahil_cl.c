#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int num;
	struct node *ptr;
}node;

node *f,*l;
void createcl(int n)
{
	int i;
	node *new;
	for(i=0;i<n;i++)
	{
		new=(node*)malloc(sizeof(node));
		printf("Enter the data:\n");
		scanf("%d",&new->num);
		if(i==0)
		{
			f=new;
			new->ptr=f;
			l=new;
		}
		else
		{
			l->ptr=new;
			new->ptr=f;
			l=new;
		}
	}
}

void display()
{
	node *temp;
	temp=f;
	while(temp->ptr!=f)
	{
		printf("%d\t",temp->num);
		temp=temp->ptr;
	}
	printf("%d\n",temp->num);
}
void del_first()
{
	node *temp;
	temp=f;
	l->ptr=f->ptr;
	f=f->ptr;
	free(temp);
}
void del_last()
{
	node *temp;
	temp=f;
	while(temp->ptr!=l)
		temp=temp->ptr;
	temp->ptr=f;
	free(l);
	l=temp;
}
void main()
{
	int n;
	printf("Enter the no. of nodes:\n");
	scanf("%d",&n);
	createcl(n);
	display();
	del_first();
	display();
	del_last();
	display();
}
	
	
