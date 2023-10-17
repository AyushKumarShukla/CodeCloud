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
       /*   All references are of class Employee which is the base class for the multiple inheritance path: 
            Employee --> Scientist --> DScientist
            Thus, the reference of Employee can hold objects of all it's derieved classes with two restrictions:
            1. The base class reference can access only those data and methods that the object inherited from it.
            2. The resolution of which method needs to be called is pushed to run time, when line of code is 
            actually executed. The compiler is unable to resolve the clear method which will be called just by
            parsing the statement.
       */
       Employee emp = new Employee("Ayush",1089); 
       Employee sci = new Scientist(15,4.5); 
       Employee dsci = new DScientist(4);
       System.out.println(emp.toString());
       System.out.println(sci.toString());
       System.out.println(dsci.toString());
    }
}
