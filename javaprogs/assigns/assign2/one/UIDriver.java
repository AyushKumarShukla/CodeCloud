import java.util.Scanner;
class num
{
    double value;
    num(double num)
    {
        this.value=num;
    }
    double getData()
    {
        return value;
    }
}

class Op
{
    static double add(num a, num b)
    {
        double t1=a.getData();
        double t2=b.getData();
        double sum=t1+t2;
        return sum;
    }
}

class UIDriver
{
    public static void main(String args[])
    {
        Scanner scan=new Scanner(System.in);
        System.out.print("Enter the first number: ");
        double arg1=scan.nextDouble();
        System.out.print("Enter the second number: ");
        double arg2=scan.nextDouble();
        num num1 = new num(arg1);
        num num2 = new num(arg2);
        double res=Op.add(num1,num2);
        System.out.println("SUM:"+res);
    }
}
