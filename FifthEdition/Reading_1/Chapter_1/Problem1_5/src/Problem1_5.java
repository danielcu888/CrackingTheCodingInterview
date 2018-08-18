public class Problem1_5 
{
	public static String compress(String s)
	{
		char[] c = s.toCharArray();
		int idx = 0, repChar = 0;
		while(idx < c.length - 1)  //O(n)
			{
				if(c[idx] == c[idx+1]) ++repChar;
				++idx;
			}
		int newLength = (s.length()-repChar)*2;
		if(newLength >= s.length()) return s;

		char[] c2 = new char[newLength+1];
		int readPosBeg = 0, writePos = 0, readPosEnd = 0, len = c.length;
		while(readPosEnd < len) //O(n)
		{
			int count = 0;
			while(readPosEnd < len && c[readPosEnd] == c[readPosBeg])
				{
					++readPosEnd;
					++count;
				}
			c2[writePos++] = c[readPosBeg];
			c2[writePos++] = (char)(count + (int)'0');
			readPosBeg = readPosEnd;
		}
		c2[writePos] = '\0';
		
		return new String(c2);
	}
	
	public static void main(String[] args) 
	{
		String s = "abbbcc";
		s = compress(s);
		System.out.println(s);
	}
}
