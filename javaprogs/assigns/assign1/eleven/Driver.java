class Accounting
{
    static double simpleInterest(double prin,double rate,double time)
    {
        return(0.01*prin*rate*time);
    }
}

class Driver
{   
    public static void main(String args[])
    {
        double prin = Double.parseDouble(args[0]);
        double rate = Double.parseDouble(args[1]);
        double time = Double.parseDouble(args[2]);
        double res = Accounting.simpleInterest(prin,rate,time);
        System.out.format("SI: %.2f\n",res);
    }
}
