class first
{
	void show()
	{
		System.out.println("First");
	}
}

class second extends first
{
	void show()
	{
		System.out.println("Second");
	}
}

class third extends first
{
	void show()
	{
		System.out.println("Third");
	}
}

class fourth extends first
{
	void show()
	{
		System.out.println("Fourth");
	}
}

class five
{
	public static void main(String args[])
	{
		//parent class references holding derieved class objects. The method to be called is
resolved at runtime.
		first one = new first();
		first two = new second();
		first three = new third();
		first four = new fourth();

		one.show();
		two.show();
		three.show();
		four.show();
	}
}