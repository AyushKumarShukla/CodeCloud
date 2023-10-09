import java.util.Scanner;
import java.lang.Math;

class ComplexNumber
{
	double re;
	double im;

	ComplexNumber(double a, double b)
	{
		this.re=a;
		this.im=b;
	}

	void dispNum()
	{
		System.out.println("Complex No: "+re+" + "+im+"i");
	}

    //static method to be called with respect to the class itself
    static ComplexNumber add(ComplexNumber num1, ComplexNumber num2) //arguments,return type of type ComplexNumber
	{
		double resum=num1.re+num2.re;
		double reim=num1.im+num2.im;
        //instantiating a new object with the summed values of re and im
        ComplexNumber res = new ComplexNumber(resum,reim);
        //return the reference of the new object formed
        return res;
	}
}

class Driver
{
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		System.out.println("For a number Z, Enter Z(Re) and Z(Im): ");
		double re1=scan.nextDouble();
		double im1=scan.nextDouble();
		ComplexNumber num1=new ComplexNumber(re1,im1);
		num1.dispNum();
		
		System.out.println("For a number Z, Enter Z(Re) and Z(Im): ");
		double re2=scan.nextDouble();
		double im2=scan.nextDouble();
		ComplexNumber num2=new ComplexNumber(re2,im2);
		num1.dispNum();
        //hold the reference in Main method
        ComplexNumber res=ComplexNumber.add(num1,num2); 
        System.out.print("SUM-->");
        res.dispNum();
	}
}
