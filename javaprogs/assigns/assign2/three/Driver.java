import java.lang.Math;
class Cylinder
{
    double radius;
    double height;
    Cylinder(double radius,double height)
    {
        this.radius=radius;
        this.height=height;
    }
    double surfaceArea()
    {
        double result=(2*Math.PI*radius)*(radius+height);
        return result;
    }
    double volume()
    {
        double result=Math.PI*Math.pow(radius,2)*height;
        return result;
    }
}

class Driver
{
    public static void main(String args[])
    {
        double r = Double.parseDouble(args[0]);
        double h = Double.parseDouble(args[1]);
        Cylinder cyl = new Cylinder(r,h);
        double result1=cyl.surfaceArea();
        double result2=cyl.volume();
        System.out.println("TSA: "+result1);
        System.out.println("VOLUME: "+result2);
    }
}

