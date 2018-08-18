package exercise_9_4;

import java.util.ArrayList;

public class Exercise_9_4 
{
	public static ArrayList<String> foo(String s)
	{
		ArrayList<String> ret = null;
		if(s.isEmpty()) return ret;
		ret = new ArrayList<String>();
		ret.add(s.substring(0,1));

		ArrayList<String> tmp = foo(s.substring(1));
		if(tmp != null)
			for(String str : tmp)
			{
				ret.add(str);
				ret.add(s.substring(0,1) + str);
			}
		return ret;
	}
	
	public static void main(String[] args)
	{
		String s = "wxyz";
		ArrayList<String> a = foo(s);
		for(String str : a)
			System.out.println(str);
	}
}
