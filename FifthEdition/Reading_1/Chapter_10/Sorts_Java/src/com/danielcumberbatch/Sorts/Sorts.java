package com.danielcumberbatch.Sorts;

public class Sorts 
{
	public static void MergeSort(int[] array, int low, int high)
	{
		if(low < high)
		{
			int middle = (low + high)/2;
			MergeSort(array, low, middle);
			MergeSort(array, middle + 1, high);
			Merge(array, low, middle, high);
		}
	}
	
	protected static void Merge(int[] array, int low, int middle, int high)
	{
		int[] helper = new int[array.length];
		
		for(int i = low; i <= high; ++i)
			helper[i] = array[i];
		
		int helperLeft = low;
		int helperRight = middle + 1;
		int current = low;
		
		while(helperLeft <= middle && helperRight <= high)
		{
			if(helper[helperLeft] <= helper[helperRight])
			{
				array[current] = helper[helperLeft];
				++helperLeft;
			}
			else
			{
				array[current] = helper[helperRight];
				++helperRight;
			}
			++current;
		}
		
		while(helperLeft <= middle)
			array[current++] = helper[helperLeft++];
	}

	protected static void swap(int[] array, int i, int j)
	{
		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
	
	public static void QuickSort(int[] array, int left, int right)
	{
		int index = partition(array, left, right);
		if(left < index - 1) QuickSort(array, left, index - 1);
		if(right > index) QuickSort(array, index, right);
	}	
	
	protected static int partition(int array[], int left, int right)
	{
		if(left<=right)
		{
			int mid = array[(left + right)/2];
			while(left <= right)
			{
				while(array[left] < mid && left < array.length)
					++left;
				while(array[right] > mid && right >= 0)
					--right;			
				if(left <= right) 
					swap(array, left++, right--);
			}
		}
		return left;
	}
	
	public static void main(String[] args)
	{
		int[] array = {1,4,5,2,8,9};
		//MergeSort(array, 0, array.length - 1);
		QuickSort(array, 0, array.length - 1);
		for(int i : array)
			System.out.print(i + " ");
		System.out.println();
	}

}

