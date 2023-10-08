import java.lang.Math;
class Shape
{
    static double Area(double a,double b,double c)
    {
        if(!(a+b>c && b+c>a && c+a>b))
        {
            System.out.println("TRIANGLE INEQUALITY BROKEN");
            System.exit(1);
        }
        double s=(a+b+c)/2;
        double res1=Math.sqrt(s*(s-a)*(s-b)*(s-c));
       
        return res1;
    }
    static double Area(double length,double breadth)
    {
        double res2=length*breadth;
        return res2;
    }
    static double Area(double length)
    {
        double res3=length*length;
        return res3;
    }
}

class Driver
{
    public static void main(String args[])
    {
        double a = Double.parseDouble(args[0]);
        double b = Double.parseDouble(args[1]);
        double c = Double.parseDouble(args[2]);
        double square=Shape.Area(a);
        double rect=Shape.Area(a,b);
        double tri=Shape.Area(a,b,c);
        System.out.println("AREA: (SQUARE,RECT,TRI):"+square+" "+rect+" "+tri);

    }
}
