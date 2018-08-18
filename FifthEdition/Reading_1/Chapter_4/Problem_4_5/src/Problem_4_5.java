class TreeNode
{
	int data = 0;
	TreeNode left = null, right = null;

	public TreeNode(int _data)
	{
		data = _data;
	}
	
	public static TreeNode minimalBST(int a[], int start, int end)
	{
		TreeNode head = null;
		if(start <= end)
		{
			int mid = (start + end)/2;
			head = new TreeNode(a[mid]);
			head.left = minimalBST(a, start, mid - 1);
			head.right = minimalBST(a, mid + 1, end);
		}
		return head;
	}
	
	public static boolean isBST(TreeNode curr)
	{
		boolean ret = true;
		if(curr.left != null)
			ret = ret && (curr.left.data <= curr.data) && isBST(curr.left);
		if(curr.right != null)
			ret = ret && (curr.right.data >= curr.data) && isBST(curr.right);
		return ret;
	}
}

public class Problem_4_5 
{
	public static void main(String[] args)
	{
		int a[] = {0,1,2,3,4,5,6,7,8,9};
		TreeNode head = TreeNode.minimalBST(a, 0, a.length - 1);
		System.out.println(TreeNode.isBST(head));
	}
}