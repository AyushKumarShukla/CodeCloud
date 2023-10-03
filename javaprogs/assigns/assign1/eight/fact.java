import java.util.Scanner;
class Driver
{
    static int fact(int input)
    {
        int res=1;
        if(input<1) // base case if input = 1 : return 1 : else continue recursion
            return 1; //return value for base case call
        else
            res=input*fact(input-1); // recursive formula implementation
        return res; //return value for non base case calls
    }

    public static void main(String args[])
    {
        System.out.println("TO FIND THE FACTORIAL OF A NUMBER");
        Scanner scan=new Scanner(System.in);
        System.out.print("Enter A Number: ");
        int input=scan.nextInt();
        int res=fact(input);
        System.out.println("FACTORIAL("+input+")"+" = "+res);
    }
}
