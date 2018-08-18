
public class Problem1_6
{
	public static void display(int[][] matrix, int N)
	{
		for(int i = 0; i != N; ++i)
		{
			for(int j = 0; j != N; ++j)
				System.out.print(matrix[i][j]);
			System.out.println();
		}
		System.out.println();
	}
	
	public static void rotate(int[][] matrix, int N)
	{
		for(int layer = 0; layer < N/2; ++layer)
		{
			int first = layer, last = N - 1 - layer;
			for(int i = layer; i < last; ++i)
			{
				int store = matrix[first][i];
				matrix[first][i] = matrix[i][last];
				matrix[i][last] = matrix[last][last - i]; 
				matrix[last][last - i] = matrix[last - i][first];
				matrix[last - i][first] = store;
			}
		}
	}
	
	public static void main(String[] args)
	{
		final int N = 4;
		int[][] matrix = new int[N][N];
		for(int i = 0; i != N; ++i)
			for(int j = 0; j != N; ++j)
				matrix[i][j] = (i*2) + 1;
		display(matrix, N);
		rotate(matrix, N);
		display(matrix, N);
	}

}
