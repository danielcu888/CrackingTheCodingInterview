
public class Problem1_8
{
	public static boolean isRotation(String s1, String s2)
	{
		if(s1.length() != s2.length()) return false;
		
		char first = s2.charAt(0);
		int idx = 0;
		
		while(true)
		{
			while(idx < s1.length() && s1.charAt(idx) != first)
				++idx;
			System.out.println(idx);
			
			if(idx == s1.length()) return false;

			int readPos1 = idx, readPos2 = 0;
			while(readPos1 != s1.length() && s1.charAt(readPos1++) == s2.charAt(readPos2++))
				System.out.println(readPos1 + " " + readPos2);
			if(readPos1 == s1.length())
				break;
			else
				++idx;
		}
				
		return s2.endsWith(s1.substring(0, idx));
	}
	
	public static boolean isRotation2(String s1, String s2)
	{
		if(s1.length() != s2.length() || s1.length() == 0) return false;
		
		String s1s1 = s1 + s1;
		return isSubstring(s1s1,s2);
	}
	
	public static void main(String[] args)
	{
		
	}
}
