class Employee
{
    String name;
    int id;
    Employee()
    {
    }
    Employee(String name,int id)
    {
        this.name=name;
        this.id=id;
    }
    public String toString()
    {
        String res = "Name: " + name + ", " + "id: "+ id;
        return res;
    }
}

class Scientist extends Employee
{
    int no_of_publication;
    double experience;
    Scientist()
    {
    }
    Scientist(String name,int id,int no,double exp)
    {
        super(name,id);
        this.no_of_publication=no;
        this.experience=exp;
    }
    public String toString()
    {
        String res = super.toString() + ", No. Of Publications: " + no_of_publication + "," + " experience: "+ experience + " years";
        return res;
    }
}
 
class DScientist extends Scientist
{
    int award;
    DScientist(String name,int id,int no,double exp,int award)
    {
        super(name,id,no,exp);
        this.award=award;
    }
    public String toString()
    {
        String res = super.toString() + ", awards: " + award;
        return res;
    }
}

class Driver
{
    public static void main(String args[])
    {
       Employee emp = new Employee("Ayush",1089); 
       Employee sci = new Scientist("Nitin",1123,43,8.9); 
       Employee dsci = new DScientist("Mahesh",9987,72,12.5,7);
       System.out.println("Employee Object:");
       System.out.println(emp.toString());
       System.out.println("\nScientist Object:");
       System.out.println(sci.toString());
       System.out.println("\nDScientist Object:");
       System.out.println(dsci.toString());
    }
}
