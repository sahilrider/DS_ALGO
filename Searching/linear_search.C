#include <stdio.h>
#include <stdlib.h>

int main()
    {
      int array[1000], sk, c, x;

      printf("Enter number of elements you need insert to the array\n");
      scanf("%d", &x);

      printf("Enter %d integer(s)\n", x);

      for (c = 0; c < x; c++)
        scanf("%d", &array[c]);

      printf("Enter a number to search\n");
      scanf("%d", &sk);

      for (c = 0; c < x; c++)
      {
        if (array[c] == sk)    /* If required element is found */
        {
          printf("%d is present at location %d.\n", sk, c+1);
          break;
        }
      }
      if (c == x)
        printf("%d isn't found in the array.\n", sk);

      return 0;
    }
