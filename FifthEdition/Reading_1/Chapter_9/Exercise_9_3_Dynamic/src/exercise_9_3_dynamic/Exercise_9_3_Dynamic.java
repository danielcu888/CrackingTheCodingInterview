package exercise_9_3_dynamic;

public class Exercise_9_3_Dynamic 
{
	public static int foo(int a[], int start)
	{
		int i = start;
		while(i < a.length)
		{
			if(a[i] == i) 
				return i;
			else if(a[i] > i)
				{
					int ret = foo(a, a[i]);
					return ret != a.length ? ret : -1;
				}
			else
				++i;
		}
		return -1;
	}
	
	public static void main(String[] args)
	{
		int a[] = {-10,-5,2,2,2,2,4,7,9,12,13};
		System.out.println(foo(a, 0));
	}
}
