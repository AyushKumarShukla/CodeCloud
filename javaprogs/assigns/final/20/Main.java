interface TwoDimensions
{
    double getLength();
    double getWidth();
}

interface ThreeDimensions
{
    double getArea();
    double getHeight();
}

interface Shape extends TwoDimensions, ThreeDimensions
{
    double getVolume();
}

class Rect
{
    double len;
    double wid;
    Rect(double l,double w)
    {
        len=l;
        wid=w;
    }
    public double getArea()
    {
        return len*wid ;
    }
}

class Cuboid extends Rect implements Shape
{
    double height;
    
    Cuboid(double l,double w,double h)
    {
        super(l,w);
        height=h;
    }
    
    public double getLength()
    { 
        return len;
    }

    public double getWidth()
    {
        return wid;
    }

    public double getHeight()
    {
        return height;
    }

    public double getVolume()
    {
        return getArea()*height;
    }

}

class Main
{
    public static void main(String args[])
    {
        Cuboid c1 = new Cuboid(5,5,5);
        System.out.format("Length: %.2f\n",c1.getLength());
        System.out.format("Width: %.2f\n",c1.getWidth());
        System.out.format("Height: %.2f\n",c1.getHeight());
        System.out.format("Base Area: %.2f\n",c1.getArea());
        System.out.format("Volume: %.2f\n",c1.getVolume());

    }
}
