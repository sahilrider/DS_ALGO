#include <stdio.h>
#include <malloc.h>

typedef struct tnode
{
	int num;
	struct tnode *left, *right;
} tnode;

tnode *root = NULL;

typedef struct snode
{
	tnode *tree;
	struct snode *next
} snode;

snode *top = NULL;

void push(tnode *r)
{
	snode *nn = (snode *)malloc(sizeof(snode));
	nn->tree = r;
	nn->next = NULL;
	if (top == NULL)
	{
		top = nn;
	}
	else
	{
		nn->next = top;
		top = nn;
	}
	//	printf("Pushed=%d\n",r->num);
}

tnode *pop()
{
	//	printf("Popped\n");
	tnode *res = top->tree;
	snode *temp = top;
	top = top->next;
	free(temp);
	return res;
}

int isempty()
{
	//printf("Checked\n");
	if (top == NULL)
		return 0;
	else
		return 1;
}

void preorder()
{
	tnode *current = root;
	push(current);
	//int ctr=0;
	while (isempty() != 0)
	{
		current = pop();
		printf("%d ", current->num);
		if (current->right)
			push(current->right);
		if (current->left)
			push(current->left);
	}
	printf("\n");
}

tnode *ntn(int data)
{
	tnode *nn = (tnode *)malloc(sizeof(tnode));
	nn->num = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

int main()
{
	root = ntn(1);
	root->left = ntn(2);
	root->right = ntn(3);
	root->left->left = ntn(4);
	root->left->right = ntn(5);
	preorder();
}
