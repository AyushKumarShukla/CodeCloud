
class SingleObj
{
	String val;
	private SingleObj()
	{
		System.out.println("Object A has been created");
		val = "A";
	}
	
	static SingleObj ref = new SingleObj();

	static SingleObj getInstance()
	{
		return ref;
	}
	String getVal()
	{
		return val;
	}
}

class Driver
{
	public static void main(String args[])
	{
		SingleObj obj1 = SingleObj.getInstance();
		SingleObj obj2 = SingleObj.getInstance();
		System.out.println("obj1: " + obj1.getVal());
		System.out.println("obj2: " + obj2.getVal());
	}
}