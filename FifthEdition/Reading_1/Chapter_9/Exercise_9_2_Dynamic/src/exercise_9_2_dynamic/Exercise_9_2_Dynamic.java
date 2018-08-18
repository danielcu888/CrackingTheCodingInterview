package exercise_9_2_dynamic;

import java.util.ArrayList;
import java.util.HashMap;

interface constants
{
	public final static int DIM = 8;
}

class Point implements constants
{
	Point(int _x, int _y)
	{
		if(_x < 0 || _y < 0 || 
			_x >= constants.DIM || _y >= constants.DIM )
		throw new IllegalArgumentException("arguments out of range.");
		x = _x; y = _y;
	}
	
	int getX() {return x;}
	int getY() {return y;}
		
	private int x, y;
}

public class Exercise_9_2_Dynamic implements constants
{
	private static boolean isFree(int x, int y, Point hotSpots[])
	{
		if(x < 0 || y < 0 || 
				x >= constants.DIM || y >= constants.DIM )
			throw new IllegalArgumentException("arguments out of range.");
		
		for(Point p : hotSpots)
			if(p.getX() == x && p.getY() == y)
				return false;
		return true;
	}
	
	public static boolean getPath(int x, int y, ArrayList<Point> path, Point hotSpots[])
	{
		Point p = new Point(x,y);
		path.add(p);
		if(x == 0 && y == 0)
			return true;
		boolean success = false;
		if(x > 0 && isFree(x - 1, y, hotSpots))
			success = getPath(x - 1, y, path, hotSpots);
		if(!success && y > 0 && isFree(y - 1, y, hotSpots))
			success = getPath(x, y - 1, path, hotSpots);
		if(!success)
			path.remove(p);
		return success;
	}
	
	public static boolean getPath(int x, int y, ArrayList<Point> path, Point hotSpots[], HashMap<Point, Boolean> cache)
	{
		Point p = new Point(x,y);
		if(cache.containsKey(p))
			return cache.get(p);
		path.add(p);
		if(x == 0 && y == 0)
			return true;
		boolean success = false;
		if(x > 0 && isFree(x - 1, y, hotSpots))
			success = getPath(x - 1, y, path, hotSpots);
		if(!success && y > 0 && isFree(y - 1, y, hotSpots))
			success = getPath(x, y - 1, path, hotSpots);
		if(!success)
			path.remove(p);
		cache.put(p, success);
		return success;
	}
	
	public static void main(String[] args)
	{
		
	}
}
