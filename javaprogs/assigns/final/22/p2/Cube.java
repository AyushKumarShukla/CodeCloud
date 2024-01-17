package p2;
import p1.Square;

public class Cube extends Square
{
    double side;
    public Cube(double s)
    {
        super(s);
        side=s;
    }

    public double getVolume()
    {
        return getArea() * side;
    }
}
