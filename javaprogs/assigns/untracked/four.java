class Employee
{
	String name;
	int id;
	Employee(String a, int b)
	{
		this.name = a;
		this.id = b;
	}
	public void toString1()
	{
		System.out.format("Name: %s , id: %d\n",name,id);
	}
}

class Scientist extends Employee
{
	int no_of_publication;
	int experience;
	Scientist(String a, int b,int c,int d)
	{
		super(a,b);
		this.no_of_publication = c;
		this.experience = d;
	}
	public void toString1()
	{
		super.toString1();
		System.out.format("Number Of Publish.: %d , experience: %d years\n",no_of_publication,experience);
	}
}

class Dscientist extends Scientist
{
	int award;
	Dscientist(String a, int b,int c,int d,int e)
	{
		super(a,b,c,d);
		this.award = e;	
	}
	public void toString1()
	{
		super.toString1();
		System.out.format("Awards: %d\n",award);
	}
}

class four
{
	public static void main(String args[])
	{	
		Dscientist me = new Dscientist("Ayush",1089,10,5,22);	
		me.toString1();
	}
}