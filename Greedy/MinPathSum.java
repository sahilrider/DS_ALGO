import java.util.*;

public class MinPathSum{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		int[][] a = new int[n][m];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				a[i][j] = scan.nextInt();
			}
		}
		System.out.println(minPathSum(a));
	}
	public static int minPathSum(int[][] grid) {
        int m = grid.length,n = grid[0].length;
        for(int i = 1; i < grid.length; i++){
            grid[i][0] += grid[i-1][0]; 
        }
        for(int i = 1; i < grid[0].length; i++){
            grid[0][i] += grid[0][i-1]; 
        }
        for(int i = 1; i < grid.length; i++){
            for(int j = 1; j < grid[0].length; j++){
                grid[i][j] += Math.min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
}