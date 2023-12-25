import java.io.*;
import java.util.*;
class InputMethods
{
    static double BufferedAdd() throws Exception
    {
        InputStreamReader r1 = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(r1);
        System.out.print("Enter the first number: ");
        double first = Double.parseDouble(br.readLine());
        System.out.print("Enter the second number: ");
        double second = Double.parseDouble(br.readLine());
        return (first+second);
    }

    static double ScannerAdd()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the first number: ");
        double first = sc.nextDouble();
        System.out.print("Enter the second number: ");
        double second = sc.nextDouble();
        return (first+second);
    }
}

class Driver
{
	public static void main(String args[]) throws Exception
	{
        double first = Double.parseDouble(args[0]);
        double second  = Double.parseDouble(args[1]);
        double sum = first + second;
        Scanner sc = new Scanner(System.in);
        System.out.format("Sum from command line input: %.2f\n",sum);
        while(true)
        {
            System.out.println("MENU:\n1.INPUT USING Scanner CLASS\n2.INPUT USING BufferedReader CLASS\n3.EXIT");
            System.out.print("\nEnter Your Choice: ");
            switch(sc.nextInt())
            {
                case 1:
                    System.out.format("Sum from Scanner Class: %.2f\n",InputMethods.ScannerAdd());
                    break;
                case 2:
                    System.out.format("Sum from BufferedReader Class: %.2f\n",InputMethods.BufferedAdd());
                    break;
                case 3:
                    System.exit(0);
                    break;
            }
        } 

				
	}
}
