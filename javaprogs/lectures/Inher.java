//inheritance path : line->plane->space
class line
{
    double x;
    line(double x)
    {
        this.x=x;
    }

    void calLen()
    {
        System.out.println("LENGTH: "+x);
    }
}

class plane extends line
{
    double y;
    plane(double x,double y)
    {
        super(x);
        this.y=y;
    }

    void calArea()
    {
        double res=x*y;
        System.out.println("AREA: "+res);
    }
}

class space extends plane //multilevel inheritance
{
    double z;
    space(double x,double y,double z)
    {
        super(x,y); //Invoking the constructor of superclass
        this.z=z; 
    }
    void calVol()
    {
        double res=x*y*z;
        System.out.println("VOL: "+res);
    }

}

class Inher
{
    public static void main(String args[])
    {
        space one = new space(10,20,30); //instantiating space object
        one.calLen();
        one.calArea();
        one.calVol();
    }
}
