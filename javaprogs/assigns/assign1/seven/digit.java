class DigitOp
{
    static int product_of_digits(int input)
    {
        int temp=input;
        int prod=1;
        while(temp>0)
        {
            int digit=temp%10;
            temp=temp/10;
            prod*=digit;
        }
        return prod;
    }
    
    static int sum_of_digits(int input)
    {
        int temp=input;
        int sum=0;
        while(temp>0)
        {
            int digit=temp%10;
            temp=temp/10;
            sum+=digit;
        }
        return sum;
    }

    static int numrev(int input)
    {
        int temp=input;
        int digit;
        String rev="";
        while(temp>0)
        {
            digit=temp%10;
            temp=temp/10;
            rev=rev+digit;//string concat-digit gets typecasted into string
        }
        return Integer.parseInt(rev); //string to int
    }
}

class Driver
{
	public static void main(String args[])
    {
        int input=Integer.parseInt(args[0]);
        int res1=DigitOp.product_of_digits(input);
        int res2=DigitOp.sum_of_digits(input);
        int res3=DigitOp.numrev(input);
        System.out.println("(PROD,SUM,REV): "+res1+" "+res2+" "+res3);
    }
}
