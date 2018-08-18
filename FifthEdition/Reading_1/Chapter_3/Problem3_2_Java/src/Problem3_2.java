import java.util.Stack;

class StackWithMin
{
	public StackWithMin()
	{
		items = new Stack<Integer>();
		mins = new Stack<Integer>();
	}
	
	public boolean isEmpty()
	{
		return items.empty();
	}
	
	public int length()
	{
		return items.size();
	}
	
	public Integer peek()
	{
		return items.peek();
	}
	
	public void push(int val)
	{
		if(isEmpty() || val <= mins.peek())
		{
			mins.push(val);
		}
		items.push(val);
	}
	
	public int pop() throws Exception
	{
		if(isEmpty()) throw new Exception("Attempt to pop empty stack.");
		if(items.peek() == mins.peek())
		{
			return mins.pop();
		}
		return items.pop();
	}
	
	public int min()
	{
		return mins.peek();
	}
	
	private Stack<Integer> items;
	private Stack<Integer> mins;
}

public class Problem3_2
{
	public static void main(String[] args)
		throws Exception
	{
		StackWithMin st = new StackWithMin();
		st.push(1);
		System.out.println(st.min());
		st.push(5);
		System.out.println(st.min());
		st.push(8);
		System.out.println(st.min());
		st.push(0);
		System.out.println(st.min());
		st.push(17);
		System.out.println(st.min());
		st.pop();
		System.out.println(st.min());
		st.pop();
		System.out.println(st.min());
	}
}
