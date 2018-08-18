package exercise_9_5;
import java.util.ArrayList;

public class Exercise_9_5 
{
	public static ArrayList<String> foo(String s)
	{
		ArrayList<String> ret = null;
		if(s == null) return ret;
		ret = new ArrayList<String>();
		if(s.length() == 1)
		{
			ret.add(s); 
			return ret;
		}
		for(int i = 0; i != s.length(); ++i)
		{
			String tmp = s.substring(0, i) + s.substring(i+1);
			String tmp2 = s.substring(i, i+1);
			ArrayList<String> a = foo(tmp);
			for(String tmp3 : a)
				ret.add(tmp2 + tmp3);
		}
		return ret;
	}
	
	public static void main(String[] args)
	{
		String s = "wxyz";
		ArrayList<String> l = foo(s);
		for(String tmp : l)
			System.out.println(tmp);
	}
}
