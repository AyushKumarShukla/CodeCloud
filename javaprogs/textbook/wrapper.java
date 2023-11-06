import java.lang.*;
import java.util.Vector;
class Driver
{
    public static void main(String args[])
    {
        String arr[]=new String[10];
        Vector<String> list = new Vector<>();
        Integer intobj = 10; // autoboxing of primitive value into a Wrapper object
        System.out.println(intobj); // object itself
        System.out.println(intobj.intValue()); // Object to primitive
        System.out.println(Integer.toString(intobj)); // Wrapper Object to String
        System.out.println(Integer.valueOf("100")); //String to Wrapper object
        System.out.println(Integer.parseInt("100")); //String to primitive
    }
}

