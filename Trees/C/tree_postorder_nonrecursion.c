#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *lptr, *rptr;
} node;

struct Stack
{
    int size;
    int top;
    node **array;
};

node *newnode(int data)
{
    node *newn;
    newn = (node *)malloc(sizeof(node));
    newn->data = data;
    newn->lptr = NULL;
    newn->rptr = NULL;
    return newn;
}

struct Stack *createStack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (node **)malloc(stack->size * sizeof(node *));
    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->top - 1 == stack->size;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, node *node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

node *pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

node *peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

void postorder(node *root)
{
    if (root == NULL)
        return;

    struct Stack *stack = createStack(100);
    do
    {
        while (root)
        {
            if (root->rptr)
                push(stack, root->rptr);
            push(stack, root);

            // Set root as root's left child
            root = root->lptr;
        }

        root = pop(stack);
        if (root->rptr && peek(stack) == root->rptr)
        {
            pop(stack);
            push(stack, root);
            root = root->rptr;
        }
        else
        {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (!isEmpty(stack));
}

void main()
{
    node *root;
    root = newnode(1);
    root->lptr = newnode(2);
    root->rptr = newnode(3);
    root->lptr->lptr = newnode(4);
    root->lptr->rptr = newnode(5);

    printf("Post Order Transversal: ");
    postorder(root);
}
