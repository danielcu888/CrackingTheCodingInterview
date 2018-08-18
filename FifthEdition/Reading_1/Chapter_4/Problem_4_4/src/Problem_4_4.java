class myInteger
{
	public myInteger(int _val)
	{
		val = _val;
	}
	
	int val = 0;
}

class TreeNode
{
    public TreeNode(int _data)
    {
        data = _data;
        left = null;
        right = null;
        next = null;
    }
   
    int data;
    TreeNode left, right, next;

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

    public static int depth(TreeNode head)
    {
        myInteger max_level = new myInteger(0);
        preOrder(head, 1, max_level);
        return max_level.val;
    }
 
    public static void preOrder(TreeNode curr, int level, myInteger max_level)
    {
        if(curr == null) return;
        if(level > max_level.val) max_level.val = level;
        preOrder(curr.left, level + 1, max_level);
        //System.out.println("data = " + curr.data + ", level = " + level + ", max_level = " + max_level.val);
        preOrder(curr.right, level + 1, max_level);
    }
    
    public static TreeNode appendToTail(TreeNode head, TreeNode n)
    {
        if(head == null) return n;
        TreeNode tmp = head;
        while(tmp.next != null)
            tmp = tmp.next;
        tmp.next = n;
        return head;
    }
    
    public static void preOrderConnect(TreeNode curr, TreeNode[] arr, int level)
    {
        if(curr == null) return;
        arr[level] = appendToTail(arr[level], curr);
        preOrderConnect(curr.left, arr, level + 1);
        preOrderConnect(curr.right, arr, level + 1);
    }
    
    public static TreeNode[] breadthConnect(TreeNode head)
    {
        int max_level = depth(head);
        TreeNode arr[] = new TreeNode[max_level];
        preOrderConnect(head, arr, 0);
        return arr;
    }
    
    public static void traverseLL(TreeNode head)
    {
        while(head != null)
        {
            System.out.print(head.data + " ");
            head = head.next;
        }
    }
}


public class Problem_4_4
{ 
	public static void main(String[] args)
	{
		int[] a = {1,2,3,4,5,6,7,8,9};
		TreeNode head = TreeNode.minimalBST(a, 0, a.length-1);
        TreeNode[] arr = TreeNode.breadthConnect(head);
        for(int i = 0; i != arr.length; ++i)
            {
        		System.out.print("The TreeNodes on level " + (i+1) + " are: ");
        		TreeNode.traverseLL(arr[i]);
                System.out.println();
            }
	}
}
	
	
	
	
	
	
	
	