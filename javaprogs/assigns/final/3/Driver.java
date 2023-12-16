import java.util.*;
class MyString
{
	String var;
	MyString(String inp)
	{
		this.var = inp;
	}
	int wordCount()
	{
		/*Alternate method:
			If a space is encounted, as long as the next element is a space, the 
			loop counter is incremented - this makes the control skip the 			consequetive spaces and count only non space strings
		*/
		String comp[] = var.split(" ");
		int count=comp.length;
		for(String val:comp)
		{
			//System.out.println("\nElement:"+val);
			/*if after trimming, a string becomes null. That means it was a space*/
			if(val.trim()=="") //space detection logic
			{
				//System.out.println("Space Encountered");
				count -= 1;
			}
		}
		return count;
	}

	boolean isPalindrome()
	{
		String comp[] = var.split(" ");
		String temp="";
		for(String val:comp)
		{
			if(val.trim()!=" ") //space detection logic
			{
				temp += val;			
			}
		}

		int len = temp.length();
		temp=temp.toLowerCase();
		boolean ispalin = true;
		int i,j;
		for(i=0,j=len-1; i<=j ; i++,j--)
		{
			if(temp.charAt(i) != temp.charAt(j))
			{
				ispalin = false;
			}				
		}
		return ispalin;
	}

	String reverse()
	{
		String rev="";
		for(int i=var.length()-1;i>=0;i--)
			rev += var.charAt(i);
		return rev;
	}

	String getString()
	{
		return var;
	}
}

class Driver
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the string: ");
		String inp = sc.nextLine();
		MyString str = new MyString(inp);
		System.out.format("\nEntered String: %s ",str.getString());
		System.out.format("\nNo. of words: %d\n",str.wordCount());
		System.out.format("\nPalindrome: %b",str.isPalindrome());
		System.out.format("\nReverse: %s",str.reverse());	
	}
}