package Problem_4_8;

class TreeNode
{
	public TreeNode(int data)
	{
		this.data = data;
	}
	
	int data;
	TreeNode left, right;

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

/*	public static boolean containsTree(TreeNode T1, TreeNode T2)
	{
		//if T1 is null and T2 is null then T1 = T2 hence return true.
		//if T1 isn't null and T2 is null then, since null subtrees 
		//are always present, return true.
		//therefore if T2 is null return true
		//else continue test
		return T2 == null ? true : subTree(T1, T2);
	}
*/
	
	public static boolean subTree(TreeNode T1, TreeNode T2)
	{
		if(T2 == null) return true;
		if(T1 == null) return false; //since T2 != null and we have recursed to a leaf of T1
		
		if(T1.data == T2.data) //then heads of potential identical subtrees are identical
			if(matchTree(T1, T2)) //tests to see if subtrees are identical 
				return true;
		
		return (subTree(T1.left, T2) || subTree(T1.right, T2)); //else traverse down T1 and re-test 
	}
	
	private static boolean matchTree(TreeNode T1, TreeNode T2)
	{
		if(T2 == null && T1 == null) return true; //traversed entirety of both trees
		if(T1 == null || T2 == null) return false; //got to end of one tree, yet not the other, hence non-identical
		
		return (T1.data != T2.data) ? false : (matchTree(T1.left, T2.left) && matchTree(T1.right, T2.right));
	}
}

public class Problem_4_8 
{
	public static void main(String[] args)
	{
		
	}
}
