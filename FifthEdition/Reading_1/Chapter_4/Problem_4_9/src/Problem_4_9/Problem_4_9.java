package Problem_4_9;

import java.util.Vector;

class TreeNode
{
	int data;
	TreeNode left, right;
	public TreeNode(int data)
	{
		this.data = data;
		left = right = null;
	}
	public static TreeNode createTree(int a[], int start, int end)
	{
		TreeNode head = null;
		if(start <= end)
		{
			int mid = (start + end)/2;
			head = new TreeNode(a[mid]);
			head.left = createTree(a, start, mid - 1);
			head.right = createTree(a, mid + 1, end);
		}
		return head;
	}
	
	private static void printPathsRec(TreeNode curr, int target, Vector<Integer> path, int sum, int level)
	{
		if(curr == null) return;
		sum += curr.data;
		if(path.size() >= level + 1) 
			path.setElementAt(curr.data, level);
		else
			path.add(curr.data);
		
		if(sum == target)
		{
			for(int i = 0; i <= level; ++i)
				System.out.print(path.elementAt(i) + " ");
			System.out.println();
		}
			
		printPathsRec(curr.left, target, path, sum, level + 1);
		printPathsRec(curr.right, target, path, sum, level + 1);
	}
	
	//Every Node is visited only once, hence this is O(N)
	public static void printPaths(TreeNode root, int target)
	{
		if(root == null) return;
		Vector<Integer> path = new Vector<Integer>();
		printPathsRec(root, target, path, 0, 0);
	}
}

class Problem_4_9
{
	public static void main(String[] args)
	{
		int a[] = {7,2,7,1,2,9,-9,9};
		TreeNode root = TreeNode.createTree(a, 0, a.length - 1);
		TreeNode.printPaths(root, 10);
	}
}