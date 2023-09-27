/**
The program takes as input a number in rupees upto two decimal places and converts it to the equivalent sum in 
paise
*/

import java.util.Scanner;

public class two
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter an amount in rupees: ");
		float amt_rup = scan.nextFloat();
		System.out.println("The amount you entered is :" + amt_rup + " Rupees");
		float amt_pai = amt_rup * 100;
		System.out.println("In paise: "+amt_pai);

	}
}
