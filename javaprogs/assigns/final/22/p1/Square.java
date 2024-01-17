package p1;
public class Square
{
    double side;
    public Square(double s)
    {
        side=s;
    }

    public double getSide()
    {
        return side;
    }

    public double getArea()
    {
        return side*side;
    }
}
