class Shape
{
    static double calArea(int radius)
    {
        return(Math.PI*(radius*radius));
    }

    static double calArea(double side)
    {
        return(side*side);
    }

    static double calArea(double len, double wid)
    {
        return(len*wid);
    }

    static double calArea(double a, double b, double c)
    {
        try
        {
            if(!triangle(a,b,c))
                throw new ArithmeticException("Triangle Inequality Not Satisfied By The Given Sides "+a+" "+b+" "+c);
        }
        catch(ArithmeticException e)
        {
            System.out.println(e.getMessage());
            return -1;
        }
        double s = (a+b+c)/2;
        return(Math.sqrt(s*(s-a)*(s-b)*(s-c)));
    }

    static boolean triangle(double a,double b,double c)
    {
        if(a+b>c && b+c>a && c+a>b)
            return true;
        else
            return false;
    }
}

class Main
{
    public static void main(String args[])
    {
        double cir = Shape.calArea(10);
        System.out.format("Area of circle: %.2f\n",cir);
        
        double sq = Shape.calArea(4);
        System.out.format("Area of square: %.2f\n",sq);
        
        double rect = Shape.calArea(2,5);
        System.out.format("Area of rectangle: %.2f\n",rect);
        
        double tri_good = Shape.calArea(4,3,6); //sides satisfy Triangle inequality
        System.out.format("Area of valid triangle: %.2f\n",tri_good);
        
        double tri_bad = Shape.calArea(1,1,10);//sides do not satisfy Triangle inequality
        System.out.format("Area of invalid triangle: %.2f\n",tri_bad);
    }
}
