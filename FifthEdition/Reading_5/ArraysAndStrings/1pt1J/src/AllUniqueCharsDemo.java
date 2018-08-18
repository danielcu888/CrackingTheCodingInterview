import java.util.HashMap;

public class AllUniqueCharsDemo {
	
	public static boolean all_unique_chars1(String s) {
		if (s.length() == 0)
			return true;
		if (s.length() > Math.pow(2.,15.))
			return false;
		HashMap<Character, Boolean> m = new HashMap<Character, Boolean>();
		final int l = s.length();
		for (int i = 0; i != l; ++i)
			if (m.get(s.charAt(i)) == null)
				m.put(s.charAt(i), true);
			else
				return false;
		return true;
	}
	
	public static boolean all_unique_chars2(String s) {
		if (s.length() == 0)
			return true;
		if (s.length() > 128)
			return false;
		boolean a[] = new boolean[128];
		for (int i = 0; i != 128; ++i)
			a[i] = false;
		final int l = s.length();  
		for (int i = 0; i != l; ++i)
			if (a[s.charAt(i)])
				return false;
			else
				a[s.charAt(i)] = true;
		return true;
	}

	public static boolean all_unique_chars3(String s) {
		if (s.length() == 0)
			return true;
		if (s.length() > 26)
			return false;
		long bv = 0L;
		final int l = s.length();
		for (int i = 0; i != l; ++i)
			if (((1 << s.charAt(i)) & bv) > 0)
				return false;
			else
				bv |= (1 << s.charAt(i));
		return true;
		}
	
	public static void main(String args[]) {
		final String s = "abcdefghi";
		if (all_unique_chars3(s))
			System.out.println("All unique chars");
		else
			System.out.println("Not all unique chars");
	}
}
