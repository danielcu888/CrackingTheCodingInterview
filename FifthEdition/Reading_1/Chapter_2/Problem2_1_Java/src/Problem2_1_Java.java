import java.util.HashMap;

class LinkedListNode
{
	public LinkedListNode(int data)
	{
		this.data = data;
		next = null;
	}
	
	int data;
	LinkedListNode next;
}


public class Problem2_1_Java
{
	public static void deleteDups(LinkedListNode n)
	{
		HashMap<Integer, Boolean> map = new HashMap<Integer, Boolean>();
		LinkedListNode previous = null;
		while(n != null)
		{
			if(map.containsKey(Integer.valueOf(n.data)))
			{
				previous.next = n.next;
			}
			else
			{
				map.put(Integer.valueOf(n.data), true);
				previous = n;
			}	
			n = n.next;
		}
	}
	
	public static void deleteDups2(LinkedListNode n)
	{
		while(n != null)
		{
			LinkedListNode runner = n;
			while(runner != null)
			{
				if(runner.next.data == n.data)
					runner.next = runner.next.next;
				else
					runner = runner.next;
			}
			n = n.next;
		}
	}
	
	public static void main(String[] args)
	{
		
	}

}
