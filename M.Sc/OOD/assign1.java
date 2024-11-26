package com.ten;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Scanner;

import javax.swing.JOptionPane;

class FactUtil
{
	private static FactUtil _reference = null;
	int value = 0;
	int result = 0;
	private FactUtil(int value)
	{
		this.value = value;
	}
	
	public static FactUtil factorial(int value)
	{
		int res = 1;
		if (_reference == null)
			_reference = new FactUtil(value);
		
		//factorial computation
		for(int i=2;i<=value;i++)
		{
			res = res * i;
		}
		
		_reference.result = res;
		return _reference;
			
	}
}

public class FactorialTest {
	public static void main(String args[])
	{
		int i=0,ch;
		Scanner sc = new Scanner(System.in);
		System.out.println("MENU:\n1.Input via GUI\n2.Input numbers from file 'nums'");
		System.out.println("Enter your choice: ");
		ch = sc.nextInt();
		FactUtil obj = null;
		
			switch(ch)
			{
				case 1:
					int number = Integer.parseInt(JOptionPane.showInputDialog("Enter a number: "));
					obj = FactUtil.factorial(number);
					JOptionPane.showMessageDialog(null,"factorial of " + number + " is = " + obj.result);
						break;
				case 2:
					Path path = Paths.get("/home/cloud/eclipse-workspace/temp10_1/src/com/ten/nums");
					try {
						List<String> lines = Files.readAllLines(path);
						for(String num : lines)
						{	
							int temp = Integer.parseInt(num);
							obj = FactUtil.factorial(temp);
							lines.set(i,num + " , " + obj.result );
							i += 1;
						}
						Files.write(path, lines);
					}
					catch (Exception e)
					{
						e.printStackTrace();
						System.out.println("exception generated");
					}
						break;
			}
	}
}