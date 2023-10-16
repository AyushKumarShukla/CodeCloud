//abstract class defines the member methods of derieved classes
abstract class Shape
{
    abstract double area();
    abstract void disp();
}
//all derieved classes have to override the abstract methods in the abstract class Shape
class Rectangle extends Shape
{
    double len,wid;
    Rectangle(double len,double wid)
    {
        this.len=len;
        this.wid=wid;
    }
    double area()
    {
        return(len*wid);
    }
    void disp()
    {
        System.out.println("(Length,Width): "+len+" "+wid);
    }
}

class Circle extends Shape
{
    double radius;
    Circle(double rad)
    {
        this.radius=rad;
    }
    double area()
    {
        double pi = 3.14159265358978932386426434142;
        return(pi*radius*radius);
    }
    void disp()
    {
        System.out.println("Radius: "+radius);
    }
}

class Triangle extends Shape
{
    double base,height;
    Triangle(double b,double h)
    {
        this.base=b;
        this.height=h;
    }
    double area()
    {
        return(0.5*base*height);
    }
    void disp()
    {
        System.out.println("(Base,Height): "+base+" "+height);
    }

}

class Driver
{
    public static void main(String args[])
    {
        Rectangle rect1 = new Rectangle(10,20);
        double res=rect1.area();
        System.out.println("Area of Rect1: " + res);
        rect1.disp();

        System.out.println();

        Circle cir1 = new Circle(10);
        double res1=cir1.area();
        System.out.println("Area of cir1: "+res1);
        cir1.disp();

        System.out.println();

        Triangle tri1 = new Triangle(10,10);
        double res2=tri1.area();
        System.out.println("Area of tri1: "+res2);
        tri1.disp();
    }
}
