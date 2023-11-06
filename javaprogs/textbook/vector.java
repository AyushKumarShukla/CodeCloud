import java.util.Vector;
class Driver
{
    public static void main(String args[])
    {
        String arr[]=new String[10];
        Vector<String> list = new Vector<>();
        list.addElement("Ayush");
        list.addElement("Kumar");
        list.addElement("Shukla");
        list.insertElementAt("Student",0);
        //Length is dynamic, size adjusts to number of elements
        //size() method gives length
        for(int i=0;i<list.size();i++)
            System.out.println(list.elementAt(i));
        list.copyInto(arr);
        //Length is fixed, empty cells filled with null
        //length variable gives length
        for(int i=0;i<arr.length;i++)
            System.out.println(arr[i]);

    }
}

