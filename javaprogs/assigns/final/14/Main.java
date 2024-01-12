
abstract class Shape
{
    abstract double area();
    abstract void disp();
}

class Rectangle extends Shape
{
    double len;
    double wid;
    
    Rectangle(double a, double b)
    {
        len=a;
        wid=b;
    }

    double area()
    {
        return len*wid;
    }

    void disp()
    {
        System.out.format("Side length: (%.2f , %.2f) , Area: %.2f\n",len,wid,area());
    }
}

class Circle extends Shape
{
    double rad;
    
    Circle(double a)
    {
        rad=a;
    }

    double area()
    {
        return Math.PI*(rad*rad);
    }

    void disp()
    {
        System.out.format("Radius: %.2f , Area: %.2f\n",rad,area());
    }
}

class Triangle extends Shape
{
    double len;
    double wid;
    double high;
    
    Triangle(double a, double b,double c)
    {
        len=a;
        wid=b;
        high=c;
    }

    double area()
    {
        return len*wid*high;
    }

    void disp()
    {
        System.out.format("Side length: (%.2f , %.2f , %.2f) , Area: %.2f\n",len,wid,high,area());
    }
}

class Main
{
    public static void main(String args[])
    {
        Rectangle rect = new Rectangle(1.5,2.1);
        System.out.println("Rectangle object: ");
        rect.disp();
       
        Circle cir = new Circle(5);
        System.out.println("Circle Object: ");
        cir.disp();
        
        Triangle tri = new Triangle(1.2,2.5,3.1);
        System.out.println("Triangle Object: ");
        tri.disp();
    }
}
