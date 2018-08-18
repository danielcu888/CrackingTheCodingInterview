public class IsPerm {
	private static String Sort(String s) {
		char c[] = s.toCharArray();
		java.util.Arrays.sort(c);
		return new String(c);
	}
	
	public static boolean isPermutation1(String s1, String s2) {
		if (s1 == null || s2 == null)
			return false;
		if (s1.equals(s2))
			return true;
		if (s1.length() != s2.length())
			return false;
		return Sort(s1).equals(Sort(s2));
	}

	public static boolean isPermutation2(String s1, String s2) {
		if (s1 == null || s2 == null)
			return false;
		if (s1.equals(s2))
			return true;
		if (s1.length() != s2.length())
			return false;

		char letters[] = new char[256];
		char c1[] = s1.toCharArray();
		for (char c : c1)
			++letters[(int)c];
		final int l = s2.length();
		for (int i = 0 ; i != l; ++i)
			if (--letters[(int)s2.charAt(i)] < 0)
				return false;
		return true;
	}
	
	public static void main(String args[]) {
	}
}
