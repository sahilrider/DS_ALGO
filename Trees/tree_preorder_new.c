#include <stdio.h>
#include <conio.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

typedef struct node tree;

tree *root = NULL;

tree* newnode(int data) {

  tree *new = NULL;
  new = (tree *)malloc(sizeof(tree));

  new->data = data;
  new->left = NULL;
  new->right = NULL;

  return(new);
}

void preorder(tree *root) {

  if(root == NULL) {return;}

  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}


int main() {
  root = newnode(1);
  root->left = newnode(2);
  root->right = newnode(3);
  root->left->left = newnode(4);
  root->left->right = newnode(5);
  printf("Preorder traversal of binary tree is : ");
  preorder(root);
  printf("\n");
  return 0;
}
