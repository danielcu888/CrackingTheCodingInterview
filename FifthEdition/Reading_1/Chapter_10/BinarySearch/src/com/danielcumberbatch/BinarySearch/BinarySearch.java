package com.danielcumberbatch.BinarySearch;

public class BinarySearch 
{
	public static boolean binarysearchunsorted(int array[], int left, int right, int val)
	{
		if(left > right) return false;
		int mid = (left + right)/2;
		if(val == array[mid]) return true;
		return (binarysearchunsorted(array, left, mid - 1, val) || 
				binarysearchunsorted(array, mid + 1, right, val));
	}
	
	public static int binarysearchsorted_rec(int array[], int left, int right, int val)
	{
		if(left > right) return -1;
		int mid = (left + right)/2;
		if(val == array[mid]) 
			return mid;
		else if(val < array[mid])
			return binarysearchsorted_rec(array, left, mid - 1, val);
		else
			return binarysearchsorted_rec(array, mid + 1, right, val);
	}
	
	public static int binarysearchsorted(int array[], int left, int right, int val)
	{
		while(left >= right)
		{
			int mid = (left + right)/2;
			if(array[mid] == val)
				return mid;
			else if(array[mid] < val)
				left = mid +1;
			else
				right = mid - 1;			
		}
		return -1;
	}
	
	public static void main(String[] args)
	{
		int[] array = {1,4,5,2,8,9};
		System.out.println(binarysearchunsorted(array, 0, array.length-1, 1));
	}
}
