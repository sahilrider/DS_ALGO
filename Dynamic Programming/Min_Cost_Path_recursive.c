#include<stdio.h> 
#include<limits.h>
int cost[1000][1000],a,b,p,q;
int min(int x, int y, int z); 
int minCost(int cost[a][b], int m, int n) 
{ 
if (n < 0 || m < 0) 
	return INT_MAX; 
else if (m == 0 && n == 0) 
	return cost[m][n]; 
else
	return cost[m][n] + min( minCost(cost, m-1, n-1),minCost(cost, m-1, n),minCost(cost, m, n-1) ); 
} 
int min(int x, int y, int z) 
{ 
if (x < y) 
	return (x < z)? x : z; 
else
	return (y < z)? y : z; 
} 
int main() 
{ 
printf("enter the size of matrix");
scanf("%d%d",&a,&b);
printf("enter the cost");
for(int i=0;i<a;i++)
	for(int j=0;j<b;j++)
		scanf("%d",&cost[i][j]);
printf("enter the position");
scanf("%d%d",&p,&q);
printf(" %d ", minCost(cost, p, q)); 
return 0; 
} 

