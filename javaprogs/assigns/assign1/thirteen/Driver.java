import java.util.ArrayList;
import java.lang.Math;
class Num
{
    static boolean isPrime(int num)
    {
        for(int i=2;i<=Math.sqrt(num);i++)
        {
            if(num%i==0)
                return false;
        }
        return true;
    }
    //ArrayList<Datatype> has to be used
    static ArrayList<Integer> printPrimes(int start,int end)
    {
        ArrayList<Integer> primes = new ArrayList<>(); //list to hold primes
        for(int i=start;i<=end;i++)
            if(isPrime(i))
                primes.add(i); // adding primes one by one
        return primes; // returning the ArrayList
    }
}

class Driver
{
    public static void main(String args[])
    {
        ArrayList<Integer> primes; //to hold primes list
        int start = Integer.parseInt(args[0]);
        int end = Integer.parseInt(args[1]);
        primes = Num.printPrimes(start,end);
        for(int i=0;i<primes.size();i++)
            System.out.format("%d ",primes.get(i)); //retrieving elements one by one
        System.out.println();
    }
}
