import java.util.Stack;
import java.util.Vector;

class SetOfStacks
{
	private final int MAX_CAP = 3;
	private Vector<Stack<Object>> stacks;

	public SetOfStacks()
	{
		stacks = new Vector<Stack<Object>>();
	}

	private void addNewStack()
	{
		System.out.println("Adding New Stack...");
		stacks.add(new Stack<Object>());
	}
	
	private void removeStackAt(int idx)
	{
		System.out.println("Removing Empty Stack...");
		stacks.remove(stacks.elementAt(idx));
	}

	public boolean isEmpty()
	{
		return stacks.size() == 0;
	}
		
	public void push(Object ob)
	{
		System.out.println("Pushing onto SetOfStacks...");
		if(isEmpty() || stacks.elementAt(stacks.size()-1).size() == MAX_CAP) 
			addNewStack();
		stacks.elementAt(stacks.size()-1).push(ob);
	}
		
	public Object popAt(int idx)
	{
		if(isEmpty() || idx >= stacks.size()) return null;
		System.out.println("Popping SetOfStacks...");
		Object ret = stacks.elementAt(idx).pop();
		if(stacks.elementAt(idx).empty())
			removeStackAt(idx);
		return ret;
	}
	
	public Object pop()
	{
		return popAt(stacks.size()-1);
	}
	
	public void display()
	{
		System.out.println("Displaying SetOfStacks...");
		if(isEmpty()) 
			System.out.println("Stack Empty");
		else
		{
			for(int i = 0; i != stacks.size(); ++i)
			{
				for(int j = 0; j != stacks.elementAt(i).size(); ++j)
					System.out.println(stacks.elementAt(i).elementAt(j));
				System.out.println();
			}
		}
	}
}

public class Problem3_3
{
	public static void main(String[] args)
	{
		SetOfStacks s = new SetOfStacks();
		s.push(Integer.valueOf(5));
		s.push(Integer.valueOf(51));
		s.push(Integer.valueOf(15));
		s.push(Integer.valueOf(225));
		s.push(Integer.valueOf(52));
		s.push(Integer.valueOf(5));
		s.push(Integer.valueOf(51));
		s.push(Integer.valueOf(15));
		s.push(Integer.valueOf(225));
		s.push(Integer.valueOf(52));
		s.push(Integer.valueOf(5));
		s.push(Integer.valueOf(51));
		s.push(Integer.valueOf(15));
		s.push(Integer.valueOf(225));
		s.push(Integer.valueOf(52));
		s.display();
		s.popAt(2);
		s.display();
		s.popAt(2);
		s.display();
		s.popAt(2);
		s.display();
		s.popAt(2);
		s.display();
	}
}
