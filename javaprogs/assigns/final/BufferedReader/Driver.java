import java.io.*;
class Driver
{
	public static void main(String args[]) throws Exception
	{
		InputStreamReader r1 = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(r1);
		String name;
		int age;
		System.out.print("Enter your name: ");
		name = br.readLine();
		System.out.print("\nEnter your age: ");
		age = Integer.parseInt(br.readLine());
		System.out.format("Name: %s\nAge:%d",name,age);

				
	}
}