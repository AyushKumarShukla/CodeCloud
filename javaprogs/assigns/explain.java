import java.util.Scanner;

class Rectangle
{
	double length;
	double width;

	public void GetData()
	{
		Scanner scan=new Scanner(System.in);
		System.out.printf("Enter Length: ");
		length=scan.nextDouble();
		System.out.printf("Enter Width: ");
		width=scan.nextDouble();
	}

	public void area()
	{
		double res=length*width;
		System.out.print("The area is : "+res);
	}

	public void perimeter()
	{
		double peri=2*(length+width);
		System.out.print("The perimeter is : "+peri);

	}
}

public class explain
{
	public static void main(String args[])
	{
		Rectangle rect1=new Rectangle();
		rect1.GetData();
		rect1.area();
		rect1.perimeter();
	}
}
