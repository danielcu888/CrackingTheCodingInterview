public class Problem1_4
{
	public static void substitute(char[] str, int len)
	{
		if(len == 0) return; //return if string is empty

		final int LENGTH = 3;
		
		//trim leading spaces in the string
		//determine number of spaces at beginning of string
		int idx = 0;
		while(idx < len && str[idx] == ' ') ++idx;
				
		//if all characters are spaces, return null string
		if(idx == len)
		{
			str[0] = '\0';
			return;
		}
		
		//idx now points to first non-space character
		int writePos = 0, readPos = idx;
		while(readPos < len)
			str[writePos++] = str[readPos++];

		//set new length of string
		len = writePos;
			
		//count number of spaces in string
		int numSpaces = 0; idx = 0;
		while(idx < len)
			if(str[idx++] == ' ') ++numSpaces;
						
		//idx = len
		//count number of spaces at end of string
		do {
			if(str[--idx] == ' ') --numSpaces;
		} while(str[idx] == ' ');
		++idx;
		//idx now points to one past the last non-space character in string
		
		int newLength = idx + numSpaces*(LENGTH-1);
				
		readPos = idx - 1; //points to last non-space character in string
		writePos = newLength - 1;
		
		while(readPos >= 0)
		{
			if(str[readPos] == ' ')
			{
				str[writePos--] = '0';
				str[writePos--] = '2';
				str[writePos--] = '%';
			}
			else
				str[writePos--] = str[readPos];
			--readPos;
		}
	}
	
	public static void main(String[] args) 
	{
		String s = "Mr John Smith";
		char[] c = s.toCharArray();
		char[] c2 = new char[100];
		for(int i = 0; i != c.length; ++i) c2[i] = c[i];
		substitute(c2, s.length());
		System.out.println(new String(c2));
	}
}
