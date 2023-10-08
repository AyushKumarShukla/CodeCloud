class Area
{
    double length;
    double breadth;
    Area(double len, double bred) //rectangle
    {
        this.length=len;
        this.breadth=bred;
    }
    Area(double sidelen) //square
    {
        this.length=sidelen;
        this.breadth=sidelen;
    }
    double calArea()
    {
        double res=length*breadth;
        return res;
    }
}

class Volume extends Area
{
    double height;
    Volume(double a,double b,double c) //cuboid
    {
        super(a,b); //calls the rectangle constructor
        this.height=c;
    }
    Volume(double sidelength) //cube
    {
        super(sidelength); //calls the square constructor
        height=sidelength;
    }
    double calVolume()
    {
        double res=calArea()*height;
        return res;
    }
}

class Driver
{
    public static void main(String args[])
    {
        Volume vol = new Volume(1,2,3); //Volume(10)
        double resvol=vol.calVolume();
        double resarea=vol.calArea();
        System.out.println("VOLUME,AREA: "+resvol+" , "+resarea);
    }
}
