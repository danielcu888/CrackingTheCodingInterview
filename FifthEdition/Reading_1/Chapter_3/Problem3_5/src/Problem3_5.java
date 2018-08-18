import java.util.Stack;

class MyQueue<T>
{
	private Stack<T> stackNewest, stackOldest;
	
	public MyQueue()
	{
		stackNewest = new Stack<T>();
		stackOldest = new Stack<T>();
	}
	
	public boolean isEmpty()
	{
		return size() == 0;
	}
	
	public int size()
	{
		return stackNewest.size() + stackOldest.size();
	}
	
	public T front()
	{
		if(isEmpty()) return null;
		if(stackOldest.isEmpty())
			shiftStacks(true);
		return stackOldest.peek();
	}
	
	public T back()
	{
		if(isEmpty()) return null;
		if(stackNewest.isEmpty())
			shiftStacks(false);
		return stackNewest.peek();
	}
	
	public void push(T val)
	{
		stackNewest.push(val);
	}
	
	public T pop()
	{
		if(isEmpty()) return null;
		if(stackOldest.isEmpty())
			shiftStacks(true);
		return stackOldest.pop();
	}
	
	private void shiftStacks(boolean toOld)
	{
		if(toOld) //then shift contents of stackNewest to stackOldest
		{
			while(!stackNewest.isEmpty())
				stackOldest.push(stackNewest.pop());
		}
		else
		{
			while(!stackOldest.isEmpty())  //then shift contents of stackNewest to stackOldest
				stackNewest.push(stackOldest.pop());
		}
	}
}

public class Problem3_5
{	
	public static void main(String[] args)
	{
		MyQueue test = new MyQueue();
	}
}
