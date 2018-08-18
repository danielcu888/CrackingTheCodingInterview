
public class Problem1_7
{
	public static void truncate(int[][] matrix, int M, int N)
	{
		boolean[] rowsUsed = new boolean[M];
		boolean[] colsUsed = new boolean[N];
				
		//O(n^2)
		for(int i = 0; i !=M; ++i)
			for(int j = 0; j != N; ++j)
				if(matrix[i][j] == 0) 
					rowsUsed[i] = colsUsed[j] = true;
	
		//O(n^2)
		for(int i = 0; i != M; ++i)
			if(rowsUsed[i]) 
				for(int j = 0; j != N; ++j) matrix[i][j] = 0;
		
		for(int i = 0; i != N; ++i)
			if(colsUsed[i])
				for(int j = 0; j != M; ++j) matrix[j][i] = 0;
	}
	
	public static void display(int[][] matrix, int M, int N)
	{
		for(int i = 0; i != M; ++i)
		{
			for(int j = 0; j != N; ++j)
				System.out.print(matrix[i][j]);
			System.out.println();
		}
		System.out.println();
	}
	
	public static void main(String[] args)
	{
		final int M = 5, N = 4;
		int[][] matrix = {{9,1,2,3},{1,2,4,9},{2,2,4,0},{2,3,3,5},{1,1,1,1}};
		display(matrix, M, N);
		truncate(matrix, M, N);
		display(matrix, M, N);
	}
}
