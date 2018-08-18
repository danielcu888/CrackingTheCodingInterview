import java.util.Stack;
import java.util.Random;

class TowersOfHanoi
{
	static final int N = 3;
	static final int T = 5;
	
	class Disc
	{
		public Disc(int sz)
		{
			if(sz > N || sz < 1)
				throw new IllegalArgumentException("Illegal Disc Size");
			sizeOfDisc = sz;
		}
		
		public int size()
		{
			return sizeOfDisc;
		}
				
		final int sizeOfDisc;
	}
	
	public TowersOfHanoi()
		throws Exception
	{
		if(N < 1 || T < 1)
			throw new Exception("Illegal number of discs or towers!");
		towers = new Stack[T];
		for(int i = 0; i != T; ++i)
			towers[i] = new Stack<Disc>();
		for(int i = N; i > 0; --i)
			towers[0].push(new Disc(i));
	}
		
	public void display()
	{
		if(!status())
		{
			System.out.println("Attempt to display failed - game unfinished!");
			return;
		}
		
		while(!towers[T-1].empty())
			System.out.println(towers[T-1].pop().size());
	}
	

	public void move()
	{
		int ranLoc = randomGenerator.nextInt(T);
		int ranDest = randomGenerator.nextInt(T);
		while(towers[ranLoc].empty() || ranLoc == ranDest || 
		      (!towers[ranDest].empty() && towers[ranLoc].peek().size() > towers[ranDest].peek().size()))
		{
			ranLoc = randomGenerator.nextInt(T);
			ranDest = randomGenerator.nextInt(T);
		}
		towers[ranDest].push(towers[ranLoc].pop());
	}
	
	public boolean status()
	{
		for(int i = 0; i != T-1; ++i)
			if(!towers[i].empty()) return false;
		return true;
	}
	
	private Random randomGenerator = new Random();
	private Stack<Disc> towers[];
}

public class Problem3_4
{
	public static void main(String[] args)
		throws Exception
	{
		int numMoves = 0;
		TowersOfHanoi tow = new TowersOfHanoi();
		while(!tow.status())
		{
			tow.move();
			++numMoves;
		}
		System.out.println("Finished in " + numMoves + " moves!");
		tow.display();
	}
}
