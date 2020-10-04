#include<stdio.h>
#include<string.h>
int stack[10],top=-1;

void push(int ch)
{

	stack[++top]=ch;
}
int pop()
{
	int temp=stack[top--];
	return temp;
}

int main()
{
	char exp[10];
	int i,l,op1,op2;
	scanf("%s",exp);
	l=strlen(exp);
	for(i=0;i<l;i++)
	{
		if(exp[i]>=48 && exp[i]<=57)
			push(exp[i]-48);
		else
		{
			op2=pop(); op1=pop();
			switch(exp[i])
			{
				case '+': push(op1 + op2);break;
				case '-':  push(op1 - op2);break;
				case '*': push(op1 * op2);break;
				case '/':  push(op1 / op2);break;
			}
		}
	}
	printf("%d\n",stack[top]);
	return 0;
}
