public class StacksAndQueues
{
	class Node
	{
		Object data;
		Node next;
		
		public Node(Object data)
		{
			this.data = data;
			this.next = null;
		}
	}
	
	
	class Stack
	{
		Node top;
		
		public Stack()
		{
			top = null;
		}
		
		public Node peek()
		{
			return top;
		}
		
		public boolean empty()
		{
			return top == null;
		}
		
		public int length()
		{
			int ret = 0;
			if(!empty())
			{
				Node tmp = top;
				while(tmp != null)
					{
						++ret;
						tmp = tmp.next;
					}
			}
			return ret;
		}
		
		public void push(Object item)
		{
			Node tmp = new Node(item);
			
			if(top == null) 
				top = tmp;
			else
			{
				tmp.next = top;
				top = tmp;
			}
		}
		
		public Node pop()
		{
			if(top == null)
				return null;
			else
			{
				Object item = top.data;
				top = top.next;
				return new Node(item);
			}
		}
		
	}
	
	class Queue
	{
		Node head, tail;

		public Queue()
		{
			head = tail = null;
		}
		
		public boolean empty()
		{
			return head == null;
		}
		
		public int length()
		{
			int ret = 0;
			if(!empty())
			{
				Node tmp = head;
				while(tmp != null)
				{
					++ret;
					tmp = tmp.next;
				}
			}
			return ret;
		}
		
		public Node front()
		{
			return head == null ? null : new Node(head.data);
		}
		
		public Node back()
		{
			return tail == null ? null : new Node(tail.data);
		}
		
		public void push(Object item)
		{
			Node tmp = new Node(item);
			if(empty())
				head = tail = tmp;
			else
			{
				tail.next = tmp;
				tail = tail.next;
			}
		}
		
		public Node pop()
		{
			if(head == null) 
				return null;
			else
			{
				Object item = head.data;
				head = head.next;
				return new Node(item);
			}
		}
		
	}
}



























