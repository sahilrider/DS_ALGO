#define N 4
#include<stdio.h>

/*To diplay the result*/
void display(int board[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}

/*To check safe positions for queen*/
int issafe(int board[N][N],int row,int col)
{
	int i,j;
	//check for vertical cross
	for(i=0;i<col;i++)
		if(board[row][i])
			return 0;
	//check for primary diagonal cross
	for(i=row,j=col;i>=0 && j>=0;i--,j--)
		if(board[i][j])
			return 0;
	//check for secondary diagonal cross
	for(i=row,j=col;j>=0 && i<N;i++,j--)
		if(board[i][j])
			return 0;
	
	return 1;
}

int solvenq(int board[N][N], int col)
{
	int i;
	if (col >= N)
		return 1;

	for ( i = 0; i < N; i++)
	{
		if ( issafe(board, i, col) )
		{
			board[i][col] =1;
			if ( solvenq(board, col + 1) )
				return 1;

			board[i][col] = 0; // BACKTRACK
		}
	}

	return 0;
}

/*Function for backtracking*/
void solve()
{
	int board[N][N]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	
	if(solvenq(board,0)==0)
	{
		printf("Solution does not exist\n");
	}
	else
	{
		display(board);
	}
}

void main()
{
	solve();
}
