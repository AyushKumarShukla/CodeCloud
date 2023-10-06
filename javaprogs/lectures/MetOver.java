import java.util.Scanner;
import java.lang.Math;
class Figure
{
    static void calArea(double length)
    {
        double res=Math.pow(length,2);
        System.out.println("AREA OF SQUARE: "+res);
    }
    
    static void calArea(int length,int breadth) //parameter list with ints
    {
        double res = length * breadth;
        System.out.println("FLOOR(AREA) OF RECTANGLE: "+res);
    }

    static void calArea(double length,double breadth) //parameter list with doubles
    {
        double res = length * breadth;
        System.out.println("AREA OF RECTANGLE: "+res);
    }

    static void calArea(double length,double breadth,double height)
    {
        double res = length * breadth * height;
        System.out.println("AREA OF CUBOID: "+res);
    }
}

class MetOver
{
    public static void main(String args[])
    {
        int l=10,b=20,h=30;
        Figure.calArea(l,b);
    }
}
