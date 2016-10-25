#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int num;
	struct node *left,*right;
}node;
node *start=NULL;

void create()
{
	node *newn;
	newn=(node*)malloc(sizeof(node));	
	scanf("%d",&newn->num);
	newn->left=NULL;
	newn->right=NULL;
	start=newn;
}
void ins_end()
{
	node *newn,*temp;
	newn=(node*)malloc(sizeof(node));	
	scanf("%d",&newn->num);
	newn->left=NULL;
	newn->right=NULL;
	temp=start;
	while(temp->right!=NULL)
		temp=temp->right;
	newn->left=temp;
	temp->right=newn;
}
void ins_beg()
{
	node *newn;
	newn=(node*)malloc(sizeof(node));	
	scanf("%d",&newn->num);
	newn->left=NULL;
	newn->right=start;
	start=newn;
}
void display()
{
	node *temp;	
	temp=start;
	while(temp!=NULL)
	{
		printf("%d ",temp->num);
		temp=temp->right;
	}
	printf("\n");
}	
void del_beg()
{
	node *temp;	
	temp=start;
	start=start->right;
	free(temp);
}
void del_end()
{
	node *temp,*t;
	while(temp->right!=NULL)
		temp=temp->right;
	//(temp->left)->right=NULL;
	t=temp->left;
	t->right=NULL;
	free(temp);
}
void main()
{
	create();	
	ins_end();
	ins_end();
	ins_beg();	
	ins_beg();
	display();
	del_beg();
	display();	
	del_end();
	display();
}
