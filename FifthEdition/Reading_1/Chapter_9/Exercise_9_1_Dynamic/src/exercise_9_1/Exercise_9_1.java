package exercise_9_1;

import java.util.HashMap;

public class Exercise_9_1 {
	public static int countWaysDP(int n, HashMap<Integer, Integer> map)
	{
		if(map.containsKey(n))
			return map.get(n);
		int q = 0;
		if(n < 0) return 0;
		else if(n == 0) q = 1;
		else
			q = countWaysDP(n-1, map) + countWaysDP(n-2, map) + countWaysDP(n-3, map);
		map.put(n, q);
		return q;
	}
	
	public static void main(String[] args)
	{
		System.out.println(countWaysDP(4, new HashMap<Integer, Integer>()));
	}
}
