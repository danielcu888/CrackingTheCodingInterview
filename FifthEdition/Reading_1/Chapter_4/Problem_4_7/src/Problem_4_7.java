class TreeNode
{
	public TreeNode(int data)
	{
		this.data = data;
		left = right = null;
	}
	int data;
	TreeNode left, right;

	public static TreeNode minimalTree(int a[], int start, int end)
	{
		TreeNode head = null;
		if(start <= end)
		{
			int mid = (start + end)/2;
			head = new TreeNode(a[mid]);
			head.left = minimalTree(a, start, mid - 1);
			head.right = minimalTree(a, mid + 1, end);
		}
		return head;
	}

	public static boolean covers(TreeNode head, TreeNode n)
	{
		if(head == null || n == null) return false;
		if(head == n) return true;
		return (covers(head.left, n) || covers(head.right, n));
	}

	public static TreeNode FCA(TreeNode curr, TreeNode n1, TreeNode n2)
	{
		if(curr == n1 || curr == n2) return curr; //check that current node is not one of parsed descendants
		if(!covers(curr, n1) || !covers(curr, n2)) return null; //check that nodes are valid

		boolean is_n1_on_left = covers(curr.left, n1);
		boolean is_n2_on_left = covers(curr.left, n2);

		if(is_n1_on_left != is_n2_on_left) return curr;
		TreeNode child_side = is_n1_on_left ? curr.left : curr.right;
		return FCA(child_side, n1, n2);
	}

	public static void preOrder(TreeNode curr, int level)
	{
		if(curr == null) return;
		System.out.println(curr.data + ", level = " + level);
		preOrder(curr.left, level + 1);
		preOrder(curr.right, level + 1);
	}
}

public class Problem_4_7 
{
	public static void main(String[] args)
	{
		int a[] = {1,4,2,5,7,89,3};
		TreeNode head = TreeNode.minimalTree(a, 0, a.length - 1);
		TreeNode.preOrder(head, 1);
		TreeNode n1 = head.right.right;
		TreeNode n2 = head.right.left;
		
		System.out.println();
		System.out.println(n1.data + " " + n2.data + " " + TreeNode.FCA(head, n1, n2).data);
	}
}











