import java.util.Scanner;
class arr
{
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		int length = Integer.parseInt(args[0]);
		int[] list = new int[length];
		System.out.format("Enter array elements: \n");
		int i;
		for(i=0;i<length;i++)
		{
			int temp;
			System.out.format("Enter element %d: ",i+1);
			list[i] = scan.nextInt();
		}
		System.out.format("Entered Array: ");
		for(i=0;i<length;i++)
		{
			System.out.format("%d ",list[i]);
		}
		//linear search
		System.out.format("\nEnter the number to be found: ");
		int key = scan.nextInt();
		boolean found=false;
		int loc=-1;
		for(i=0;i<length;i++)
		{
			if(list[i]==key)
			{
				found=true;
				loc=i;
			}
		}
		if(found)
		{
			System.out.format("Element %d found at location %d",key,loc+1);
		}
		else
		{
			System.out.format("%d is not present in the array",key);	
		}
	System.out.format("\n");
	}
}
