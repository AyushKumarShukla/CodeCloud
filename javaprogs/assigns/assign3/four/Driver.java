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
        String res = "Name: " + name + "," + "id: "+ id;
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
    Scientist(int no,double exp)
    {
        this.no_of_publication=no;
        this.experience=exp;
    }
    public String toString()
    {
        String res = "No. Of Publications: " + no_of_publication + "," + "experience: "+ experience;
        return res;
    }
}

class DScientist extends Scientist
{
    int award;
    DScientist(int award)
    {
        this.award=award;
    }
    public String toString()
    {
        String res = "Award: " +award;
        return res;
    }
}

class Driver
{
    public static void main(String args[])
    {
       Employee emp = new Employee("Ayush",1089); 
       Scientist sci = new Scientist(15,4.5); 
       DScientist dsci = new DScientist(4);
       System.out.println(emp.toString());
       System.out.println(sci.toString());
       System.out.println(dsci.toString());
    }
}
