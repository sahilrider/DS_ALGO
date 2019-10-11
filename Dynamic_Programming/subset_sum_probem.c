#include<stdio.h>

bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a 
    // subset of set[0..j-1] with sum equal to i
    bool subset[n+1][sum+1];
  
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[i][0] = true;
  
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[0][i] = false;
  
     // Fill the subset table in botton up manner
     for (int i = 1; i <= n; i++)
     {
       for (int j = 1; j <= sum; j++)
       {
         if(j<set[i-1])
         subset[i][j] = subset[i-1][j];
         if (j >= set[i-1])
           subset[i][j] = subset[i-1][j] || 
                                 subset[i - 1][j-set[i-1]];
       }
     }
  
        //  this code to print table
     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", subset[i][j]);
       printf("n");
     }
  
     return subset[n][sum];
}
int main()
{
  int n,set[100],val;
  int i,j;
  int res;
  printf("Enter the size of set:");
  scanf("%d",&n);
  printf("Enter the values:");
  for(i=0;i<n;i++)
    scanf("%d",&set[i]);
  printf("What is the final sum ?:");
  scanf("%d",&val);
  res=issubsetsum(set,n,val);
  printf("%d\n",res);
  return 0;
}
