import java.lang.Exception;
/* Throwable --> Exception --> OurClass (Inheritance class) */
/*The exception class contains code for creating exception objects*/
/*Upon extending the Exception class, we can create our own exception messages*/

class NegativeNumber extends Exception
{
    NegativeNumber(String message)
    {
        super(message); //pass message to Exception class
    }
}

class TestExcept
{
    static int except1(int a,int b)
    {
        int res;
        try
        {
            res = a-b;
            if(res<0) // condition for exception hit
                throw new NegativeNumber("Negative Number Encountered"); //throw exception
        }
        catch(NegativeNumber n) //exception catch
        {
            //exception handling
            System.out.println("MESSAGE: "+n.getMessage()+",returning -1");
            res=-1;
        }
        return res;
    }
}

class Driver1
{
    public static void main(String args[])
    {
        int a=Integer.parseInt(args[0]),b=Integer.parseInt(args[1]);
        int res = TestExcept.except1(a,b);
        System.out.println("RESULT: "+res);
    }
}
