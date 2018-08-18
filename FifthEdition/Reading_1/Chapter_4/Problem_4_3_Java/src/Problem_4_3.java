class TreeNode
{
	public TreeNode(int _data)
	{
		data = _data;
	}
	
	int data = 0;
	TreeNode left = null;
	TreeNode right = null;
}

public class Problem_4_3
{
	public static void preOrder(TreeNode head)
	{
		if(head == null) return;
		preOrder(head.left);
		System.out.println(head.data);
		preOrder(head.right);
		return;
	}
	
	public static TreeNode createMinimalBST(int[] array, int start, int end)
	{
		if(start > end) return null;
		int mid = (start + end)/2;
		TreeNode n = new TreeNode(array[mid]);
		n.left = createMinimalBST(array, start, mid - 1);
		n.right = createMinimalBST(array, mid + 1, end);
		return n;
	}
	
	public static TreeNode createMinimalBST(int[] array)
	{
		return createMinimalBST(array, 0, array.length - 1);
	}
	
	
	public static void main(String[] args)
	{
		
	}
}
