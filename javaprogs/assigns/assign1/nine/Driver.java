
class Fibo
{
    static int printNTerms(int terms)
    {
        int sum;
        if(terms==1)
            return 0;
        else if(terms==2)
            return 1;
        else
        {
            sum=printNTerms(terms-1)+printNTerms(terms-2);
            return sum;
        }
    }
}

class Driver
{
    public static void main(String args[])
    {
       int i;
       int terms = Integer.parseInt(args[0]);
        for(i=1;i<=terms;i++)
            System.out.print(Fibo.printNTerms(i)+", ");
        System.out.println();
    }
}
