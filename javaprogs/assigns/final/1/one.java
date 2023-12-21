class Search
{
	static int linearSearch(list arr,int key)
	{
		for(int i=0;i<arr.getLength();i++)
		{
			if(arr.valueAt(i) == key)
				return i;
		}
		return -1;	
	}
	
	static int binarySearch(list arr,int key)
	{
		int left = 0;
		int right = arr.getLength()-1;
		while(left<=right)
		{
			int mid = (left+right)/2;
			if(arr.valueAt(mid) == key)
				return mid;
			else if(arr.valueAt(mid) < key)
				left = mid+1;
			else
				right = mid-1;
		}
		return -1;
	}
}

class list
{
	int seq[];
	
	list(int... numbers)
	{
		this.seq = new int[numbers.length];
		for(int i=0;i<numbers.length;i++)
			this.seq[i] = numbers[i];			
	}	

	void show()
	{
		for(int i=0;i<this.seq.length;i++)
		{
			System.out.format("%d ",seq[i]);
		}		
	}

	int getLength()
	{
		return seq.length;
	}

	int valueAt(int index)
	{
		return seq[index];
	}
}

class Driver
{
	public static void main(String args[])
	{
		list l1 = new list(1,3,6,8,44,55);
		System.out.print("The elements of the array are: ");
		l1.show();
		int key = 8;

		int found = Search.linearSearch(l1,key);
		showFoundMessage(found,key);

		int found2 = Search.binarySearch(l1,key);
		showFoundMessage(found2,key);
	}

	static void showFoundMessage(int found,int key)
	{
		if(found == -1)
			System.out.format("\nElement %d is not found\n",key);
		else
			System.out.format("\nElement %d found at index %d\n",key,found);
	
	}
}