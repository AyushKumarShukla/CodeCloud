//To use a abstract class, create it's subclasses and show 
runtime polymorphism from it
abstract class Base
{
	abstract void show();
}

class Base1 extends Base
{
	void show()
	{
		System.out.println("GoodWill");
	}
}

class Base2 extends Base
{
	void show()
	{
		System.out.println("Honesty");
	}
}

class Base3 extends Base
{
	void show()
	{
		System.out.println("Faith");
	}
}
class New
{
	public static void main(String args[])
	{
		Base one = new Base1();
		Base two = new Base2();
		Base three = new Base3();
		one.show();
		two.show();	
		three.show();			
	}
}