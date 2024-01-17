interface Shape
{
    double getLength();
    double getWidth();
    double getArea();
}

class Cube implements Shape
{
    double side;
    Cube(double side)
    {
        this.side=side;
    }
    public double getLength()
    {
        return this.side;
    }
    public double getWidth()
    {
        return this.side;
    }
    public double getArea()
    {
        return this.side*this.side;
    }
}

class Cuboid implements Shape
{
    double len;
    double wid;
    double hei;
    Cuboid(double l,double w, double h)
    {
        len=l;
        wid=w;
        hei=w;
    }
    public double getLength()
    {
        return this.len;
    }
    public double getWidth()
    {
        return this.wid;
    }
    public double getArea()
    {
        return this.len*this.wid;
    }
}

class Main
{
    public static void main(String args[])
    {
        Shape c1 = new Cube(5);
        Shape c2 = new Cuboid(1,2,3);
        //dynamic method dispatch
        System.out.format("Cube Length: %.2f\n",c1.getLength());
        System.out.format("Cube Width: %.2f\n",c1.getWidth());
        System.out.format("Cube Base Area: %.2f\n\n",c1.getArea());
        System.out.format("Cuboid Length: %.2f\n",c2.getLength());
        System.out.format("Cuboid Width: %.2f\n",c2.getWidth());
        System.out.format("Cuboid Base Area: %.2f\n",c2.getArea());
    }
}
