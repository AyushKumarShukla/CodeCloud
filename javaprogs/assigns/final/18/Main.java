class CircularBase
{
    double rad;
    CircularBase(double rad)
    {
        this.rad=rad;
    }

    double calArea()
    {
        return Math.PI * rad * rad;
    }
}

class Cone extends CircularBase
{
    double height;
    Cone(double r,double h)
    {  
        super(r);
        height=h;
    }

    double volume()
    {
        return super.calArea() * (height/3.0);
    }

    public String toString()
    {
        return "RADIUS: " + rad + "\n" + "HEIGHT: " + height;

    }
}

class Cylinder extends CircularBase
{
    double height;
    Cylinder(double r,double h)
    {  
        super(r);
        height=h;
    }

    double volume()
    {
        return super.calArea() * height;
    }
    public String toString()
    {
        return "RADIUS: " + rad + "\n" + "HEIGHT: " + height;
    }
}
class Main
{
    public static void main(String args[])
    {  
        Cone c1 = new Cone(2,5);
        System.out.println("CONE OBJECT: ");
        System.out.println(c1.toString());
        double vol=c1.volume();
        System.out.format("VOLUME: %.2f",vol);

        Cylinder c2 = new Cylinder(7,2);
        System.out.println("\n\nCYLINDER OBJECT: ");
        System.out.println(c2.toString());
        vol=c2.volume();
        System.out.format("VOLUME: %.2f",vol);
        System.out.println();
    }
}
