class College
{
    int college_id = 5587;

    class Person
    {
        int personal_id = 1089;

        void printID()
        {
            System.out.format("PERSONAL ID: %d\nCOLLEGE ID: %d",personal_id,college_id);
        }
    }

    int getPersonId(College.Person obj)
    {
        return obj.personal_id;
    }
}
class Main
{
    public static void main(String args[])
    {   
        College c = new College();
        College.Person p = c.new Person();
        c.getPersonId(p);
    }
}
