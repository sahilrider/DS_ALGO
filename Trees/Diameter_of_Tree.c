#include<stdio.h>
#include<stdlib.h>
typedef struct nodes{
	int val;
	int leftcount;
	int rightcount;
	struct nodes *left;
	struct nodes*right;
} node;

int height(node *head){
	if(head == NULL){
		return 0;
	}
	return 1 + max(height(head->left),height(head->right));
}

int diameter(node *head){
	if(head == NULL){
		return 0;
	}
	return = max(height(head->left) + height(head->right) + 1,diameter(head->right),diameter(head->left));
}


int main(void){
	diameter(root);
}