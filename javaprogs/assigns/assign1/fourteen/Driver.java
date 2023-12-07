
import java.util.ArrayList;
import java.lang.Math;
class Num
{
    static boolean isArmstrong(int num)
    {
        for(int i=2;i<=Math.sqrt(num);i++)
        {
            if(num%i==0)
                return false;
        }
        return true;
    }
    //ArrayList<Datatype> has to be used
    static ArrayList<Integer> printArmstrong(int start,int end)
    {
        ArrayList<Integer> arms = new ArrayList<>(); //list to hold primes
        for(int i=start;i<=end;i++)
            if(isArmstrong(i))
                arms.add(i); // adding primes one by one
        return arms; // returning the ArrayList
    }
}

class Driver
{
    public static void main(String args[])
    {
        ArrayList<Integer> arms; //to hold primes list
        int start = Integer.parseInt(args[0]);
        int end = Integer.parseInt(args[1]);
        arms = Num.printArmstrong(start,end);
        for(int i=0;i<arms.size();i++)
            System.out.format("%d ",arms.get(i)); //retrieving elements one by one
        System.out.println();
    }
}
