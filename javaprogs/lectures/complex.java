import java.util.Scanner;
import java.lang.Math;

class ComplexNumber
{
	double re;
	double im;

	void getInput(double a, double b)
	{
		re=a;
		im=b;
	}

	void dispNum()
	{
		System.out.println("Complex No: "+re+" + "+im+"i");
	}

	double modulus()
	{
		double res= Math.sqrt(Math.pow(re,2)+Math.pow(im,2));
		return res;
	}
}
class Imath
{
	static void add(ComplexNumber num1, ComplexNumber num2)
	{
		double resum=num1.re+num2.re;
		double reim=num1.im+num2.im;
		System.out.println("SUM: "+resum+" + "+reim+"i");
	}
	
	static void sub(ComplexNumber num1, ComplexNumber num2)
	{
		double resum=num1.re-num2.re;
		double reim=num1.im-num2.im;
		System.out.println("DIFF: "+resum+" + "+reim+"i");
	}
	
	static void mult(ComplexNumber num1, ComplexNumber num2)
	{
		double a = num1.re;
		double c = num2.re;
		double b = num1.im;
		double d = num2.im;

		double re_of_prod=(a*c)-(b*d);
		double im_of_prod=(a*d)+(b*c);

		System.out.println("PROD: "+re_of_prod+" + "+im_of_prod+"i");
	}
	
	static void div(ComplexNumber num1, ComplexNumber num2)
	{
		double a = num1.re;
		double c = num2.re;
		double b = num1.im;
		double d = num2.im;
			
		double re_of_div=(a*c+b*d)/(Math.pow(c,2)+Math.pow(d,2));
		double im_of_div=(b*c-a*d)/(Math.pow(c,2)+Math.pow(d,2));

		System.out.println("QUOT: "+re_of_div+" + "+im_of_div+"i");
	}
}
class Driver
{
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);

		ComplexNumber num1=new ComplexNumber();
		System.out.println("For a number Z, Enter Z(Re) and Z(Im): ");
		double re=scan.nextDouble();
		double im=scan.nextDouble();
		num1.getInput(re,im);
		num1.dispNum();
		
		ComplexNumber num2=new ComplexNumber();
		System.out.println("For a number Z, Enter Z(Re) and Z(Im): ");
		double re1=scan.nextDouble();
		double im1=scan.nextDouble();
		num2.getInput(re1,im1);
		num2.dispNum();

		Imath.add(num1,num2);
		Imath.sub(num1,num2);
		Imath.mult(num1,num2);
		Imath.div(num1,num2);

	}
}
