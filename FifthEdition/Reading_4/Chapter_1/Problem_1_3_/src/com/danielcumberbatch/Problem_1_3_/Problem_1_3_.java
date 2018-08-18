package com.danielcumberbatch.Problem_1_3_;

public class Problem_1_3_ {
	public static boolean isPerm(String s1, String s2)
	{
		if(s1.length() != s2.length()) 
			return false;
		
		int tmp[] = new int[256];
		for(int i = 0; i != tmp.length; ++i)
			tmp[i] = 0;
		for(int i = 0; i != s1.length(); ++i)
			++tmp[s1.charAt(i) -'a'];
		for(int i = 0; i != s2.length(); ++i)
			--tmp[s2.charAt(i) -'a'];
		for(int i = 0; i != tmp.length; ++i)
			if(tmp[i] != 0) return false;
		return true;
	}
	
	public static void main(String[] args)
	{
		
	}
}
