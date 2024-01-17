import p2.Cube;

//the directory in which this source file lies is the current working directory, that is, the root of all 
//packages 

//Any package access will only in the starting from the current working directory, if the required package is
//within another directory, it will not be visible
class Main
{
    public static void main(String args[])
    {
        Cube c = new Cube(10);
        System.out.format("Side Length: %.2f\n",c.getSide());
        System.out.format("Base Area: %.2f\n",c.getArea());
        System.out.format("Volume: %.2f\n",c.getVolume());
    }
}
