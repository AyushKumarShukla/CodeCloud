interface Shape
{
	final double PI = 3.14159;
	double area(double rad);
}

class Circle implements Shape
{
	public double area(double rad)
	{
		return(PI*rad*rad);
	}
}

class Sphere implements Shape
{
	public double area(double rad)
	{
		return(4*PI*rad*rad);
	}
}

class Driver
{
	public static void main(String args[])
	{
		double res1,res2;
		Circle cir = new Circle();
		Sphere sph = new Sphere();
		res1 = cir.area(10);
		res2 = sph.area(10);
		System.out.format("Area: %f\nSurface Area: %f\n",res1,res2);
	}
}
