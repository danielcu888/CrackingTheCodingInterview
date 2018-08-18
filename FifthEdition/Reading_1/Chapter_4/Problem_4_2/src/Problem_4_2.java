import java.util.*;

import org.w3c.dom.Node;

enum State
{
	Unvisited, Visiting, Visited;
}

static boolean search(Graph g, Node start, Node end)
{
	LinkedList<Node> q = new LinkedList<Node>();
	for(Node u : g.getNodes())
		u.state = State.Unvisited;
	start.state = State.Visiting;
	q.add(start);
	Node u;
	while(!q.isEmpty())
	{
		u = q.removeFirst();
		for(Node v : u.getAdjacentNodes())
		{
			if(v.state == State.Unvisited)
				{
					if(v == end) 
						return true;
					else
					{
						v.state = State.Visiting;
						q.add(v);
					}
				}
		}
		u.state = State.Visited;
	}
	return false;
}

public class Problem_4_2
{
	public static void main(String[] args)
	{
		
	}
}
