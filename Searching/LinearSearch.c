//program to search an element in an array using linear search
#include<stdio.h>
#include<conio.h>
int main()
{
 int a[50], element, size, i, index=-1;
 clrscr ();
 printf("Enter the size of the array (max. 50) : ");
 scanf("%d", &size);
 printf("Enter the elements of the array :\n");
 for(i=0; i<size; i++)
 {
  scanf("%d", &a[i]);
 }
 printf("Enter the element to be searched : ");
 scanf("%d", &element);
 for(i=0; i<size; i++)
 {
  if(a[i]==element)
  {
   index=i;
   break;
  }
 }
 if(index!=-1)
  printf("Element is found at index %d and position %d", index, index+1);
 else
  printf("Element not found! ");
 getch ();
 return 0;
}

