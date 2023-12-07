import java.lang.Math;
class Eq
{
    static double[] quad(double a,double b,double c)
    {
        double roots[] = new double[2]; // array to hold roots
        double det = Math.sqrt((b*b)-4*a*c);
        if(det<0)
            System.exit(1); // imaginary roots
        else
        {
            double root1 = (-b + det)/(2*a);
            double root2 = (-b - det)/(2*a);
            roots[0] = root1;
            roots[1] = root2;
        }
        return roots;
    }
}
class Driver
{
    public static void main(String args[])
    {
        double a = Double.parseDouble(args[0]);
        double b = Double.parseDouble(args[1]);
        double c = Double.parseDouble(args[2]);
        double res[] = Eq.quad(a,b,c);
        System.out.format("The roots are %f and %f\n",res[0],res[1]);
    }
}
