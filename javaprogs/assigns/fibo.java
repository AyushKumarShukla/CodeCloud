import java.util.Scanner;

public class fibo
{
	static int fibo(int terms)
	{
		int first=0,second=1;
		if(terms<=1)
			return terms;
		else
		{
			return(fibo(terms-1)+fibo(terms-1));
		}
	}
	public static void main(String args[])
	{
		
		int terms=3;
		int res=fibo(terms);
		System.out.printf("Fibo(%d)=%d\n",terms,res);
	}
}
