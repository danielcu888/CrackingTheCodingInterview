public class Problem_3_1
{
	class TripleStack
	{
		private int stackSize;
		private int[] buffer = new int[3 * stackSize];
		private int[] stackPointers = {0,0,0};
		
		public TripleStack(int stackSize)
		{
			if(stackSize < 1) throw new IllegalArgumentException("invalid stack size");
			this.stackSize = stackSize;
		}

		public boolean empty(int stackNum)
		{
			if(stackNum < 0 || stackNum >= 3) throw new ArrayIndexOutOfBoundsException("Invalid stackNum");
			return stackPointers[stackNum] == 0;
		}
		
		public int length(int stackNum)
		{
			if(stackNum < 0 || stackNum >= 3) throw new ArrayIndexOutOfBoundsException("Invalid stackNum");			
			return stackPointers[stackNum];
		}
		
		public int top(int stackNum)
		{
			if(stackNum < 0 || stackNum >= 3) throw new ArrayIndexOutOfBoundsException("Invalid stackNum");
			return buffer[stackNum * stackSize + stackPointers[stackNum]];
		}
		
		public void push(int stackNum, int value) throws Exception
		{
			if(stackNum < 0 || stackNum >= 3) throw new ArrayIndexOutOfBoundsException("Invalid stackNum");
			if(stackPointers[stackNum] == stackSize)
				throw new Exception("stack is full");
			buffer[stackNum * stackSize + stackPointers[stackNum] + 1] = value;
			stackPointers[stackNum]++;
		}
	
		public void pop(int stackNum) throws Exception
		{
			if(stackNum < 0 || stackNum >= 3) throw new ArrayIndexOutOfBoundsException("Invalid stackNum");
			if(stackPointers[stackNum] == 0)
				throw new Exception("Attempt to pop an empty stack");
			buffer[stackNum * stackSize + stackPointers[stackNum]] = 0;
			--stackPointers[stackNum];
		}
	}
}
















