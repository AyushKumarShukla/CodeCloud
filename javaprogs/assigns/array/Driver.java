import java.util.Scanner;
class seq
{
	int arr[]; //reference for array object
	seq(int size) //given size
	{
		arr = new int[size];
	}
	//the copy constructor takes an object of the same class as an argument, and performs piece-meal	copy of the elements from arr of argument object to arr of the this object
	seq(seq list)
	{
		arr = new int[list.arr.length];
		for(int i=0;i<list.arr.length;i++)
		{
			this.arr[i] = list.arr[i];
		}
	}
	void inputArray()
	{
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<arr.length;i++)
			arr[i] = sc.nextInt();
	}
	void showArray()
	{
		for(int i=0;i<arr.length;i++)
			System.out.format("%d ",arr[i]);
	}
}

class Sorts
{
	static seq bubbleSort(seq list)
	{
		int temp;
		for(int i=0;i<list.arr.length;i++)
			for(int j=0;j<list.arr.length-1;j++)
				if(list.arr[j]>list.arr[j+1])
				{
					temp=list.arr[j];
					list.arr[j]=list.arr[j+1];
					list.arr[j+1]=temp;
				}
		seq ret = new seq(list);
		return ret;
	}
}

class Searches
{
	static int linearSearch(seq list,int key)
	{
		for(int i=0;i<list.arr.length;i++)
		{
			if(list.arr[i]==key)
				return i;
		}
		return -1;
	}
}

class Menu
{
	static void printMenu()
	{
		  System.out.println("\nMENU:");
                  System.out.println("1. Input Array");
                  System.out.println("2. Display Array");
                  System.out.println("3. Linear Search");
                  System.out.println("4. Bubble Sort");
                  System.out.println("5. Re-enter Array");
                  System.out.println("6. Exit");
	}

}

class Driver
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		boolean exit=false;
		System.out.println("Enter the size of array: ");
		int inp = sc.nextInt();
		seq list1 = new seq(inp);
		System.out.format("A list of size %d generated",inp);
		while(!exit)
		{
			Menu.printMenu();
			System.out.println("Enter your choice");
			int ch = sc.nextInt();
			switch(ch)
			{
				case 1:
					System.out.print("Enter Elements: ");
					list1.inputArray();
					break;
				case 2:
					System.out.print("Entered Elements: ");
					list1.showArray();
					System.out.println();
					break;
				case 3:
					System.out.println("Enter key:");
					int key = sc.nextInt();
					int ret = Searches.linearSearch(list1,key);
					System.out.format("Key %d found at location %d\n",key,ret);
					break;
				case 4:
					Sorts.bubbleSort(list1);
					System.out.println("Sorted array: ");
					list1.showArray();
					break;
				case 5:
					System.out.println("Enter the size of array: ");
					int size = sc.nextInt();
					list1 = new seq(size);
					System.out.format("A list of size %d generated",list1.arr.length);	
					break;
				case 6:
					System.exit(0);
					break;
			}

		}


		/*seq list2 = new seq(list1);
		System.out.println("A list of size 10 generated");
		System.out.println("Copy Constructed Values: ");
		list2.showArray();
		System.out.println();*/
	}
}

