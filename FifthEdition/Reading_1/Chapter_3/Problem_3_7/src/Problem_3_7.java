class Pet
{
	public Pet(boolean _isDog, String _name)
	{
		isDog = _isDog;
		next = null;
		name = _name;
	}
	
	Pet next;
	boolean isDog;
	String name;
}

class PetQueue
{
	public PetQueue()
	{
		head = null;
		tail = null;
	}
	
	public void enqueue(Pet p)
	{
		System.out.println("Adding a new pet...");
		if(head == null)
			head = tail = p;
		else
		{
			tail.next = p;
			tail = tail.next;
		}
	}
	
	public Pet dequeueAny()
	{
		System.out.println("removing oldest pet...");
		if(head == null)
			return null;
		else
		{
			Pet ret = head;
			head = head.next;
			ret.next = null;
			return ret;
		}
	}
	
	private Pet dequeue(boolean b)
	{
		Pet ret = null;
		if(head == null)
			return null;
		else if(head.isDog == b)
		{
			ret = head;
			head = head.next;
			ret.next = null;
		}
		else
		{
			Pet tmp = head;
			while(tmp.next != null && tmp.next.isDog != b)
				tmp = tmp.next;
			if(tmp.next != null)
			{
				ret = tmp.next;
				tmp.next = ret.next;
				ret.next = null;
			}
		}

		return ret;
	}

	public Pet dequeueDog()
	{
		System.out.println("removing oldest dog...");
		return dequeue(true);
	}
	
	public Pet dequeueCat()
	{
		System.out.println("removing oldest cat...");
		return dequeue(false);
	}
	
	public void display()
	{
		Pet tmp = head;
		while(tmp != null)
		{
			System.out.println(tmp.name + (tmp.isDog ? " is a dog" : " is a cat"));
			tmp = tmp.next;
		}
	}
	
	private Pet head, tail;
}


public class Problem_3_7
{
	public static void main(String[] args)
	{
		PetQueue pq = new PetQueue();
		pq.enqueue(new Pet(true, "dog1"));
		pq.enqueue(new Pet(true, "dog2"));
		pq.enqueue(new Pet(false, "cat1"));
		pq.enqueue(new Pet(true, "dog3"));
		pq.enqueue(new Pet(false, "cat2"));
		
		pq.display();
		
		pq.dequeueAny();
		pq.display();
		
		pq.dequeueCat();
		pq.display();
		
		pq.dequeueCat();
		pq.display();
	}
}









