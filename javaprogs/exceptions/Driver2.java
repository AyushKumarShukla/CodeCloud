class TestExcept
{
    /*This method does not have any exception handling of its own, thus it informs the caller method*/
    static int except1(int a,int b) throws ArithmeticException
    {
        int res;
        res = a/b;
        return res;
    }
}

class Driver2
{
    public static void main(String args[])
    {
        /*caller method handles the informed exception*/
        int a=Integer.parseInt(args[0]),b=Integer.parseInt(args[1]),res=-1;
        try
        {
            res = TestExcept.except1(a,b);
        }
        catch(ArithmeticException e1)
        {
            System.out.println("Called method generated exception: "+e1.getMessage());
        }
        System.out.println("RESULT: "+res);
    }
}
