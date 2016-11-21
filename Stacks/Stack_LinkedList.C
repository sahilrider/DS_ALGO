#include<stdio.h>
#include<malloc.h>

typedef struct snode
{
	int num;
	struct snode *back;
}snode;

snode *push(snode *t,int data)
{
	snode *newnode=(snode*)malloc(sizeof(snode));
	newnode->num=data;
	newnode->back=NULL;
	if(t==NULL)
		t=newnode;
	else
	{
		newnode->back=t;
		t=newnode;
	}
	return t;
}

snode *pop(snode *t)
{
	snode *temp;
	printf("Popped=%d\n",t->num);
	temp=t;
	t=t->back;
	free(temp);
	return t;
}

snode *display(snode *t)
{
	snode *temp;
	temp=t;
	if(t==NULL)
		printf("Empty Stack\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d ",temp->num);
			temp=temp->back;
		}
		printf("\n");
	}
	return t;
}

void main()
{
	snode *top=NULL;
	top=push(top,1);
	top=push(top,2);
	top=push(top,3);
	top=push(top,4);
	top=push(top,5);
	top=push(top,6);
	top=display(top);
	top=pop(top);
	top=pop(top);
	top=display(top);
}
