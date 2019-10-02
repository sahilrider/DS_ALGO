#include<stdio.h>
#include<malloc.h>

typedef struct node 
{
	int data;
	struct node *lptr,*rptr;
}node;

node *root=NULL;

node *insert(node *r,int num)		//Insert data as per their value in the tree
{
	node *newn,*temp,*parent;
	temp=r;
	newn=(node*)malloc(sizeof(node));
	newn->data=num;
	newn->lptr=newn->rptr=NULL;
	if(temp==NULL)
	{
		r=newn;
	}
	else
	{
		parent=NULL;
		while(temp!=NULL)
		{
			parent=temp;
			if(num < temp->data)
				temp=temp->lptr;
			else
				temp=temp->rptr;
		}
		if(num < parent->data)
			parent->lptr=newn;
		else
			parent->rptr=newn;
	}
	return r;
}

void inorder(node *r)		//Inorder transversal
{
	if(r!=NULL)
	{
		inorder(r->lptr);
		printf("%d ",r->data);
		inorder(r->rptr);
	}
}

void preorder(node *r)		//Preorder transversal
{
	if(r!=NULL)
	{
		printf("%d ",r->data);
		preorder(r->lptr);
		preorder(r->rptr);
	}
}

void postorder(node *r)		//Postorder transversal
{
	if(r!=NULL)
	{
		postorder(r->lptr);
		postorder(r->rptr);
		printf("%d ",r->data);
	}
}

node *smallest(node *r)
{
	if(r==NULL || r->lptr==NULL)
		return r;
	else
		return smallest(r->lptr);
}

node *largest(node *r)
{
	if(r==NULL || r->rptr==NULL)
		return r;
	else
		return largest(r->rptr);
}

node *delet(node *r,int elem)
{
		if(r==NULL)		//if tree is empty
			return r;
		else if(elem < r->data)		//left side value
		{
			r->lptr= delet(r->lptr,elem);		//right side value
		}
		else if(elem > r->data)					//value found
			r->rptr= delet(r->rptr,elem);
		else
		{
			if(r->lptr==NULL && r->rptr==NULL)		//no  child
			{
				free(r);
				r=NULL;
			//	return r;
			}
			else if(r->lptr==NULL)		//only right child
			{
				node *temp=r;
				r=r->rptr;
				free(temp);
			//	return r;
			}
			else if(r->rptr==NULL)		//only left child
			{
				node *temp=r;
				r=r->lptr;
				free(temp);
			//	return r;
			}
			else								//2 child
			{
				node *temp=smallest(r->rptr);		//smallest on right subtree
				r->data=temp->data;					//replace that with root
				r->rptr=delet(r->rptr,temp->data);	//delete that value from that subtree
			//	return r;
			}
			//return r;
		}
		return r;
}

int totalnodes(node *r)
{
	if(r!=NULL)
	{
		return totalnodes(r->lptr) + totalnodes(r->rptr) + 1;
	}
}

int internalnodes(node *r)
{
	if(r==NULL)
		return 0;
	else if(r->lptr==NULL && r->rptr==NULL)
		return 0;
	else
		return internalnodes(r->lptr) + internalnodes(r->rptr) + 1;
}

int externalnodes(node *r)
{
	if(r==NULL)
		return 0;
	else if(r->lptr==NULL && r->rptr==NULL)
		return 1;
	else
		return externalnodes(r->lptr) + externalnodes(r->rptr);
}

int getheight(node *r){
	if(r == NULL){
		return 0;
	}else{
		int leftHeight = getheight(r->lptr);
		int rightHeight = getheight(r->rptr);
		if(leftHeight > rightHeight){
			return(leftHeight+1); 
		}else{
			return(rightHeight+1);
		}
	}
}



void main()
{
	node *small,*large;
	int totalnode,internalnode,externalnode;
	
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,40);
	root=insert(root,50);
	root=insert(root,34);
	root=insert(root,45);
	root=insert(root,16);
	root=insert(root,36);
	root=insert(root,5);

	printf("Height of tree is %d", getheight(root));
	
	printf("\nPre Order Transversal: ");
	preorder(root);
	printf("\nIn Order Transversal: ");
	inorder(root);
	printf("\nPost Order Transversal: ");
	postorder(root);
	
	small=smallest(root);
	printf("\nSmallest Node:%d\n",small->data);
	
	large=largest(root);
	printf("Largest Node:%d\n",large->data);
	
	totalnode=totalnodes(root);
	printf("Total Node:%d\n",totalnode);
	
	internalnode=internalnodes(root);
	printf("Internal Nodes:%d\n",internalnode);
	
	externalnode=externalnodes(root);
	printf("External Nodes:%d\n",externalnode);
	
	root=delet(root,40);
	printf("\nPre Order Transversal: ");
	preorder(root);
	printf("\nIn Order Transversal: ");
	inorder(root);
	printf("\nPost Order Transversal: ");
	postorder(root);
	
}
