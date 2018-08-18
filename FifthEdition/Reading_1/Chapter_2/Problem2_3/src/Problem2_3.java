class LinkedListNode
{
	public LinkedListNode(int data)
	{
		this.data = data;
		this.next = null;
	}
	
	int data;
	LinkedListNode next;
}

public class Problem2_3
{
	public static void deleteNode(LinkedListNode c)
	{
		if(c == null) return;
		if(c.next == null)
			{
				c = null;
				return;
			}
		c.data = c.next.data;
		c.next = c.next.next;
	}
	
	public static void main(String[] args)
	{
	
	}

}
