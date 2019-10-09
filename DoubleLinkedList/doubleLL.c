#include<stdio.h>
#include<stdlib.h>
struct node
{
  int n;
  struct node *right;
  struct node *left;
};

typedef struct node node;
int count = 0;
node* create_node()
{
  node *ptr = (node*) malloc(sizeof(node));
  int n=0;
  printf("Enter the value:");
  scanf("%d", &n);
  ptr->n =n;
  ptr->right = NULL;
  ptr->left = NULL;
  return ptr;
}

node* create_list(int n , node *head)
{
  int i=0;
  node *ptr = head;
  for(i = 0; i < n ; i++){
    node* nptr = create_node();
    ptr->right = nptr;
    nptr->left = ptr;
    ptr = ptr->right;
    count++;
  }
  return ptr;
}

node* insertEnd(node *tail)
{
  //printf("%d\n", tail->n);
  node *ptr  = tail;
  node *nptr = create_node();
  ptr->right =nptr;
  nptr->left = ptr;
  tail = nptr;
  printf("The value inserted to End:%d\n",nptr->n );
  count++;
  return tail;
}
void insertPos(int pos,node *head)
{
  node *prev;
  node *ptr = head;
  int i= 0;
  for(i=0; i<pos; i++)
  {
    prev = ptr;
    ptr = ptr->right;
    }
  node *nptr = create_node();
  printf("The inserted value in position %d :%d\n",(i+1),nptr->n );
  nptr->right= ptr;
  nptr->left= prev;
  prev->right=nptr;
  ptr->left=nptr;
  count++;
}

void insertAfter(int num,node *head)
{
  node *prev;
  node *ptr = head;
  int i= 0,flag=0;
  while(ptr->right != NULL)
  {
    if(ptr->n == num)
    {
      flag = 1;
      break;
    }
    ptr=ptr->right;
  }
  ptr = ptr->right;
  if(flag == 1)
  {
    prev = ptr->left;
    node *nptr = create_node();
    printf("The inserted value after %d :%d\n",num,nptr->n );
    nptr->right= ptr;
    nptr->left= prev;
    prev->right=nptr;
    ptr->left=nptr;
    count++;
  }
  else printf("The Number %d is not present!!!\n", num);
}
void insertBefore(int num,node *head)
{
  node *prev;
  node *ptr = head;
  int i= 0,flag=0;
  while(ptr->right != NULL)
  {
    if(ptr->n == num)
    {
      flag = 1;
      break;
    }
    ptr=ptr->right;
  }

  if(flag == 1)
  {
    prev = ptr->left;
    node *nptr = create_node();
    printf("The inserted value before %d :%d\n",num,nptr->n );
    nptr->right= ptr;
    nptr->left= prev;
    prev->right=nptr;
    ptr->left=nptr;
    count++;
  }
  else printf("The Number %d is not present!!!\n", num);
}

node* insertHead(node *head)
{
  node *nptr = create_node();
  printf("The value inserted to HEAD:%d\n",nptr->n );
  nptr->right = head;
  head->left=nptr;
  head = nptr;
  count++;
  return head;
}

node* delEnd(node *tail)
{
  node *ptr= tail;
  node *prev=tail->left;
  printf("The deleted value from End:%d\n",ptr->n );
  prev->right = NULL;
  free(ptr);
  tail = prev;
  count--;
  return tail;
}
node* delHead(node *head)
{
  node *ptr = head;
  head = head->right;
  head->left = NULL;
  printf("The deleted value from Head:%d\n",ptr->n );
  free(ptr);
  count--;
  return head;
}

void delPos(int pos,node *head)
{
  int i=0;
  node *prev;
  node *ptr = head;
  node *next = NULL;
  for(i=0; i<pos; i++)
  {
    prev = ptr;
    ptr = ptr->right;
  }
  next = ptr->right;
  printf("The deleted value from position %d :%d\n",(i+1),ptr->n );
  prev->right = ptr->right;
  next->left= ptr->left;
  free(ptr);
  count--;
}


void display(node *head)
{
  node *ptr = head;
  while (ptr!= NULL) {
    printf("%d-->", ptr->n);
    ptr = ptr->right;
  }
  printf("\n");
}

int main()
{
  int n = 0,choice = -1, pos =-1,num=0;
  while (1) {
    printf("Enter 1: To create list\nEnter 2: To display list\nEnter 3: To insert node at HEAD\nEnter 4: To insert node at any position\nEnter 5: To insert node at End\nEnter 6: To delete node at HEAD\nEnter 7: To delete node from any Position\nEnter 8: To delete node from END\nEnter 9:To insert after certain Value\nEnter 10: To insert before certain Value\nEnter 0: To Exit\nEnter your choice:");
    scanf("%d",&choice );
    switch (choice)
    {
      case 1:
      printf("HEAD\n");
      node *head = create_node();
      node *tail=head;
      while(tail->right != NULL)
        tail= tail->right;
      count++;
       if(count != 0)
       {
         printf("Enter the number of nodes you want including head:");
         scanf("%d",&n );
         tail = create_list(n-1,head);
       }
       else
        printf("ERROR!!! List not present or head is NULL");
       break;


       case 2:
       if(count != 0 && head != NULL)
         display(head);
       else
        printf("ERROR List not present.\n" );
       break;


       case 3:
       if(count != 0 && head != NULL)
          head = insertHead(head);
        else
          printf("ERROR!!! List not present or head is NULL\n");
        break;


       case 4:
       if(count != 0 && head != NULL)
       {
        printf("Enter the position:(Starts from 1):-");
        scanf("%d",&pos);
        pos--;
        if(pos == 0)
          head = insertHead(head);
        else if(pos>0 && pos<count)
          insertPos(pos,head);
        else if(pos == count)
          tail = insertEnd(tail);
        else
          printf("Position out of range or negetive position given!!!\n");
        }
        else
          printf("ERROR!!! List not present or head is NULL\n");
        break;


        case 5:
        if(count != 0 && tail != NULL)
           tail = insertEnd(tail);
         else
           printf("ERROR!!! List not present or tail is NULL\n");
         break;


        case 6:
        if(count != 0 && head != NULL)
           head = delHead(head);
         else
           printf("ERROR!!! List not present or head is NULL\n");
         break;


        case 7:
        if(count != 0 && head != NULL)
        {
         printf("Enter the position:(Starts from 1):-");
         scanf("%d",&pos);
         pos--;
         if(pos == 0)
           head = delHead(head);
         else if(pos>0 && pos<count)
           delPos(pos,head);
         else if(pos == count)
           tail = delEnd(tail);
         else
           printf("Position out of range or negetive position given!!!\n");
         }
         else
           printf("ERROR!!! List not present or head is NULL\n");
         break;

         case 8:
         if(count != 0 && tail != NULL)
            tail = delEnd(tail);
          else
            printf("ERROR!!! List not present or tail is NULL\n");
          break;
        case 9:
        if(count != 0 && head != NULL)
          {
            printf("Enter the number after which you want to inserted:");
            scanf("%d", &num);
            if(num != tail->n)
             insertAfter(num,head);
            else
              tail = insertEnd(tail);
          }
         else
           printf("ERROR!!! List not present or HEAD is NULL\n");
         break;
         case 10:
         if(count != 0 && head != NULL)
          {
            printf("Enter the number before which you want to insert:");
            scanf("%d", &num);
            if(num != head->n)
              insertBefore(num,head);
            else
              head=insertHead(head);
          }
          else
            printf("ERROR!!! List not present or HEAD is NULL\n");
          break;
         case 0: printf("TERMINATED!!! \n" );
         break;
         default:
          printf("WRONG CHOICE!!!\n" );
        }
        if(choice == 0)
          break;
       }
       return 0;
    }
