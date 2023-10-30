/**
This program converts temperature in Fahrenheit to celcius using the formula: 
C = (F-32)/1.8
*/

import java.util.Scanner;

public class four
{
	public static void main(String args[])
	{
		System.out.printf("****FAHRENHEIT TO CELCIUS CONVERTER****\n");
		Scanner scan=new Scanner(System.in);
		System.out.printf("Enter temperature in Fahrenheit: ");
		float temp_in_fahr=scan.nextFloat();
		float temp_in_cel=(float)((temp_in_fahr-32)/1.8);
		System.out.printf("Temperature in Celcius:%.2f \n",temp_in_cel);

	}
}

/*
OUTPUT
SET 1:
****FAHRENHEIT TO CELCIUS CONVERTER****
Enter temperature in Fahrenheit: -40
Temperature in Celcius:-40.00
SET 2:
****FAHRENHEIT TO CELCIUS CONVERTER****
Enter temperature in Fahrenheit: 32
Temperature in Celcius:0.00
*/
