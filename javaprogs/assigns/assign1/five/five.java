/** A program to determine sum of the following series for given value of n:(1 + 1/2 + 1/3 + 
…… + 1/n)  up to two decimal places
*/
import java.util.Scanner;

public class five
{
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		System.out.printf("Enter a value of n: ");
		long terms=scan.nextLong();
		float sum=0f;
		for(int i=1;i<=terms;i++)
		{
			sum+=(1.0f/i);
		}
		System.out.printf("Computed Value Of Series: %f\n",sum);

	}
}
/*Limit of the series found to be 15.403683 approximately*/
