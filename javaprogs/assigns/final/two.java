import java.util.*;
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

class Sort
{
	static void bubbleSort(list arr)
	{
		for(int i=0;i<arr.getLength();i++)
		{
			for(int j=0;j<arr.getLength()-1;j++)
			{
				if(arr.valueAt(j) > arr.valueAt(j+1))
				{
					int temp = arr.valueAt(j);
					arr.insertAt(j,arr.valueAt(j+1));
					arr.insertAt(j+1,temp);
				}
			}
		}
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

	void insertAt(int index,int val)
	{
		seq[index]=val;
	}
}

class Driver
{
	public static void main(String args[])
	{
		list l1 = new list(10,9,8,7,6,5,4,3,2,1);
		System.out.print("\nThe elements of the array are: ");
		l1.show();
		System.out.print("\nThe elements of the array are: ");
		Sort.bubbleSort(l1);
		l1.show();
	}
	static void showFoundMessage(int found,int key)
	{
		if(found == -1)
			System.out.format("\nElement %d is not found\n",key);
		else
			System.out.format("\nElement %d found at index %d\n",key,found);
	
	}
}