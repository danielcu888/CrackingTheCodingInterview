import java.util.HashMap;

public class Problem1_1 
{
	//O(s.length()) time complexity, O(1) space complexity, short, Unicode Strings
	public static boolean isAllUniqueUnicode(String s)
	{
		HashMap<Character, Integer> ch = new HashMap<Character, Integer>();
		for(int i = 0;i != s.length(); ++i)
		{
			if(ch.get(s.charAt(i)) != null) return false;
			ch.put(s.charAt(i), 1);
		}
		return true;
	}
	
	//O(s.length()) time complexity, O(1) space complexity, long, ASCII Strings
	public static boolean isAllUniqueASCII(String s)
	{
		final int SIZE = 128;
		if(s.length() > SIZE) return false;
		
		boolean[] ch = new boolean[SIZE];
		for(int i = 0; i != ch.length; ++i) ch[i] = false;
		
		for(int i = 0; i != s.length(); ++i)
		{
			int idx = (int)s.charAt(i);
			if(ch[idx]) return false;
			ch[idx] = true;
		}
		return true;
	}
	
	//O(s.length()) time complexity, O(1) space complexity, ASCII characters between 'a' and 'a'+31
	public static boolean isAllUniqueBits(String s)
	{
		if(s.length() > 32) return false;
		
		int checker = 0;
		
		for(int i = 0; i != s.length(); ++i)
		{
			int val = (int)(s.charAt(i) - 'a');
			if((checker & (1 << val)) > 0) return false;
			checker |= (1 << val);
		}
		return true;
	}
	
	public static void main(String[] args) 
	{
		
	}
}
