
class Parent
{
    int id;
    String name;
    String address;

    Parent(int a,String b, String c)
    {
        id=a;
        name=b;
        address=c;
    }

    void disp()
    {
        System.out.format("ID: %d\nNAME: %s\nADDRESS: %s\n",id,name,address);
    }
}

class ChildOne extends Parent
{
    double marks;

    ChildOne(double a,int b, String c, String d)
    {
        super(b,c,d);
        marks=a;
    }

    void disp()
    {
        System.out.println("PARENT INFO: ");
        super.disp();
        System.out.println("CHILD INFO:");
        System.out.format("MARKS: %.2f %%",marks);
    }
}

class ChildTwo extends Parent
{
    String quali;
    double salary;

    ChildTwo(String a, double b, int c, String d, String e)
    {
        super(c,d,e);
        quali=a;
        salary=b;
    }
    
    void disp()
    {
        System.out.println("PARENT INFO: ");
        super.disp();
        System.out.println("CHILD INFO:");
        System.out.format("QUALIFICATION: %s\nSALARY: %.2f L.P.A",quali,salary);
    }
}

class Main
{
    public static void main(String args[])
    {
        ChildOne first = new ChildOne(89.65,15478,"RAM KUMAR JOSHI","Kolkata, West Bengal");
        ChildTwo second = new ChildTwo("DOCTORATE",11.5,78192,"RAKESH VERMA","Varanasi, Uttar Pradesh");
        System.out.println("ChildOne Object: ");
        first.disp();
        System.out.println("\n\nChildTwo Object: ");
        second.disp();
        System.out.println();
    }
}







