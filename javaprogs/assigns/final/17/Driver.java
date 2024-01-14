class Rectangle
{
    double length;
    double breadth;
    Rectangle(double len, double bred) //rectangle
    {
        this.length=len;
        this.breadth=bred;
    }
    Rectangle(double sidelen) //square
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

class Volume extends Rectangle
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
        double res=super.calArea()*height;
        return res;
    }
    double calArea()
    {
        double res = 2*(length*breadth + breadth*height + height*length);
        return res;
    }
    public String toString()
    {
        return "LENGTH: " + length + "\n" + "WIDTH: " + breadth + "\n" + "HEIGHT: " + height;
    }
}

class Driver
{
    public static void main(String args[])
    {
        Volume rect = new Volume(2,3,6); //Volume(10)
        System.out.println("RECTANGLE/CUBOID OBJECT: ");
        System.out.println(rect.toString());
        double vol=rect.calVolume();
        double surfacearea=rect.calArea();
        System.out.println("VOLUME , AREA: "+vol+" , "+surfacearea);

        Volume cube = new Volume(2); //Volume(10)
        System.out.println("\nSQUARE/CUBE OBJECT: ");
        System.out.println(cube.toString());
        vol=cube.calVolume();
        surfacearea=cube.calArea();
        System.out.println("VOLUME , AREA: "+vol+" , "+surfacearea);
    
    }
}
