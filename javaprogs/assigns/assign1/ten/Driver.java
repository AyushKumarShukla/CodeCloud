class Series
{
    static int powerSeries(int terms,int x)
    {
        int sum=0;
        for(int i=0;i<terms;i++)
            sum+=Math.pow(x,i);
        return sum;
    }
}

class Driver
{
    public static void main(String args[])
    {
        int terms=Integer.parseInt(args[0]);
        if(terms<1)
            throw new IllegalArgumentException("Atleast 1 terms needed" );
        int x=Integer.parseInt(args[1]);
        int res = Series.powerSeries(terms,x);
        System.out.println(res);
    }
}
