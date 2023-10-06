import java.util.Scanner;

class Rectangle
{
    double length;
    double breadth;
    /*Overloaded Constructors*/
    Rectangle() //Modified Default Constructor
    {
        System.out.println("DEFAULT CONSTRUCTOR INVOKED");
        length=5555;
        breadth=5555;
    }
    
    Rectangle(double len,double bred) //Parameterised Constructor

    {
        System.out.println("PARAMETERISED CONSTRUCTOR INVOKED");
        length=len;
        breadth=bred;
    }

    /*Overloaded DispVal Methods*/
    void DispVal() 
    {
        System.out.println("(LENGTH,BREADTH): "+"("+length+" , "+breadth+")");
    }
    void DispVal(double len,double bred)
    {
        System.out.println("(LENGTH,BREADTH): "+"("+length+" , "+breadth+")");
    }
}


class ConOver
{
    public static void main(String arg[])
    {
        double l=15,b=10;
        Rectangle rect1= new Rectangle(); //instantiation with default constructor
        rect1.DispVal();
        Rectangle rect2=new Rectangle(5,10); //instantiation with parameterised constructor
        rect2.DispVal(l,b);
    }
}

