interface MathConst
{
    final static double PI = 3.14;
    final static double E = 2.71;
    void printConst();
}

class MathOp
{
    double add(double a,double b)
    {
        double res=a+b;
        return res;
    }
    double sub(double a,double b)
    {
        double res=a-b;
        return res;
    }
}

class Calculate extends MathOp implements MathConst
{
    public void printConst()
    {
        System.out.format("(PI,E): %f,%f",PI,E);
    }
    void calculate()
    {
        double res1 = add(PI,E);
        double res2 = sub(PI,E);
        System.out.format("\nSum:%f,Diff:%f\n",res1,res2);
    }
}

class Driver
{
    public static void main(String args[])
    {
        Calculate obj1 = new Calculate();
        obj1.printConst();
        obj1.calculate();
    }
}
