package ex9_3;

public class Exercise_9_3 
{
	public static int magicSearch(int a[], int start, int end)
	{
		if(start > end) 
			return -1;
		if(a[start] == start) 
			return start;
		return magicSearch(a, a[start], end);
	}
	
	public static void main(String[] args)
	{
		int a[] = {4,4,5,5,5,5,9};
		int result = magicSearch(a,0,a.length-1); 
		if(result == -1) 
			System.out.println("No magic number!");
		else 
			System.out.println(result);
	}
}
