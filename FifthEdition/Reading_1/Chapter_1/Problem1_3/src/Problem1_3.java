import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;

public class Problem1_3 
{
	private static String sort(String s)
	{
		char[] c = s.toCharArray();
		Arrays.sort(c);
		return new String(c);
	}
	
	//Order nlog(n) time complexity
	public static boolean isPermutation(String s1, String s2)
	{
		if(s1.length() != s2.length()) 
			return false;
		return sort(s1).equals(sort(s2));
	}
	
	//Order n time complexity, for short Unicode Strings
	public static boolean isPermutationUnicode(String s1, String s2)
	{
		if(s1.length() != s2.length()) return false;
		HashMap<Character, Integer> hm = new HashMap<Character, Integer>();

		for(int i = 0; i != s1.length(); ++i)
		{
			char c = s1.charAt(i);
			Integer val = hm.get(c);
			if(val != null)
				hm.put(c, val+1);
			else
				hm.put(c, 1);
		}
		
		for(int i = 0; i != s2.length(); ++i)
		{
			char c = s2.charAt(i);
			Integer val = hm.get(c);
			if(val == null) return false;
			hm.put(c, val-1);
		}
		
		Iterator<Character> iterator = hm.keySet().iterator();
		while(iterator.hasNext())
		{
			if(hm.get(iterator.next()) != 0)
				return false;
		}
		
		return true;
	}
	
	//Order n time complexity, for long ASCII Strings
	public static boolean isPermutationASCII(String s1, String s2)
	{
			if(s1.length() != s2.length()) return false;
			final int SIZE = 128;
			int[] occs = new int[SIZE];
			for(int i = 0; i != SIZE; ++i) occs[i] = 0;
			for(int i = 0; i != s1.length(); ++i)
			{
				int idx1 = s1.charAt(i),
					idx2 = s2.charAt(i) ;
				++occs[idx1]; --occs[idx2];	
			}
			
			for(int i = 0; i != s1.length(); ++i)
			{		
				int idx1 = s1.charAt(i);
				if(occs[idx1] != 0) return false;
			}
			return true;
	}
	
	public static void main(String[] args) 
	{
		System.out.println(isPermutation("permutation", "merputation"));
		System.out.println(isPermutationUnicode("permutation", "merputation"));
		System.out.println(isPermutationASCII("permupation", "merputation"));
	}

}
