class TreeNode
{
	public TreeNode(int data)
	{
		this.data = data;
		left = right = parent = null;
	}
	
	int data;
	TreeNode left, right, parent;

	public static TreeNode minimalBST(int[] a, int start, int end)
	{
		TreeNode head = null;
		if(start <= end)
		{
			int mid = (start + end)/2;
			head = new TreeNode(a[mid]);
			head.left = minimalBST(a, start, mid - 1);
			if(head.left != null) head.left.parent = head;
			head.right = minimalBST(a, mid + 1, end);
			if(head.left != null) head.right.parent = head;
		}
		return head;
	}

	public static void inOrderTrav(TreeNode curr, int level)
	{
		if(curr == null) return;
		inOrderTrav(curr.left, level + 1);
		System.out.println(curr.data + " level = " + level);
		inOrderTrav(curr.right, level + 1);
	}
		
	public static TreeNode findNextInOrder(TreeNode n)
	{
		if(n == null) return null;
		
		if(n.right != null)
			return leftMostChild(n.right);
		else
			return nextLargerParent(n);
	}
	
	public static TreeNode leftMostChild(TreeNode n)
	{
		while(n.left != null)
			n = n.left;
		return n;
	}
	
	public static TreeNode nextLargerParent(TreeNode n)
	{
		TreeNode tmp = n;
		while(tmp.parent != null && tmp.parent.data < n.data)
			tmp = tmp.parent;
		return tmp.parent;
	}
	
}

public class Problem_4_6 
{
	public static void main(String[] args)
	{
		int a[] = {1,8,9,10,15,16,17,18};
		TreeNode head = TreeNode.minimalBST(a, 0, a.length - 1);
		System.out.println(head.left.right.data);
		TreeNode tmp = TreeNode.findNextInOrder(head.right.right.right);
		if(tmp != null)
			System.out.println(tmp.data);
		else
			System.out.println("null");
	}
}
