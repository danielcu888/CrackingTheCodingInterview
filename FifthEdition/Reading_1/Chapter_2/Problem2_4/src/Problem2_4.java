class LinkedListNode
{
	public int data;
	public LinkedListNode next;

	public LinkedListNode(int data)
	{
		this.data = data;
		this.next = null;
	}
		
	public static LinkedListNode appendToTail(LinkedListNode head, LinkedListNode n)
	{
		if(head == null)
			head = n;
		else
		{
			LinkedListNode tmp = head;
			while(tmp.next != null)
				tmp = tmp.next;
			tmp.next = n;
		}
		return head;
	}
	
	public static LinkedListNode partition(LinkedListNode head, int x)
	{
		if(head == null) return null;
		
		LinkedListNode less = null, grOrEq = null;
		while(head != null)
		{
			if(head.data < x)
				less = LinkedListNode.appendToTail(less, head);
			else
				grOrEq = LinkedListNode.appendToTail(grOrEq, head);
			LinkedListNode tmp = head;
			head = head.next;
			tmp.next = null;
		}
		
		less = LinkedListNode.appendToTail(less, grOrEq);
		return less;
	}

	public static void displayList(LinkedListNode head)
	{
		if(head == null) return;
		while(head != null)
		{
			System.out.println("data = " + head.data);
			head = head.next;
		}
	}
}

public class Problem2_4
{
	public static void main(String[] args)
	{
		LinkedListNode head = new LinkedListNode(10);
		for(int i = 9; i != 0; --i)
			head = LinkedListNode.appendToTail(head, new LinkedListNode(i));
		LinkedListNode.displayList(head);
		head = LinkedListNode.partition(head, 3);
		System.out.println();
		LinkedListNode.displayList(head);
	}

}
