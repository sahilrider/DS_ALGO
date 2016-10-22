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

void josephus()
{
	node *t1,*t2;
	t2=f;
	int ctr;
	while(f!=l)
	{
		ctr=1; t2=f;
		while(ctr!=3)
		{
			t1=t2;
			t2=t2->ptr;
			ctr++;
		}
		t1->ptr=t2->ptr;
		f=t2->ptr;
		l=t1;
		free(t2);
		display();
	}
}

void main()
{
	int n;
	printf("Enter the no. of nodes:\n");
	scanf("%d",&n);
	createcl(n);
	display();
	josephus();
}


