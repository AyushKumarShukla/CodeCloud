class Error
{
    static int except1(int a,int b)
    {
        int out=-1;
        try //hits and throws exception object
        {
            out=a/b; //exception hit
        }
        catch(ArithmeticException e1) //catches and handles exception object
        {
            System.out.println("Division by zero error, please ensure b is not zero");
            System.out.println("Message in exception object: "+e1.getMessage());
        }
        finally //housekeeping operations such as closing files,connections etc
        {
            System.out.println("I am Immovable");
        }

        System.out.println("Printed after catch block");
        return out;
    }
}

class Driver
{
    public static void main(String args[])
    {
        int a=5,b=0;

        int res = Error.except1(a,b);
        System.out.println(res);
    }
}
