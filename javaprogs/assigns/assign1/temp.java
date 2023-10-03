import java.util.Scanner;
/**
The program takes input the length and width of a rectangle and returns the area and perimeter.
*/
class rectangle
{
	double length;
	double width;
	//set the instance variables of the object
	public void setDimensions(double a, double b)
	{
		length=a;
		width=b;
	}
	//compute area
	public double area()
	{
		return length*width;
	}
	//compute perimeter
	public double perimeter()
	{
		return 2*(length+width);
	}	
}

class Driver
{
	public static void main(String args[])
	{
		System.out.printf("To compute area and perimeter of a rectangle: \n");
		//scanner object for taking user input
		Scanner scan = new Scanner(System.in);
		//creating an object of class rectangle
		rectangle rect1=new rectangle(); //create an object of type rectangle in memory
		//take user input
		System.out.print("Enter the length of the rectangle: ");
		double len=scan.nextDouble();
		System.out.print("Enter the width of the rectangle: ");
		double wid=scan.nextDouble();
		//call methods
		rect1.setDimensions(len,wid);
		double area=rect1.area();
		double peri=rect1.perimeter();
		//display result using printf method
		System.out.printf("AREA: %.2f\nPERIMETER: %.2f\n",area,peri);
	}
}
/*
OUTPUT
SET 1:
To compute area and perimeter of a rectangle:
Enter the length of the rectangle: 15.2
Enter the width of the rectangle: 23.365
AREA: 355.15
PERIMETER: 77.13

SET 2:
To compute area and perimeter of a rectangle:
Enter the length of the rectangle: 20
Enter the width of the rectangle: 20
AREA: 400.00
PERIMETER: 80.00

*/
